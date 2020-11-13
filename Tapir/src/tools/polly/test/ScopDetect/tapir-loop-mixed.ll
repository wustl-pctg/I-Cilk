; RUN: opt %loadPolly -polly-detect -analyze < %s \
; RUN:     | FileCheck %s
;
; Four-layer loop mixing regular loops and tapir loops of the form:
;
; cilk_for(...) {
;     for(...) {
;         cilk_for(...) {
;             for(...) {
;                 B[i + j + k + l] = A[i + j + k + l] * 2;
;             }
;         }
;     }
; }
;
; CHECK: Valid Region for Scop: pfor.detach => pfor.end.continue

; ModuleID = 'test.ll'
source_filename = "test.c"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1

; Function Attrs: nounwind uwtable
define i32 @main() local_unnamed_addr #0 {
entry:
  %A = alloca [512 x i32], align 16
  %B = alloca [512 x i32], align 16
  br label %entry.split

entry.split:                                      ; preds = %entry
  %syncreg = tail call token @llvm.syncregion.start()
  %0 = bitcast [512 x i32]* %A to i8*
  call void @llvm.lifetime.start.p0i8(i64 2048, i8* nonnull %0) #3
  %1 = bitcast [512 x i32]* %B to i8*
  call void @llvm.lifetime.start.p0i8(i64 2048, i8* nonnull %1) #3
  br label %pfor.detach

pfor.cond.cleanup:                                ; preds = %pfor.inc35
  sync within %syncreg, label %pfor.end.continue

pfor.end.continue:                                ; preds = %pfor.cond.cleanup
  %arrayidx38 = getelementptr inbounds [512 x i32], [512 x i32]* %B, i64 0, i64 1
  %2 = load i32, i32* %arrayidx38, align 4, !tbaa !2
  %call = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i32 %2)
  call void @llvm.lifetime.end.p0i8(i64 2048, i8* nonnull %1) #3
  call void @llvm.lifetime.end.p0i8(i64 2048, i8* nonnull %0) #3
  ret i32 0

pfor.detach:                                      ; preds = %pfor.inc35, %entry.split
  %indvars.iv77 = phi i64 [ 0, %entry.split ], [ %indvars.iv.next78, %pfor.inc35 ]
  detach within %syncreg, label %pfor.body, label %pfor.inc35

pfor.body:                                        ; preds = %pfor.detach
  %syncreg2 = tail call token @llvm.syncregion.start()
  br label %for.body

for.cond.cleanup:                                 ; preds = %pfor.end.continue9
  reattach within %syncreg, label %pfor.inc35

for.body:                                         ; preds = %pfor.end.continue9, %pfor.body
  %indvars.iv73 = phi i64 [ 0, %pfor.body ], [ %indvars.iv.next74, %pfor.end.continue9 ]
  %3 = add nuw nsw i64 %indvars.iv73, %indvars.iv77
  br label %pfor.detach10

pfor.cond.cleanup8:                               ; preds = %pfor.inc
  sync within %syncreg2, label %pfor.end.continue9

pfor.end.continue9:                               ; preds = %pfor.cond.cleanup8
  %indvars.iv.next74 = add nuw nsw i64 %indvars.iv73, 1
  %exitcond76 = icmp eq i64 %indvars.iv.next74, 512
  br i1 %exitcond76, label %for.cond.cleanup, label %for.body

pfor.detach10:                                    ; preds = %pfor.inc, %for.body
  %indvars.iv68 = phi i64 [ 0, %for.body ], [ %indvars.iv.next69, %pfor.inc ]
  detach within %syncreg2, label %pfor.body14, label %pfor.inc

pfor.body14:                                      ; preds = %pfor.detach10
  %4 = add nuw nsw i64 %3, %indvars.iv68
  %5 = add nuw nsw i64 %indvars.iv68, %indvars.iv77
  %arrayidx25 = getelementptr inbounds [512 x i32], [512 x i32]* %A, i64 0, i64 %5
  %arrayidx29 = getelementptr inbounds [512 x i32], [512 x i32]* %B, i64 0, i64 %5
  br label %for.body18

