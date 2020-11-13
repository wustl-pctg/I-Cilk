; RUN: opt %loadPolly -polly-detect -analyze < %s \
; RUN:     | FileCheck %s
;
; Two-layer loop of the form:
;
; cilk_for(...) {
;     cilk_for(...) {
;         B[i + j] = A[i + j] * 2;
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

pfor.cond.cleanup:                                ; preds = %pfor.inc20
  sync within %syncreg, label %pfor.end.continue

pfor.end.continue:                                ; preds = %pfor.cond.cleanup
  %arrayidx23 = getelementptr inbounds [512 x i32], [512 x i32]* %B, i64 0, i64 1
  %2 = load i32, i32* %arrayidx23, align 4, !tbaa !2
  %call = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i32 %2)
  call void @llvm.lifetime.end.p0i8(i64 2048, i8* nonnull %1) #3
  call void @llvm.lifetime.end.p0i8(i64 2048, i8* nonnull %0) #3
  ret i32 0

pfor.detach:                                      ; preds = %pfor.inc20, %entry.split
  %indvars.iv42 = phi i64 [ 0, %entry.split ], [ %indvars.iv.next43, %pfor.inc20 ]
  detach within %syncreg, label %pfor.body, label %pfor.inc20

pfor.body:                                        ; preds = %pfor.detach
  %syncreg1 = tail call token @llvm.syncregion.start()
  br label %vector.body

vector.body:                                      ; preds = %vec.inc, %pfor.body
  %index = phi i64 [ %index.next, %vec.inc ], [ 0, %pfor.body ]
  %index.next = add nuw nsw i64 %index, 8
  %3 = icmp eq i64 %index.next, 512
  detach within %syncreg1, label %vec.detached, label %vec.inc

vec.detached:                                     ; preds = %vector.body
  %4 = add nuw nsw i64 %index, %indvars.iv42
  %5 = getelementptr inbounds [512 x i32], [512 x i32]* %A, i64 0, i64 %4
  %6 = bitcast i32* %5 to <4 x i32>*
  %wide.load = load <4 x i32>, <4 x i32>* %6, align 4, !tbaa !2
  %7 = getelementptr i32, i32* %5, i64 4
  %8 = bitcast i32* %7 to <4 x i32>*
  %wide.load46 = load <4 x i32>, <4 x i32>* %8, align 4, !tbaa !2
  %9 = shl nsw <4 x i32> %wide.load, <i32 1, i32 1, i32 1, i32 1>
  %10 = shl nsw <4 x i32> %wide.load46, <i32 1, i32 1, i32 1, i32 1>
  %11 = getelementptr inbounds [512 x i32], [512 x i32]* %B, i64 0, i64 %4
  %12 = bitcast i32* %11 to <4 x i32>*
  store <4 x i32> %9, <4 x i32>* %12, align 4, !tbaa !2
  %13 = getelementptr i32, i32* %11, i64 4
  %14 = bitcast i32* %13 to <4 x i32>*
  store <4 x i32> %10, <4 x i32>* %14, align 4, !tbaa !2
  reattach within %syncreg1, label %vec.inc

vec.inc:                                          ; preds = %vec.detached, %vector.body
  br i1 %3, label %pfor.cond.cleanup7, label %vector.body, !llvm.loop !6

pfor.cond.cleanup7:                               ; preds = %vec.inc
  sync within %syncreg1, label %pfor.end.continue8

pfor.end.continue8:                               ; preds = %pfor.cond.cleanup7
  reattach within %syncreg, label %pfor.inc20

pfor.inc20:                                       ; preds = %pfor.end.continue8, %pfor.detach
  %indvars.iv.next43 = add nuw nsw i64 %indvars.iv42, 1
  %exitcond44 = icmp eq i64 %indvars.iv.next43, 512
  br i1 %exitcond44, label %pfor.cond.cleanup, label %pfor.detach, !llvm.loop !10
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
!6 = distinct !{!6, !7, !8, !9}
!7 = !{!"tapir.loop.spawn.strategy", i32 1}
!8 = !{!"llvm.loop.vectorize.width", i32 1}
!9 = !{!"llvm.loop.interleave.count", i32 1}
!10 = distinct !{!10, !7}