for.cond.cleanup17:                               ; preds = %for.inc.1
  reattach within %syncreg2, label %pfor.inc

for.body18:                                       ; preds = %for.inc.1, %pfor.body14
  %indvars.iv = phi i64 [ 0, %pfor.body14 ], [ %indvars.iv.next.1, %for.inc.1 ]
  %6 = add nuw nsw i64 %indvars.iv, %4
  %arrayidx = getelementptr inbounds [512 x i32], [512 x i32]* %A, i64 0, i64 %6
  %7 = load i32, i32* %arrayidx, align 4, !tbaa !2
  %rem61 = and i32 %7, 3
  %cmp22 = icmp eq i32 %rem61, 0
  br i1 %cmp22, label %if.then, label %for.inc

if.then:                                          ; preds = %for.body18
  %8 = load i32, i32* %arrayidx25, align 4, !tbaa !2
  %mul26 = shl nsw i32 %8, 1
  store i32 %mul26, i32* %arrayidx29, align 4, !tbaa !2
  br label %for.inc

for.inc:                                          ; preds = %if.then, %for.body18
  %indvars.iv.next = or i64 %indvars.iv, 1
  %9 = add nuw nsw i64 %indvars.iv.next, %4
  %arrayidx.1 = getelementptr inbounds [512 x i32], [512 x i32]* %A, i64 0, i64 %9
  %10 = load i32, i32* %arrayidx.1, align 4, !tbaa !2
  %rem61.1 = and i32 %10, 3
  %cmp22.1 = icmp eq i32 %rem61.1, 0
  br i1 %cmp22.1, label %if.then.1, label %for.inc.1

pfor.inc:                                         ; preds = %for.cond.cleanup17, %pfor.detach10
  %indvars.iv.next69 = add nuw nsw i64 %indvars.iv68, 1
  %exitcond72 = icmp eq i64 %indvars.iv.next69, 512
  br i1 %exitcond72, label %pfor.cond.cleanup8, label %pfor.detach10, !llvm.loop !6

pfor.inc35:                                       ; preds = %for.cond.cleanup, %pfor.detach
  %indvars.iv.next78 = add nuw nsw i64 %indvars.iv77, 1
  %exitcond79 = icmp eq i64 %indvars.iv.next78, 512
  br i1 %exitcond79, label %pfor.cond.cleanup, label %pfor.detach, !llvm.loop !8

if.then.1:                                        ; preds = %for.inc
  %11 = load i32, i32* %arrayidx25, align 4, !tbaa !2
  %mul26.1 = shl nsw i32 %11, 1
  store i32 %mul26.1, i32* %arrayidx29, align 4, !tbaa !2
  br label %for.inc.1

for.inc.1:                                        ; preds = %if.then.1, %for.inc
  %indvars.iv.next.1 = add nuw nsw i64 %indvars.iv, 2
  %exitcond.1 = icmp eq i64 %indvars.iv.next.1, 512
  br i1 %exitcond.1, label %for.cond.cleanup17, label %for.body18
}

; Function Attrs: argmemonly nounwind
declare void @llvm.lifetime.start.p0i8(i64, i8* nocapture) #1

; Function Attrs: argmemonly nounwind
declare token @llvm.syncregion.start() #1

; Function Attrs: argmemonly nounwind
declare void @llvm.lifetime.end.p0i8(i64, i8* nocapture) #1

; Function Attrs: nounwind
declare i32 @printf(i8* nocapture readonly, ...) local_unnamed_addr #2

attributes #0 = { nounwind uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { argmemonly nounwind }
attributes #2 = { nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 5.0.0 (https://github.com/wsmoses/Cilk-Clang.git 2637f015d66418964aa0225534c004dd71a174b8) (git@github.com:wsmoses/Parallel-IR.git 1f09ac94609f7bd432bd139897056ef96f339812)"}
!2 = !{!3, !3, i64 0}
!3 = !{!"int", !4, i64 0}
!4 = !{!"omnipotent char", !5, i64 0}
!5 = !{!"Simple C/C++ TBAA"}
!6 = distinct !{!6, !7}
!7 = !{!"tapir.loop.spawn.strategy", i32 1}
!8 = distinct !{!8, !7}
