/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Global Instruction Selector for the X86 target                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_GLOBALISEL_PREDICATE_BITSET
const unsigned MAX_SUBTARGET_PREDICATES = 88;
using PredicateBitset = llvm::PredicateBitsetImpl<MAX_SUBTARGET_PREDICATES>;
#endif // ifdef GET_GLOBALISEL_PREDICATE_BITSET

#ifdef GET_GLOBALISEL_TEMPORARIES_DECL
  mutable MatcherState State;
  typedef ComplexRendererFn(X86InstructionSelector::*ComplexMatcherMemFn)(MachineOperand &) const;
const MatcherInfoTy<PredicateBitset, ComplexMatcherMemFn> MatcherInfo;
#endif // ifdef GET_GLOBALISEL_TEMPORARIES_DECL

#ifdef GET_GLOBALISEL_TEMPORARIES_INIT
, State(0),
MatcherInfo({TypeObjects, FeatureBitsets, {
  nullptr, // GICP_Invalid
}})
#endif // ifdef GET_GLOBALISEL_TEMPORARIES_INIT

#ifdef GET_GLOBALISEL_IMPL
// Bits for subtarget features that participate in instruction matching.
enum SubtargetFeatureBits : uint8_t {
  Feature_TruePredicateBit = 38,
  Feature_HasCMovBit = 15,
  Feature_NoCMovBit = 75,
  Feature_HasMMXBit = 61,
  Feature_Has3DNowBit = 63,
  Feature_HasSSE1Bit = 26,
  Feature_UseSSE1Bit = 32,
  Feature_HasSSE2Bit = 27,
  Feature_UseSSE2Bit = 33,
  Feature_HasSSE3Bit = 19,
  Feature_UseSSE3Bit = 41,
  Feature_HasSSSE3Bit = 62,
  Feature_UseSSSE3Bit = 42,
  Feature_NoSSE41Bit = 78,
  Feature_UseSSE41Bit = 39,
  Feature_HasSSE42Bit = 46,
  Feature_UseSSE42Bit = 45,
  Feature_HasSSE4ABit = 50,
  Feature_HasAVXBit = 34,
  Feature_HasAVX2Bit = 30,
  Feature_HasAVX1OnlyBit = 28,
  Feature_HasAVX512Bit = 52,
  Feature_UseAVXBit = 31,
  Feature_NoAVX512Bit = 23,
  Feature_HasCDIBit = 56,
  Feature_HasVPOPCNTDQBit = 60,
  Feature_HasERIBit = 59,
  Feature_HasDQIBit = 54,
  Feature_NoDQIBit = 43,
  Feature_HasBWIBit = 55,
  Feature_NoBWIBit = 40,
  Feature_HasVLXBit = 53,
  Feature_NoVLXBit = 22,
  Feature_NoVLX_Or_NoBWIBit = 37,
  Feature_NoVLX_Or_NoDQIBit = 80,
  Feature_HasPOPCNTBit = 44,
  Feature_HasAESBit = 48,
  Feature_HasFXSRBit = 20,
  Feature_HasXSAVEBit = 66,
  Feature_HasXSAVEOPTBit = 67,
  Feature_HasXSAVECBit = 68,
  Feature_HasXSAVESBit = 69,
  Feature_HasPCLMULBit = 49,
  Feature_HasFMABit = 21,
  Feature_HasFMA4Bit = 24,
  Feature_HasXOPBit = 25,
  Feature_HasTBMBit = 9,
  Feature_HasLWPBit = 10,
  Feature_HasMOVBEBit = 3,
  Feature_HasRDRANDBit = 4,
  Feature_HasF16CBit = 51,
  Feature_NoF16CBit = 81,
  Feature_HasFSGSBaseBit = 70,
  Feature_HasLZCNTBit = 6,
  Feature_HasBMIBit = 7,
  Feature_HasBMI2Bit = 8,
  Feature_HasVBMIBit = 57,
  Feature_HasIFMABit = 58,
  Feature_HasRTMBit = 65,
  Feature_HasADXBit = 14,
  Feature_HasSHABit = 47,
  Feature_HasRDSEEDBit = 5,
  Feature_HasPrefetchWBit = 64,
  Feature_HasLAHFSAHFBit = 2,
  Feature_HasMWAITXBit = 11,
  Feature_HasCLZEROBit = 12,
  Feature_FPStackf32Bit = 17,
  Feature_FPStackf64Bit = 18,
  Feature_HasCLFLUSHOPTBit = 13,
  Feature_HasCmpxchg16bBit = 76,
  Feature_Not64BitModeBit = 0,
  Feature_In64BitModeBit = 1,
  Feature_IsLP64Bit = 72,
  Feature_NotLP64Bit = 71,
  Feature_NotWin64WithoutFPBit = 74,
  Feature_IsPS4Bit = 83,
  Feature_NotPS4Bit = 82,
  Feature_KernelCodeBit = 84,
  Feature_NearDataBit = 85,
  Feature_IsNotPICBit = 86,
  Feature_OptForSizeBit = 35,
  Feature_OptForMinSizeBit = 29,
  Feature_OptForSpeedBit = 79,
  Feature_CallImmAddrBit = 87,
  Feature_FavorMemIndirectCallBit = 16,
  Feature_NotSlowIncDecBit = 73,
  Feature_HasFastSHLDRotateBit = 77,
  Feature_HasMFenceBit = 36,
};

PredicateBitset X86InstructionSelector::
computeAvailableModuleFeatures(const X86Subtarget *Subtarget) const {
  PredicateBitset Features;
  if (true)
    Features[Feature_TruePredicateBit] = 1;
  if (Subtarget->hasCMov())
    Features[Feature_HasCMovBit] = 1;
  if (!Subtarget->hasCMov())
    Features[Feature_NoCMovBit] = 1;
  if (Subtarget->hasMMX())
    Features[Feature_HasMMXBit] = 1;
  if (Subtarget->has3DNow())
    Features[Feature_Has3DNowBit] = 1;
  if (Subtarget->hasSSE1())
    Features[Feature_HasSSE1Bit] = 1;
  if (Subtarget->hasSSE1() && !Subtarget->hasAVX())
    Features[Feature_UseSSE1Bit] = 1;
  if (Subtarget->hasSSE2())
    Features[Feature_HasSSE2Bit] = 1;
  if (Subtarget->hasSSE2() && !Subtarget->hasAVX())
    Features[Feature_UseSSE2Bit] = 1;
  if (Subtarget->hasSSE3())
    Features[Feature_HasSSE3Bit] = 1;
  if (Subtarget->hasSSE3() && !Subtarget->hasAVX())
    Features[Feature_UseSSE3Bit] = 1;
  if (Subtarget->hasSSSE3())
    Features[Feature_HasSSSE3Bit] = 1;
  if (Subtarget->hasSSSE3() && !Subtarget->hasAVX())
    Features[Feature_UseSSSE3Bit] = 1;
  if (!Subtarget->hasSSE41())
    Features[Feature_NoSSE41Bit] = 1;
  if (Subtarget->hasSSE41() && !Subtarget->hasAVX())
    Features[Feature_UseSSE41Bit] = 1;
  if (Subtarget->hasSSE42())
    Features[Feature_HasSSE42Bit] = 1;
  if (Subtarget->hasSSE42() && !Subtarget->hasAVX())
    Features[Feature_UseSSE42Bit] = 1;
  if (Subtarget->hasSSE4A())
    Features[Feature_HasSSE4ABit] = 1;
  if (Subtarget->hasAVX())
    Features[Feature_HasAVXBit] = 1;
  if (Subtarget->hasAVX2())
    Features[Feature_HasAVX2Bit] = 1;
  if (Subtarget->hasAVX() && !Subtarget->hasAVX2())
    Features[Feature_HasAVX1OnlyBit] = 1;
  if (Subtarget->hasAVX512())
    Features[Feature_HasAVX512Bit] = 1;
  if (Subtarget->hasAVX() && !Subtarget->hasAVX512())
    Features[Feature_UseAVXBit] = 1;
  if (!Subtarget->hasAVX512())
    Features[Feature_NoAVX512Bit] = 1;
  if (Subtarget->hasCDI())
    Features[Feature_HasCDIBit] = 1;
  if (Subtarget->hasVPOPCNTDQ())
    Features[Feature_HasVPOPCNTDQBit] = 1;
  if (Subtarget->hasERI())
    Features[Feature_HasERIBit] = 1;
  if (Subtarget->hasDQI())
    Features[Feature_HasDQIBit] = 1;
  if (!Subtarget->hasDQI())
    Features[Feature_NoDQIBit] = 1;
  if (Subtarget->hasBWI())
    Features[Feature_HasBWIBit] = 1;
  if (!Subtarget->hasBWI())
    Features[Feature_NoBWIBit] = 1;
  if (Subtarget->hasVLX())
    Features[Feature_HasVLXBit] = 1;
  if (!Subtarget->hasVLX())
    Features[Feature_NoVLXBit] = 1;
  if (!Subtarget->hasVLX() || !Subtarget->hasBWI())
    Features[Feature_NoVLX_Or_NoBWIBit] = 1;
  if (!Subtarget->hasVLX() || !Subtarget->hasDQI())
    Features[Feature_NoVLX_Or_NoDQIBit] = 1;
  if (Subtarget->hasPOPCNT())
    Features[Feature_HasPOPCNTBit] = 1;
  if (Subtarget->hasAES())
    Features[Feature_HasAESBit] = 1;
  if (Subtarget->hasFXSR())
    Features[Feature_HasFXSRBit] = 1;
  if (Subtarget->hasXSAVE())
    Features[Feature_HasXSAVEBit] = 1;
  if (Subtarget->hasXSAVEOPT())
    Features[Feature_HasXSAVEOPTBit] = 1;
  if (Subtarget->hasXSAVEC())
    Features[Feature_HasXSAVECBit] = 1;
  if (Subtarget->hasXSAVES())
    Features[Feature_HasXSAVESBit] = 1;
  if (Subtarget->hasPCLMUL())
    Features[Feature_HasPCLMULBit] = 1;
  if (Subtarget->hasFMA())
    Features[Feature_HasFMABit] = 1;
  if (Subtarget->hasFMA4())
    Features[Feature_HasFMA4Bit] = 1;
  if (Subtarget->hasXOP())
    Features[Feature_HasXOPBit] = 1;
  if (Subtarget->hasTBM())
    Features[Feature_HasTBMBit] = 1;
  if (Subtarget->hasLWP())
    Features[Feature_HasLWPBit] = 1;
  if (Subtarget->hasMOVBE())
    Features[Feature_HasMOVBEBit] = 1;
  if (Subtarget->hasRDRAND())
    Features[Feature_HasRDRANDBit] = 1;
  if (Subtarget->hasF16C())
    Features[Feature_HasF16CBit] = 1;
  if (!Subtarget->hasF16C())
    Features[Feature_NoF16CBit] = 1;
  if (Subtarget->hasFSGSBase())
    Features[Feature_HasFSGSBaseBit] = 1;
  if (Subtarget->hasLZCNT())
    Features[Feature_HasLZCNTBit] = 1;
  if (Subtarget->hasBMI())
    Features[Feature_HasBMIBit] = 1;
  if (Subtarget->hasBMI2())
    Features[Feature_HasBMI2Bit] = 1;
  if (Subtarget->hasVBMI())
    Features[Feature_HasVBMIBit] = 1;
  if (Subtarget->hasIFMA())
    Features[Feature_HasIFMABit] = 1;
  if (Subtarget->hasRTM())
    Features[Feature_HasRTMBit] = 1;
  if (Subtarget->hasADX())
    Features[Feature_HasADXBit] = 1;
  if (Subtarget->hasSHA())
    Features[Feature_HasSHABit] = 1;
  if (Subtarget->hasRDSEED())
    Features[Feature_HasRDSEEDBit] = 1;
  if (Subtarget->hasPRFCHW())
    Features[Feature_HasPrefetchWBit] = 1;
  if (Subtarget->hasLAHFSAHF())
    Features[Feature_HasLAHFSAHFBit] = 1;
  if (Subtarget->hasMWAITX())
    Features[Feature_HasMWAITXBit] = 1;
  if (Subtarget->hasCLZERO())
    Features[Feature_HasCLZEROBit] = 1;
  if (!Subtarget->hasSSE1())
    Features[Feature_FPStackf32Bit] = 1;
  if (!Subtarget->hasSSE2())
    Features[Feature_FPStackf64Bit] = 1;
  if (Subtarget->hasCLFLUSHOPT())
    Features[Feature_HasCLFLUSHOPTBit] = 1;
  if (Subtarget->hasCmpxchg16b())
    Features[Feature_HasCmpxchg16bBit] = 1;
  if (!Subtarget->is64Bit())
    Features[Feature_Not64BitModeBit] = 1;
  if (Subtarget->is64Bit())
    Features[Feature_In64BitModeBit] = 1;
  if (Subtarget->isTarget64BitLP64())
    Features[Feature_IsLP64Bit] = 1;
  if (!Subtarget->isTarget64BitLP64())
    Features[Feature_NotLP64Bit] = 1;
  if (Subtarget->isTargetPS4())
    Features[Feature_IsPS4Bit] = 1;
  if (!Subtarget->isTargetPS4())
    Features[Feature_NotPS4Bit] = 1;
  if (TM.getCodeModel() == CodeModel::Kernel)
    Features[Feature_KernelCodeBit] = 1;
  if (TM.getCodeModel() == CodeModel::Small ||TM.getCodeModel() == CodeModel::Kernel)
    Features[Feature_NearDataBit] = 1;
  if (!TM.isPositionIndependent())
    Features[Feature_IsNotPICBit] = 1;
  if (Subtarget->isLegalToCallImmediateAddr())
    Features[Feature_CallImmAddrBit] = 1;
  if (!Subtarget->callRegIndirect())
    Features[Feature_FavorMemIndirectCallBit] = 1;
  if (!Subtarget->slowIncDec())
    Features[Feature_NotSlowIncDecBit] = 1;
  if (Subtarget->hasFastSHLDRotate())
    Features[Feature_HasFastSHLDRotateBit] = 1;
  if (Subtarget->hasMFence())
    Features[Feature_HasMFenceBit] = 1;
  return Features;
}

PredicateBitset X86InstructionSelector::
computeAvailableFunctionFeatures(const X86Subtarget *Subtarget, const MachineFunction *MF) const {
  PredicateBitset Features;
  if (!Subtarget->isTargetWin64() ||Subtarget->getFrameLowering()->hasFP(*MF))
    Features[Feature_NotWin64WithoutFPBit] = 1;
  if (MF->getFunction()->optForSize())
    Features[Feature_OptForSizeBit] = 1;
  if (MF->getFunction()->optForMinSize())
    Features[Feature_OptForMinSizeBit] = 1;
  if (!MF->getFunction()->optForSize())
    Features[Feature_OptForSpeedBit] = 1;
  return Features;
}

enum {
  GILLT_v2s32,
  GILLT_v2s64,
  GILLT_v4s16,
  GILLT_v4s32,
  GILLT_v4s64,
  GILLT_v8s1,
  GILLT_v8s8,
  GILLT_v8s16,
  GILLT_v8s32,
  GILLT_v8s64,
  GILLT_v16s1,
  GILLT_v16s8,
  GILLT_v16s16,
  GILLT_v16s32,
  GILLT_v32s1,
  GILLT_v32s8,
  GILLT_v32s16,
  GILLT_v64s1,
  GILLT_v64s8,
  GILLT_s8,
  GILLT_s16,
  GILLT_s32,
  GILLT_s64,
  GILLT_s80,
};
const static LLT TypeObjects[] = {
  LLT::vector(2, 32),
  LLT::vector(2, 64),
  LLT::vector(4, 16),
  LLT::vector(4, 32),
  LLT::vector(4, 64),
  LLT::vector(8, 1),
  LLT::vector(8, 8),
  LLT::vector(8, 16),
  LLT::vector(8, 32),
  LLT::vector(8, 64),
  LLT::vector(16, 1),
  LLT::vector(16, 8),
  LLT::vector(16, 16),
  LLT::vector(16, 32),
  LLT::vector(32, 1),
  LLT::vector(32, 8),
  LLT::vector(32, 16),
  LLT::vector(64, 1),
  LLT::vector(64, 8),
  LLT::scalar(8),
  LLT::scalar(16),
  LLT::scalar(32),
  LLT::scalar(64),
  LLT::scalar(80),
};

enum {
  GIFBS_Invalid,
  GIFBS_FPStackf32,
  GIFBS_FPStackf64,
  GIFBS_HasAES,
  GIFBS_HasAVX,
  GIFBS_HasAVX1Only,
  GIFBS_HasAVX2,
  GIFBS_HasAVX512,
  GIFBS_HasBMI,
  GIFBS_HasBMI2,
  GIFBS_HasBWI,
  GIFBS_HasDQI,
  GIFBS_HasF16C,
  GIFBS_HasFMA4,
  GIFBS_HasSHA,
  GIFBS_HasSSE42,
  GIFBS_HasSSE4A,
  GIFBS_HasTBM,
  GIFBS_HasVLX,
  GIFBS_HasXOP,
  GIFBS_In64BitMode,
  GIFBS_NotSlowIncDec,
  GIFBS_UseAVX,
  GIFBS_UseSSE1,
  GIFBS_UseSSE2,
  GIFBS_UseSSE3,
  GIFBS_UseSSE41,
  GIFBS_UseSSSE3,
  GIFBS_HasAVX_HasAES,
  GIFBS_HasAVX_NoVLX,
  GIFBS_HasAVX_NoVLX_Or_NoBWI,
  GIFBS_HasAVX2_NoVLX,
  GIFBS_HasAVX2_NoVLX_Or_NoBWI,
  GIFBS_HasAVX512_HasVLX,
  GIFBS_HasBWI_HasVLX,
  GIFBS_HasDQI_HasVLX,
  GIFBS_HasVLX_HasBWI,
  GIFBS_OptForSize_NotSlowIncDec_Not64BitMode,
};
const static PredicateBitset FeatureBitsets[] {
  {}, // GIFBS_Invalid
  {Feature_FPStackf32Bit, },
  {Feature_FPStackf64Bit, },
  {Feature_HasAESBit, },
  {Feature_HasAVXBit, },
  {Feature_HasAVX1OnlyBit, },
  {Feature_HasAVX2Bit, },
  {Feature_HasAVX512Bit, },
  {Feature_HasBMIBit, },
  {Feature_HasBMI2Bit, },
  {Feature_HasBWIBit, },
  {Feature_HasDQIBit, },
  {Feature_HasF16CBit, },
  {Feature_HasFMA4Bit, },
  {Feature_HasSHABit, },
  {Feature_HasSSE42Bit, },
  {Feature_HasSSE4ABit, },
  {Feature_HasTBMBit, },
  {Feature_HasVLXBit, },
  {Feature_HasXOPBit, },
  {Feature_In64BitModeBit, },
  {Feature_NotSlowIncDecBit, },
  {Feature_UseAVXBit, },
  {Feature_UseSSE1Bit, },
  {Feature_UseSSE2Bit, },
  {Feature_UseSSE3Bit, },
  {Feature_UseSSE41Bit, },
  {Feature_UseSSSE3Bit, },
  {Feature_HasAVXBit, Feature_HasAESBit, },
  {Feature_HasAVXBit, Feature_NoVLXBit, },
  {Feature_HasAVXBit, Feature_NoVLX_Or_NoBWIBit, },
  {Feature_HasAVX2Bit, Feature_NoVLXBit, },
  {Feature_HasAVX2Bit, Feature_NoVLX_Or_NoBWIBit, },
  {Feature_HasAVX512Bit, Feature_HasVLXBit, },
  {Feature_HasBWIBit, Feature_HasVLXBit, },
  {Feature_HasDQIBit, Feature_HasVLXBit, },
  {Feature_HasVLXBit, Feature_HasBWIBit, },
  {Feature_OptForSizeBit, Feature_NotSlowIncDecBit, Feature_Not64BitModeBit, },
};

enum {
  GICP_Invalid,
};
// See constructor for table contents

bool X86InstructionSelector::selectImpl(MachineInstr &I) const {
  MachineFunction &MF = *I.getParent()->getParent();
  MachineRegisterInfo &MRI = MF.getRegInfo();
  // FIXME: This should be computed on a per-function basis rather than per-insn.
  AvailableFunctionFeatures = computeAvailableFunctionFeatures(&STI, &MF);
  const PredicateBitset AvailableFeatures = getAvailableFeatures();
  NewMIVector OutMIs;
  State.MIs.clear();
  State.MIs.push_back(&I);

  const static int64_t MatchTable0[] = {
    GIM_CheckFeatures, GIFBS_HasFMA4,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_fma_vfmadd_ss,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4f32 5694:iPTR, VR128:v4f32:$src1, VR128:v4f32:$src2, VR128:v4f32:$src3)  =>  (VFMADDSS4rr_Int:v4f32 VR128:v4f32:$src1, VR128:v4f32:$src2, VR128:v4f32:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VFMADDSS4rr_Int,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable0\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable0, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable1[] = {
    GIM_CheckFeatures, GIFBS_HasFMA4,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_fma_vfmsub_ss,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4f32 5704:iPTR, VR128:v4f32:$src1, VR128:v4f32:$src2, VR128:v4f32:$src3)  =>  (VFMSUBSS4rr_Int:v4f32 VR128:v4f32:$src1, VR128:v4f32:$src2, VR128:v4f32:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VFMSUBSS4rr_Int,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable1\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable1, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable2[] = {
    GIM_CheckFeatures, GIFBS_HasFMA4,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_fma_vfnmadd_ss,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4f32 5714:iPTR, VR128:v4f32:$src1, VR128:v4f32:$src2, VR128:v4f32:$src3)  =>  (VFNMADDSS4rr_Int:v4f32 VR128:v4f32:$src1, VR128:v4f32:$src2, VR128:v4f32:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VFNMADDSS4rr_Int,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable2\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable2, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable3[] = {
    GIM_CheckFeatures, GIFBS_HasFMA4,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_fma_vfnmsub_ss,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4f32 5720:iPTR, VR128:v4f32:$src1, VR128:v4f32:$src2, VR128:v4f32:$src3)  =>  (VFNMSUBSS4rr_Int:v4f32 VR128:v4f32:$src1, VR128:v4f32:$src2, VR128:v4f32:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VFNMSUBSS4rr_Int,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable3\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable3, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable4[] = {
    GIM_CheckFeatures, GIFBS_HasFMA4,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_fma_vfmadd_sd,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2f64 5693:iPTR, VR128:v2f64:$src1, VR128:v2f64:$src2, VR128:v2f64:$src3)  =>  (VFMADDSD4rr_Int:v2f64 VR128:v2f64:$src1, VR128:v2f64:$src2, VR128:v2f64:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VFMADDSD4rr_Int,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable4\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable4, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable5[] = {
    GIM_CheckFeatures, GIFBS_HasFMA4,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_fma_vfmsub_sd,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2f64 5703:iPTR, VR128:v2f64:$src1, VR128:v2f64:$src2, VR128:v2f64:$src3)  =>  (VFMSUBSD4rr_Int:v2f64 VR128:v2f64:$src1, VR128:v2f64:$src2, VR128:v2f64:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VFMSUBSD4rr_Int,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable5\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable5, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable6[] = {
    GIM_CheckFeatures, GIFBS_HasFMA4,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_fma_vfnmadd_sd,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2f64 5713:iPTR, VR128:v2f64:$src1, VR128:v2f64:$src2, VR128:v2f64:$src3)  =>  (VFNMADDSD4rr_Int:v2f64 VR128:v2f64:$src1, VR128:v2f64:$src2, VR128:v2f64:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VFNMADDSD4rr_Int,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable6\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable6, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable7[] = {
    GIM_CheckFeatures, GIFBS_HasFMA4,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_fma_vfnmsub_sd,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2f64 5719:iPTR, VR128:v2f64:$src1, VR128:v2f64:$src2, VR128:v2f64:$src3)  =>  (VFNMSUBSD4rr_Int:v2f64 VR128:v2f64:$src1, VR128:v2f64:$src2, VR128:v2f64:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VFNMSUBSD4rr_Int,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable7\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable7, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable8[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vpmadcswd,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4i32 6086:iPTR, VR128:v8i16:$src1, VR128:v8i16:$src2, VR128:v4i32:$src3)  =>  (VPMADCSWDrr:v4i32 VR128:v8i16:$src1, VR128:v8i16:$src2, VR128:v4i32:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPMADCSWDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable8\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable8, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable9[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vpmadcsswd,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4i32 6085:iPTR, VR128:v8i16:$src1, VR128:v8i16:$src2, VR128:v4i32:$src3)  =>  (VPMADCSSWDrr:v4i32 VR128:v8i16:$src1, VR128:v8i16:$src2, VR128:v4i32:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPMADCSSWDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable9\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable9, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable10[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vpmacsww,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v8i16 6084:iPTR, VR128:v8i16:$src1, VR128:v8i16:$src2, VR128:v8i16:$src3)  =>  (VPMACSWWrr:v8i16 VR128:v8i16:$src1, VR128:v8i16:$src2, VR128:v8i16:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPMACSWWrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable10\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable10, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable11[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vpmacswd,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4i32 6083:iPTR, VR128:v8i16:$src1, VR128:v8i16:$src2, VR128:v4i32:$src3)  =>  (VPMACSWDrr:v4i32 VR128:v8i16:$src1, VR128:v8i16:$src2, VR128:v4i32:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPMACSWDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable11\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable11, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable12[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vpmacssww,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v8i16 6082:iPTR, VR128:v8i16:$src1, VR128:v8i16:$src2, VR128:v8i16:$src3)  =>  (VPMACSSWWrr:v8i16 VR128:v8i16:$src1, VR128:v8i16:$src2, VR128:v8i16:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPMACSSWWrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable12\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable12, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable13[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vpmacsswd,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4i32 6081:iPTR, VR128:v8i16:$src1, VR128:v8i16:$src2, VR128:v4i32:$src3)  =>  (VPMACSSWDrr:v4i32 VR128:v8i16:$src1, VR128:v8i16:$src2, VR128:v4i32:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPMACSSWDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable13\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable13, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable14[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vpmacssdql,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2i64 6080:iPTR, VR128:v4i32:$src1, VR128:v4i32:$src2, VR128:v2i64:$src3)  =>  (VPMACSSDQLrr:v2i64 VR128:v4i32:$src1, VR128:v4i32:$src2, VR128:v2i64:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPMACSSDQLrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable14\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable14, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable15[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vpmacssdqh,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2i64 6079:iPTR, VR128:v4i32:$src1, VR128:v4i32:$src2, VR128:v2i64:$src3)  =>  (VPMACSSDQHrr:v2i64 VR128:v4i32:$src1, VR128:v4i32:$src2, VR128:v2i64:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPMACSSDQHrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable15\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable15, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable16[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vpmacssdd,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4i32 6078:iPTR, VR128:v4i32:$src1, VR128:v4i32:$src2, VR128:v4i32:$src3)  =>  (VPMACSSDDrr:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2, VR128:v4i32:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPMACSSDDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable16\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable16, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable17[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vpmacsdql,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2i64 6077:iPTR, VR128:v4i32:$src1, VR128:v4i32:$src2, VR128:v2i64:$src3)  =>  (VPMACSDQLrr:v2i64 VR128:v4i32:$src1, VR128:v4i32:$src2, VR128:v2i64:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPMACSDQLrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable17\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable17, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable18[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vpmacsdqh,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2i64 6076:iPTR, VR128:v4i32:$src1, VR128:v4i32:$src2, VR128:v2i64:$src3)  =>  (VPMACSDQHrr:v2i64 VR128:v4i32:$src1, VR128:v4i32:$src2, VR128:v2i64:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPMACSDQHrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable18\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable18, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable19[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vpmacsdd,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4i32 6075:iPTR, VR128:v4i32:$src1, VR128:v4i32:$src2, VR128:v4i32:$src3)  =>  (VPMACSDDrr:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2, VR128:v4i32:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPMACSDDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable19\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable19, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable20[] = {
    GIM_CheckFeatures, GIFBS_HasAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse41_blendvpd,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2f64 5956:iPTR, VR128:v2f64:$src1, VR128:v2f64:$src2, VR128:v2f64:$src3)  =>  (VBLENDVPDrr:v2f64 VR128:v2f64:$src1, VR128:v2f64:$src2, VR128:v2f64:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VBLENDVPDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable20\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable20, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable21[] = {
    GIM_CheckFeatures, GIFBS_HasAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_avx_blendv_pd_256,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR256RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR256RegClassID,
    // (intrinsic_wo_chain:v4f64 4665:iPTR, VR256:v4f64:$src1, VR256:v4f64:$src2, VR256:v4f64:$src3)  =>  (VBLENDVPDYrr:v4f64 VR256:v4f64:$src1, VR256:v4f64:$src2, VR256:v4f64:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VBLENDVPDYrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable21\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable21, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable22[] = {
    GIM_CheckFeatures, GIFBS_HasAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse41_blendvps,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4f32 5957:iPTR, VR128:v4f32:$src1, VR128:v4f32:$src2, VR128:v4f32:$src3)  =>  (VBLENDVPSrr:v4f32 VR128:v4f32:$src1, VR128:v4f32:$src2, VR128:v4f32:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VBLENDVPSrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable22\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable22, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable23[] = {
    GIM_CheckFeatures, GIFBS_HasAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_avx_blendv_ps_256,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR256RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR256RegClassID,
    // (intrinsic_wo_chain:v8f32 4666:iPTR, VR256:v8f32:$src1, VR256:v8f32:$src2, VR256:v8f32:$src3)  =>  (VBLENDVPSYrr:v8f32 VR256:v8f32:$src1, VR256:v8f32:$src2, VR256:v8f32:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VBLENDVPSYrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable23\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable23, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable24[] = {
    GIM_CheckFeatures, GIFBS_HasAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse41_pblendvb,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v16i8 5963:iPTR, VR128:v16i8:$src1, VR128:v16i8:$src2, VR128:v16i8:$src3)  =>  (VPBLENDVBrr:v16i8 VR128:v16i8:$src1, VR128:v16i8:$src2, VR128:v16i8:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPBLENDVBrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable24\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable24, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable25[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/5,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v32s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_avx2_pblendvb,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v32s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v32s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR256RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/4, /*Type*/GILLT_v32s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/4, /*RC*/X86::VR256RegClassID,
    // (intrinsic_wo_chain:v32i8 4763:iPTR, VR256:v32i8:$src1, VR256:v32i8:$src2, VR256:v32i8:$src3)  =>  (VPBLENDVBYrr:v32i8 VR256:v32i8:$src1, VR256:v32i8:$src2, VR256:v32i8:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPBLENDVBYrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/4, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable25\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable25, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable26[] = {
    GIM_CheckFeatures, GIFBS_HasBMI2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_bmi_pdep_32,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::GR32RegClassID,
    // (intrinsic_wo_chain:i32 5679:iPTR, GR32:i32:$src1, GR32:i32:$src2)  =>  (PDEP32rr:i32 GR32:i32:$src1, GR32:i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::PDEP32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable26\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable26, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable27[] = {
    GIM_CheckFeatures, GIFBS_HasBMI2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_bmi_pdep_64,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::GR64RegClassID,
    // (intrinsic_wo_chain:i64 5680:iPTR, GR64:i64:$src1, GR64:i64:$src2)  =>  (PDEP64rr:i64 GR64:i64:$src1, GR64:i64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::PDEP64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable27\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable27, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable28[] = {
    GIM_CheckFeatures, GIFBS_HasBMI2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_bmi_pext_32,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::GR32RegClassID,
    // (intrinsic_wo_chain:i32 5681:iPTR, GR32:i32:$src1, GR32:i32:$src2)  =>  (PEXT32rr:i32 GR32:i32:$src1, GR32:i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::PEXT32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable28\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable28, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable29[] = {
    GIM_CheckFeatures, GIFBS_HasBMI2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_bmi_pext_64,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::GR64RegClassID,
    // (intrinsic_wo_chain:i64 5682:iPTR, GR64:i64:$src1, GR64:i64:$src2)  =>  (PEXT64rr:i64 GR64:i64:$src1, GR64:i64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::PEXT64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable29\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable29, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable30[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse_cvtsi2ss,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::GR32RegClassID,
    // (intrinsic_wo_chain:v4f32 5843:iPTR, VR128:v4f32:$src1, GR32:i32:$src2)  =>  (Int_VCVTSI2SSrr:v4f32 VR128:v4f32:$src1, GR32:i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::Int_VCVTSI2SSrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable30\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable30, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable31[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse_cvtsi642ss,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::GR64RegClassID,
    // (intrinsic_wo_chain:v4f32 5844:iPTR, VR128:v4f32:$src1, GR64:i64:$src2)  =>  (Int_VCVTSI2SS64rr:v4f32 VR128:v4f32:$src1, GR64:i64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::Int_VCVTSI2SS64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable31\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable31, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable32[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_cvtsi2sd,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::GR32RegClassID,
    // (intrinsic_wo_chain:v2f64 5888:iPTR, VR128:v2f64:$src1, GR32:i32:$src2)  =>  (Int_VCVTSI2SDrr:v2f64 VR128:v2f64:$src1, GR32:i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::Int_VCVTSI2SDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable32\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable32, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable33[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_cvtsi642sd,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::GR64RegClassID,
    // (intrinsic_wo_chain:v2f64 5889:iPTR, VR128:v2f64:$src1, GR64:i64:$src2)  =>  (Int_VCVTSI2SD64rr:v2f64 VR128:v2f64:$src1, GR64:i64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::Int_VCVTSI2SD64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable33\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable33, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable34[] = {
    GIM_CheckFeatures, GIFBS_UseSSE1,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse_cvtsi2ss,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::GR32RegClassID,
    // (intrinsic_wo_chain:v4f32 5843:iPTR, VR128:v4f32:$src1, GR32:i32:$src2)  =>  (Int_CVTSI2SSrr:v4f32 VR128:v4f32:$src1, GR32:i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::Int_CVTSI2SSrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable34\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable34, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable35[] = {
    GIM_CheckFeatures, GIFBS_UseSSE1,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse_cvtsi642ss,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::GR64RegClassID,
    // (intrinsic_wo_chain:v4f32 5844:iPTR, VR128:v4f32:$src1, GR64:i64:$src2)  =>  (Int_CVTSI2SS64rr:v4f32 VR128:v4f32:$src1, GR64:i64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::Int_CVTSI2SS64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable35\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable35, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable36[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_cvtsi2sd,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::GR32RegClassID,
    // (intrinsic_wo_chain:v2f64 5888:iPTR, VR128:v2f64:$src1, GR32:i32:$src2)  =>  (Int_CVTSI2SDrr:v2f64 VR128:v2f64:$src1, GR32:i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::Int_CVTSI2SDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable36\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable36, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable37[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_cvtsi642sd,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::GR64RegClassID,
    // (intrinsic_wo_chain:v2f64 5889:iPTR, VR128:v2f64:$src1, GR64:i64:$src2)  =>  (Int_CVTSI2SD64rr:v2f64 VR128:v2f64:$src1, GR64:i64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::Int_CVTSI2SD64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable37\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable37, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable38[] = {
    GIM_CheckFeatures, GIFBS_HasAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_cvtsd2ss,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4f32 5887:iPTR, VR128:v4f32:$src1, VR128:v2f64:$src2)  =>  (Int_VCVTSD2SSrr:v4f32 VR128:v4f32:$src1, VR128:v2f64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::Int_VCVTSD2SSrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable38\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable38, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable39[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_cvtsd2ss,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4f32 5887:iPTR, VR128:v4f32:$src1, VR128:v2f64:$src2)  =>  (Int_CVTSD2SSrr:v4f32 VR128:v4f32:$src1, VR128:v2f64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::Int_CVTSD2SSrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable39\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable39, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable40[] = {
    GIM_CheckFeatures, GIFBS_HasAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_cvtss2sd,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2f64 5890:iPTR, VR128:v2f64:$src1, VR128:v4f32:$src2)  =>  (Int_VCVTSS2SDrr:v2f64 VR128:v2f64:$src1, VR128:v4f32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::Int_VCVTSS2SDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable40\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable40, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable41[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_cvtss2sd,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2f64 5890:iPTR, VR128:v2f64:$src1, VR128:v4f32:$src2)  =>  (Int_CVTSS2SDrr:v2f64 VR128:v2f64:$src1, VR128:v4f32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::Int_CVTSS2SDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable41\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable41, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable42[] = {
    GIM_CheckFeatures, GIFBS_HasAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse3_addsub_ps,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4f32 5948:iPTR, VR128:v4f32:$src1, VR128:v4f32:$src2)  =>  (VADDSUBPSrr:v4f32 VR128:v4f32:$src1, VR128:v4f32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VADDSUBPSrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable42\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable42, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable43[] = {
    GIM_CheckFeatures, GIFBS_HasAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_avx_addsub_ps_256,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR256RegClassID,
    // (intrinsic_wo_chain:v8f32 4664:iPTR, VR256:v8f32:$src1, VR256:v8f32:$src2)  =>  (VADDSUBPSYrr:v8f32 VR256:v8f32:$src1, VR256:v8f32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VADDSUBPSYrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable43\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable43, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable44[] = {
    GIM_CheckFeatures, GIFBS_HasAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse3_addsub_pd,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2f64 5947:iPTR, VR128:v2f64:$src1, VR128:v2f64:$src2)  =>  (VADDSUBPDrr:v2f64 VR128:v2f64:$src1, VR128:v2f64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VADDSUBPDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable44\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable44, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable45[] = {
    GIM_CheckFeatures, GIFBS_HasAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_avx_addsub_pd_256,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR256RegClassID,
    // (intrinsic_wo_chain:v4f64 4663:iPTR, VR256:v4f64:$src1, VR256:v4f64:$src2)  =>  (VADDSUBPDYrr:v4f64 VR256:v4f64:$src1, VR256:v4f64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VADDSUBPDYrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable45\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable45, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable46[] = {
    GIM_CheckFeatures, GIFBS_UseSSE3,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse3_addsub_ps,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4f32 5948:iPTR, VR128:v4f32:$src1, VR128:v4f32:$src2)  =>  (ADDSUBPSrr:v4f32 VR128:v4f32:$src1, VR128:v4f32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::ADDSUBPSrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable46\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable46, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable47[] = {
    GIM_CheckFeatures, GIFBS_UseSSE3,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse3_addsub_pd,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2f64 5947:iPTR, VR128:v2f64:$src1, VR128:v2f64:$src2)  =>  (ADDSUBPDrr:v2f64 VR128:v2f64:$src1, VR128:v2f64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::ADDSUBPDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable47\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable47, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable48[] = {
    GIM_CheckFeatures, GIFBS_HasAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_ssse3_psign_b_128,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v16i8 6020:iPTR, VR128:v16i8:$src1, VR128:v16i8:$src2)  =>  (VPSIGNBrr128:v16i8 VR128:v16i8:$src1, VR128:v16i8:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPSIGNBrr128,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable48\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable48, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable49[] = {
    GIM_CheckFeatures, GIFBS_HasAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_ssse3_psign_w_128,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v8i16 6024:iPTR, VR128:v8i16:$src1, VR128:v8i16:$src2)  =>  (VPSIGNWrr128:v8i16 VR128:v8i16:$src1, VR128:v8i16:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPSIGNWrr128,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable49\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable49, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable50[] = {
    GIM_CheckFeatures, GIFBS_HasAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_ssse3_psign_d_128,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4i32 6022:iPTR, VR128:v4i32:$src1, VR128:v4i32:$src2)  =>  (VPSIGNDrr128:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPSIGNDrr128,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable50\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable50, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable51[] = {
    GIM_CheckFeatures, GIFBS_HasAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_ssse3_phadd_sw_128,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v8i16 6004:iPTR, VR128:v8i16:$src1, VR128:v8i16:$src2)  =>  (VPHADDSWrr128:v8i16 VR128:v8i16:$src1, VR128:v8i16:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPHADDSWrr128,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable51\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable51, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable52[] = {
    GIM_CheckFeatures, GIFBS_HasAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_ssse3_phsub_sw_128,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v8i16 6010:iPTR, VR128:v8i16:$src1, VR128:v8i16:$src2)  =>  (VPHSUBSWrr128:v8i16 VR128:v8i16:$src1, VR128:v8i16:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPHSUBSWrr128,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable52\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable52, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable53[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v32s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_avx2_psign_b,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v32s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v32s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR256RegClassID,
    // (intrinsic_wo_chain:v32i8 4782:iPTR, VR256:v32i8:$src1, VR256:v32i8:$src2)  =>  (VPSIGNBYrr256:v32i8 VR256:v32i8:$src1, VR256:v32i8:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPSIGNBYrr256,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable53\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable53, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable54[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_avx2_psign_w,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR256RegClassID,
    // (intrinsic_wo_chain:v16i16 4784:iPTR, VR256:v16i16:$src1, VR256:v16i16:$src2)  =>  (VPSIGNWYrr256:v16i16 VR256:v16i16:$src1, VR256:v16i16:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPSIGNWYrr256,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable54\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable54, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable55[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_avx2_psign_d,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR256RegClassID,
    // (intrinsic_wo_chain:v8i32 4783:iPTR, VR256:v8i32:$src1, VR256:v8i32:$src2)  =>  (VPSIGNDYrr256:v8i32 VR256:v8i32:$src1, VR256:v8i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPSIGNDYrr256,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable55\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable55, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable56[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_avx2_phadd_sw,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR256RegClassID,
    // (intrinsic_wo_chain:v16i16 4767:iPTR, VR256:v16i16:$src1, VR256:v16i16:$src2)  =>  (VPHADDSWrr256:v16i16 VR256:v16i16:$src1, VR256:v16i16:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPHADDSWrr256,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable56\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable56, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable57[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_avx2_phsub_sw,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR256RegClassID,
    // (intrinsic_wo_chain:v16i16 4770:iPTR, VR256:v16i16:$src1, VR256:v16i16:$src2)  =>  (VPHSUBSWrr256:v16i16 VR256:v16i16:$src1, VR256:v16i16:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPHSUBSWrr256,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable57\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable57, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable58[] = {
    GIM_CheckFeatures, GIFBS_UseSSSE3,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_ssse3_psign_b_128,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v16i8 6020:iPTR, VR128:v16i8:$src1, VR128:v16i8:$src2)  =>  (PSIGNBrr128:v16i8 VR128:v16i8:$src1, VR128:v16i8:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::PSIGNBrr128,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable58\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable58, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable59[] = {
    GIM_CheckFeatures, GIFBS_UseSSSE3,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_ssse3_psign_w_128,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v8i16 6024:iPTR, VR128:v8i16:$src1, VR128:v8i16:$src2)  =>  (PSIGNWrr128:v8i16 VR128:v8i16:$src1, VR128:v8i16:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::PSIGNWrr128,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable59\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable59, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable60[] = {
    GIM_CheckFeatures, GIFBS_UseSSSE3,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_ssse3_psign_d_128,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4i32 6022:iPTR, VR128:v4i32:$src1, VR128:v4i32:$src2)  =>  (PSIGNDrr128:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::PSIGNDrr128,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable60\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable60, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable61[] = {
    GIM_CheckFeatures, GIFBS_UseSSSE3,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_ssse3_phadd_sw_128,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v8i16 6004:iPTR, VR128:v8i16:$src1, VR128:v8i16:$src2)  =>  (PHADDSWrr128:v8i16 VR128:v8i16:$src1, VR128:v8i16:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::PHADDSWrr128,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable61\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable61, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable62[] = {
    GIM_CheckFeatures, GIFBS_UseSSSE3,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_ssse3_phsub_sw_128,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v8i16 6010:iPTR, VR128:v8i16:$src1, VR128:v8i16:$src2)  =>  (PHSUBSWrr128:v8i16 VR128:v8i16:$src1, VR128:v8i16:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::PHSUBSWrr128,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable62\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable62, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable63[] = {
    GIM_CheckFeatures, GIFBS_HasSSE42,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse42_crc32_32_8,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::GR8RegClassID,
    // (intrinsic_wo_chain:i32 5975:iPTR, GR32:i32:$src1, GR8:i8:$src2)  =>  (CRC32r32r8:i32 GR32:i32:$src1, GR8:i8:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::CRC32r32r8,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable63\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable63, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable64[] = {
    GIM_CheckFeatures, GIFBS_HasSSE42,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse42_crc32_32_16,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::GR16RegClassID,
    // (intrinsic_wo_chain:i32 5973:iPTR, GR32:i32:$src1, GR16:i16:$src2)  =>  (CRC32r32r16:i32 GR32:i32:$src1, GR16:i16:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::CRC32r32r16,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable64\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable64, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable65[] = {
    GIM_CheckFeatures, GIFBS_HasSSE42,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse42_crc32_32_32,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::GR32RegClassID,
    // (intrinsic_wo_chain:i32 5974:iPTR, GR32:i32:$src1, GR32:i32:$src2)  =>  (CRC32r32r32:i32 GR32:i32:$src1, GR32:i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::CRC32r32r32,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable65\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable65, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable66[] = {
    GIM_CheckFeatures, GIFBS_HasSSE42,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse42_crc32_64_64,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::GR64RegClassID,
    // (intrinsic_wo_chain:i64 5976:iPTR, GR64:i64:$src1, GR64:i64:$src2)  =>  (CRC32r64r64:i64 GR64:i64:$src1, GR64:i64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::CRC32r64r64,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable66\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable66, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable67[] = {
    GIM_CheckFeatures, GIFBS_HasSHA,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sha1nexte,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4i32 5825:iPTR, VR128:v4i32:$src1, VR128:v4i32:$src2)  =>  (SHA1NEXTErr:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::SHA1NEXTErr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable67\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable67, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable68[] = {
    GIM_CheckFeatures, GIFBS_HasSHA,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sha1msg1,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4i32 5823:iPTR, VR128:v4i32:$src1, VR128:v4i32:$src2)  =>  (SHA1MSG1rr:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::SHA1MSG1rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable68\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable68, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable69[] = {
    GIM_CheckFeatures, GIFBS_HasSHA,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sha1msg2,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4i32 5824:iPTR, VR128:v4i32:$src1, VR128:v4i32:$src2)  =>  (SHA1MSG2rr:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::SHA1MSG2rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable69\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable69, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable70[] = {
    GIM_CheckFeatures, GIFBS_HasSHA,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sha256msg1,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4i32 5827:iPTR, VR128:v4i32:$src1, VR128:v4i32:$src2)  =>  (SHA256MSG1rr:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::SHA256MSG1rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable70\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable70, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable71[] = {
    GIM_CheckFeatures, GIFBS_HasSHA,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sha256msg2,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4i32 5828:iPTR, VR128:v4i32:$src1, VR128:v4i32:$src2)  =>  (SHA256MSG2rr:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::SHA256MSG2rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable71\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable71, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable72[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_HasAES,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_aesni_aesenc,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2i64 4659:iPTR, VR128:v2i64:$src1, VR128:v2i64:$src2)  =>  (VAESENCrr:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VAESENCrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable72\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable72, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable73[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_HasAES,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_aesni_aesenclast,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2i64 4660:iPTR, VR128:v2i64:$src1, VR128:v2i64:$src2)  =>  (VAESENCLASTrr:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VAESENCLASTrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable73\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable73, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable74[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_HasAES,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_aesni_aesdec,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2i64 4657:iPTR, VR128:v2i64:$src1, VR128:v2i64:$src2)  =>  (VAESDECrr:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VAESDECrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable74\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable74, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable75[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_HasAES,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_aesni_aesdeclast,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2i64 4658:iPTR, VR128:v2i64:$src1, VR128:v2i64:$src2)  =>  (VAESDECLASTrr:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VAESDECLASTrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable75\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable75, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable76[] = {
    GIM_CheckFeatures, GIFBS_HasAES,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_aesni_aesenc,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2i64 4659:iPTR, VR128:v2i64:$src1, VR128:v2i64:$src2)  =>  (AESENCrr:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::AESENCrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable76\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable76, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable77[] = {
    GIM_CheckFeatures, GIFBS_HasAES,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_aesni_aesenclast,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2i64 4660:iPTR, VR128:v2i64:$src1, VR128:v2i64:$src2)  =>  (AESENCLASTrr:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::AESENCLASTrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable77\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable77, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable78[] = {
    GIM_CheckFeatures, GIFBS_HasAES,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_aesni_aesdec,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2i64 4657:iPTR, VR128:v2i64:$src1, VR128:v2i64:$src2)  =>  (AESDECrr:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::AESDECrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable78\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable78, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable79[] = {
    GIM_CheckFeatures, GIFBS_HasAES,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_aesni_aesdeclast,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2i64 4658:iPTR, VR128:v2i64:$src1, VR128:v2i64:$src2)  =>  (AESDECLASTrr:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::AESDECLASTrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable79\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable79, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable80[] = {
    GIM_CheckFeatures, GIFBS_HasSSE4A,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse4a_extrq,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] mask
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2i64 5991:iPTR, VR128:v2i64:$src, VR128:v16i8:$mask)  =>  (EXTRQ:v2i64 VR128:v2i64:$src, VR128:v16i8:$mask)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::EXTRQ,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // mask
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable80\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable80, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable81[] = {
    GIM_CheckFeatures, GIFBS_HasSSE4A,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse4a_insertq,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] mask
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2i64 5993:iPTR, VR128:v2i64:$src, VR128:v2i64:$mask)  =>  (INSERTQ:v2i64 VR128:v2i64:$src, VR128:v2i64:$mask)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::INSERTQ,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // mask
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable81\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable81, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable82[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse_cvtsi2ss,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::GR32RegClassID,
    // (intrinsic_wo_chain:v4f32 5843:iPTR, VR128X:v4f32:$src1, GR32:i32:$src2)  =>  (VCVTSI2SSZrr_Int:v4f32 VR128X:v4f32:$src1, GR32:i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VCVTSI2SSZrr_Int,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable82\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable82, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable83[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse_cvtsi642ss,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::GR64RegClassID,
    // (intrinsic_wo_chain:v4f32 5844:iPTR, VR128X:v4f32:$src1, GR64:i64:$src2)  =>  (VCVTSI642SSZrr_Int:v4f32 VR128X:v4f32:$src1, GR64:i64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VCVTSI642SSZrr_Int,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable83\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable83, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable84[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_cvtsi2sd,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::GR32RegClassID,
    // (intrinsic_wo_chain:v2f64 5888:iPTR, VR128X:v2f64:$src1, GR32:i32:$src2)  =>  (VCVTSI2SDZrr_Int:v2f64 VR128X:v2f64:$src1, GR32:i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VCVTSI2SDZrr_Int,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable84\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable84, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable85[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_cvtsi642sd,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::GR64RegClassID,
    // (intrinsic_wo_chain:v2f64 5889:iPTR, VR128X:v2f64:$src1, GR64:i64:$src2)  =>  (VCVTSI642SDZrr_Int:v2f64 VR128X:v2f64:$src1, GR64:i64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VCVTSI642SDZrr_Int,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable85\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable85, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable86[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/4,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_avx512_cvtusi2sd,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/3, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/3, /*RC*/X86::GR32RegClassID,
    // (intrinsic_wo_chain:v2f64 4842:iPTR, VR128X:v2f64:$src1, GR32:i32:$src2)  =>  (VCVTUSI2SDZrr_Int:v2f64 VR128X:v2f64:$src1, GR32:i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VCVTUSI2SDZrr_Int,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/3, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable86\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable86, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable87[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s16, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_MUL,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v8s16, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[1] src2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (add:v8i16 (mul:v8i16 VR128:v8i16:$src1, VR128:v8i16:$src2), VR128:v8i16:$src3)  =>  (VPMACSWWrr:v8i16 VR128:v8i16:$src1, VR128:v8i16:$src2, VR128:v8i16:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPMACSWWrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/2, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable87\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable87, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable88[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_MUL,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v4s32, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[1] src2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (add:v4i32 (mul:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2), VR128:v4i32:$src3)  =>  (VPMACSDDrr:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2, VR128:v4i32:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPMACSDDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/2, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable88\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable88, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable89[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/2, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_MUL,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v8s16, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[1] src2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/2, /*RC*/X86::VR128RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (add:v8i16 VR128:v8i16:$src3, (mul:v8i16 VR128:v8i16:$src1, VR128:v8i16:$src2))  =>  (VPMACSWWrr:v8i16 VR128:v8i16:$src1, VR128:v8i16:$src2, VR128:v8i16:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPMACSWWrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/2, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable89\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable89, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable90[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/2, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src3
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_MUL,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v4s32, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[1] src2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/2, /*RC*/X86::VR128RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (add:v4i32 VR128:v4i32:$src3, (mul:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2))  =>  (VPMACSDDrr:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2, VR128:v4i32:$src3)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPMACSDDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/2, // src2
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src3
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable90\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable90, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable91[] = {
    GIM_CheckFeatures, GIFBS_NotSlowIncDec,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR8RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR8RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s8, 
    GIM_CheckConstantInt, /*MI*/0, /*Op*/2, 1,
    // (add:i8 GR8:i8:$src, 1:i8)  =>  (INC8r:i8:i32 GR8:i8:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::INC8r,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable91\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable91, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable92[] = {
    GIM_CheckFeatures, GIFBS_NotSlowIncDec,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR16RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR16RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s16, 
    GIM_CheckConstantInt, /*MI*/0, /*Op*/2, 1,
    // (add:i16 GR16:i16:$src, 1:i16)  =>  (INC16r:i16:i32 GR16:i16:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::INC16r,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable92\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable92, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable93[] = {
    GIM_CheckFeatures, GIFBS_NotSlowIncDec,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/0, /*Op*/2, 1,
    // (add:i32 GR32:i32:$src, 1:i32)  =>  (INC32r:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::INC32r,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable93\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable93, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable94[] = {
    GIM_CheckFeatures, GIFBS_NotSlowIncDec,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/0, /*Op*/2, 1,
    // (add:i64 GR64:i64:$src, 1:i64)  =>  (INC64r:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::INC64r,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable94\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable94, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable95[] = {
    GIM_CheckFeatures, GIFBS_NotSlowIncDec,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR8RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR8RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s8, 
    GIM_CheckConstantInt, /*MI*/0, /*Op*/2, -1,
    // (add:i8 GR8:i8:$src, -1:i8)  =>  (DEC8r:i8:i32 GR8:i8:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::DEC8r,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable95\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable95, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable96[] = {
    GIM_CheckFeatures, GIFBS_NotSlowIncDec,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR16RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR16RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s16, 
    GIM_CheckConstantInt, /*MI*/0, /*Op*/2, -1,
    // (add:i16 GR16:i16:$src, -1:i16)  =>  (DEC16r:i16:i32 GR16:i16:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::DEC16r,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable96\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable96, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable97[] = {
    GIM_CheckFeatures, GIFBS_NotSlowIncDec,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/0, /*Op*/2, -1,
    // (add:i32 GR32:i32:$src, -1:i32)  =>  (DEC32r:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::DEC32r,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable97\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable97, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable98[] = {
    GIM_CheckFeatures, GIFBS_NotSlowIncDec,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/0, /*Op*/2, -1,
    // (add:i64 GR64:i64:$src, -1:i64)  =>  (DEC64r:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::DEC64r,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable98\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable98, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable99[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX_Or_NoBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (add:v16i8 VR128:v16i8:$src1, VR128:v16i8:$src2)  =>  (VPADDBrr:v16i8 VR128:v16i8:$src1, VR128:v16i8:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPADDBrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable99\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable99, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable100[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (add:v16i8 VR128:v16i8:$src1, VR128:v16i8:$src2)  =>  (PADDBrr:v16i8 VR128:v16i8:$src1, VR128:v16i8:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::PADDBrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable100\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable100, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable101[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2_NoVLX_Or_NoBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v32s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v32s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v32s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (add:v32i8 VR256:v32i8:$src1, VR256:v32i8:$src2)  =>  (VPADDBYrr:v32i8 VR256:v32i8:$src1, VR256:v32i8:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPADDBYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable101\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable101, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable102[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX_Or_NoBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (add:v8i16 VR128:v8i16:$src1, VR128:v8i16:$src2)  =>  (VPADDWrr:v8i16 VR128:v8i16:$src1, VR128:v8i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPADDWrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable102\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable102, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable103[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (add:v8i16 VR128:v8i16:$src1, VR128:v8i16:$src2)  =>  (PADDWrr:v8i16 VR128:v8i16:$src1, VR128:v8i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::PADDWrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable103\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable103, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable104[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2_NoVLX_Or_NoBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (add:v16i16 VR256:v16i16:$src1, VR256:v16i16:$src2)  =>  (VPADDWYrr:v16i16 VR256:v16i16:$src1, VR256:v16i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPADDWYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable104\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable104, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable105[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (add:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2)  =>  (VPADDDrr:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPADDDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable105\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable105, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable106[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (add:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2)  =>  (PADDDrr:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::PADDDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable106\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable106, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable107[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (add:v8i32 VR256:v8i32:$src1, VR256:v8i32:$src2)  =>  (VPADDDYrr:v8i32 VR256:v8i32:$src1, VR256:v8i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPADDDYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable107\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable107, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable108[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (add:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)  =>  (VPADDQrr:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPADDQrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable108\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable108, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable109[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (add:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)  =>  (PADDQrr:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::PADDQrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable109\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable109, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable110[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (add:v4i64 VR256:v4i64:$src1, VR256:v4i64:$src2)  =>  (VPADDQYrr:v4i64 VR256:v4i64:$src1, VR256:v4i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPADDQYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable110\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable110, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable111[] = {
    GIM_CheckFeatures, GIFBS_HasDQI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VK8RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VK8RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VK8RegClassID,
    // (add:v8i1 VK8:v8i1:$src1, VK8:v8i1:$src2)  =>  (KADDBrr:v8i1 VK8:v8i1:$src1, VK8:v8i1:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::KADDBrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable111\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable111, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable112[] = {
    GIM_CheckFeatures, GIFBS_HasDQI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VK16RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VK16RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VK16RegClassID,
    // (add:v16i1 VK16:v16i1:$src1, VK16:v16i1:$src2)  =>  (KADDWrr:v16i1 VK16:v16i1:$src1, VK16:v16i1:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::KADDWrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable112\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable112, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable113[] = {
    GIM_CheckFeatures, GIFBS_HasBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v32s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VK32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v32s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VK32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v32s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VK32RegClassID,
    // (add:v32i1 VK32:v32i1:$src1, VK32:v32i1:$src2)  =>  (KADDDrr:v32i1 VK32:v32i1:$src1, VK32:v32i1:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::KADDDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable113\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable113, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable114[] = {
    GIM_CheckFeatures, GIFBS_HasBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v64s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VK64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v64s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VK64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v64s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VK64RegClassID,
    // (add:v64i1 VK64:v64i1:$src1, VK64:v64i1:$src2)  =>  (KADDQrr:v64i1 VK64:v64i1:$src1, VK64:v64i1:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::KADDQrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable114\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable114, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable115[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (add:v8i64 VR512:v8i64:$src1, VR512:v8i64:$src2)  =>  (VPADDQZrr:v8i64 VR512:v8i64:$src1, VR512:v8i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPADDQZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable115\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable115, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable116[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (add:v4i64 VR256X:v4i64:$src1, VR256X:v4i64:$src2)  =>  (VPADDQZ256rr:v4i64 VR256X:v4i64:$src1, VR256X:v4i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPADDQZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable116\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable116, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable117[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (add:v2i64 VR128X:v2i64:$src1, VR128X:v2i64:$src2)  =>  (VPADDQZ128rr:v2i64 VR128X:v2i64:$src1, VR128X:v2i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPADDQZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable117\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable117, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable118[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (add:v16i32 VR512:v16i32:$src1, VR512:v16i32:$src2)  =>  (VPADDDZrr:v16i32 VR512:v16i32:$src1, VR512:v16i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPADDDZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable118\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable118, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable119[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (add:v8i32 VR256X:v8i32:$src1, VR256X:v8i32:$src2)  =>  (VPADDDZ256rr:v8i32 VR256X:v8i32:$src1, VR256X:v8i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPADDDZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable119\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable119, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable120[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (add:v4i32 VR128X:v4i32:$src1, VR128X:v4i32:$src2)  =>  (VPADDDZ128rr:v4i32 VR128X:v4i32:$src1, VR128X:v4i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPADDDZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable120\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable120, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable121[] = {
    GIM_CheckFeatures, GIFBS_HasBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v32s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v32s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v32s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (add:v32i16 VR512:v32i16:$src1, VR512:v32i16:$src2)  =>  (VPADDWZrr:v32i16 VR512:v32i16:$src1, VR512:v32i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPADDWZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable121\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable121, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable122[] = {
    GIM_CheckFeatures, GIFBS_HasBWI_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (add:v16i16 VR256X:v16i16:$src1, VR256X:v16i16:$src2)  =>  (VPADDWZ256rr:v16i16 VR256X:v16i16:$src1, VR256X:v16i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPADDWZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable122\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable122, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable123[] = {
    GIM_CheckFeatures, GIFBS_HasBWI_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (add:v8i16 VR128X:v8i16:$src1, VR128X:v8i16:$src2)  =>  (VPADDWZ128rr:v8i16 VR128X:v8i16:$src1, VR128X:v8i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPADDWZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable123\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable123, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable124[] = {
    GIM_CheckFeatures, GIFBS_HasBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v64s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v64s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v64s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (add:v64i8 VR512:v64i8:$src1, VR512:v64i8:$src2)  =>  (VPADDBZrr:v64i8 VR512:v64i8:$src1, VR512:v64i8:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPADDBZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable124\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable124, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable125[] = {
    GIM_CheckFeatures, GIFBS_HasBWI_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v32s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v32s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v32s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (add:v32i8 VR256X:v32i8:$src1, VR256X:v32i8:$src2)  =>  (VPADDBZ256rr:v32i8 VR256X:v32i8:$src1, VR256X:v32i8:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPADDBZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable125\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable125, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable126[] = {
    GIM_CheckFeatures, GIFBS_HasBWI_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (add:v16i8 VR128X:v16i8:$src1, VR128X:v16i8:$src2)  =>  (VPADDBZ128rr:v16i8 VR128X:v16i8:$src1, VR128X:v16i8:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPADDBZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable126\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable126, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable127[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR8RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR8RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR8RegClassID,
    // (add:i8 GR8:i8:$src1, GR8:i8:$src2)  =>  (ADD8rr:i8:i32 GR8:i8:$src1, GR8:i8:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::ADD8rr,
    GIR_AddImplicitDef, 0, X86::EFLAGS,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable127\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable127, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable128[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR16RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR16RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR16RegClassID,
    // (add:i16 GR16:i16:$src1, GR16:i16:$src2)  =>  (ADD16rr:i16:i32 GR16:i16:$src1, GR16:i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::ADD16rr,
    GIR_AddImplicitDef, 0, X86::EFLAGS,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable128\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable128, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable129[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR32RegClassID,
    // (add:i32 GR32:i32:$src1, GR32:i32:$src2)  =>  (ADD32rr:i32:i32 GR32:i32:$src1, GR32:i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::ADD32rr,
    GIR_AddImplicitDef, 0, X86::EFLAGS,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable129\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable129, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable130[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR64RegClassID,
    // (add:i64 GR64:i64:$src1, GR64:i64:$src2)  =>  (ADD64rr:i64:i32 GR64:i64:$src1, GR64:i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::ADD64rr,
    GIR_AddImplicitDef, 0, X86::EFLAGS,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable130\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable130, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable131[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v4s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v4s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR256RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (and:v4i64 (bitconvert:v4i64 VR256:v8f32:$src1), (bitconvert:v4i64 VR256:v8f32:$src2))  =>  (VANDPSYrr:v4i64 VR256:v8f32:$src1, VR256:v8f32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VANDPSYrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable131\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable131, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable132[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v4s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v4s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR256RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (and:v4i64 (bitconvert:v4i64 VR256:v4f64:$src1), (bitconvert:v4i64 VR256:v4f64:$src2))  =>  (VANDPDYrr:v4i64 VR256:v4f64:$src1, VR256:v4f64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VANDPDYrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable132\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable132, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable133[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR128RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (and:v2i64 (bitconvert:v2i64 VR128:v4f32:$src1), (bitconvert:v2i64 VR128:v4f32:$src2))  =>  (VANDPSrr:v2i64 VR128:v4f32:$src1, VR128:v4f32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VANDPSrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable133\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable133, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable134[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR128RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (and:v2i64 (bitconvert:v2i64 VR128:v2f64:$src1), (bitconvert:v2i64 VR128:v2f64:$src2))  =>  (VANDPDrr:v2i64 VR128:v2f64:$src1, VR128:v2f64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VANDPDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable134\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable134, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable135[] = {
    GIM_CheckFeatures, GIFBS_UseSSE1,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR128RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (and:v2i64 (bitconvert:v2i64 VR128:v4f32:$src1), (bitconvert:v2i64 VR128:v4f32:$src2))  =>  (ANDPSrr:v2i64 VR128:v4f32:$src1, VR128:v4f32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::ANDPSrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable135\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable135, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable136[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR128RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (and:v2i64 (bitconvert:v2i64 VR128:v2f64:$src1), (bitconvert:v2i64 VR128:v2f64:$src2))  =>  (ANDPDrr:v2i64 VR128:v2f64:$src1, VR128:v2f64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::ANDPDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable136\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable136, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable137[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v8s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v8s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR512RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (and:v8i64 (bitconvert:v8i64 VR512:v16i32:$src1), (bitconvert:v8i64 VR512:v16i32:$src2))  =>  (VPANDDZrr:v8i64 VR512:v16i32:$src1, VR512:v16i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPANDDZrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable137\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable137, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable138[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v4s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v4s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (and:v4i64 (bitconvert:v4i64 VR256X:v8i32:$src1), (bitconvert:v4i64 VR256X:v8i32:$src2))  =>  (VPANDDZ256rr:v4i64 VR256X:v8i32:$src1, VR256X:v8i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPANDDZ256rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable138\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable138, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable139[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (and:v2i64 (bitconvert:v2i64 VR128X:v4i32:$src1), (bitconvert:v2i64 VR128X:v4i32:$src2))  =>  (VPANDDZ128rr:v2i64 VR128X:v4i32:$src1, VR128X:v4i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPANDDZ128rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable139\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable139, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable140[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_XOR,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_ADD,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[2] src
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[2] Operand 2
    GIM_CheckType, /*MI*/2, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/2, /*Op*/2, 1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (and:i32 (xor:i32 GR32:i32:$src, -1:i32), (add:i32 GR32:i32:$src, 1:i32))  =>  (BLCIC32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLCIC32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable140\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable140, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable141[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_XOR,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_ADD,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[2] src
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[2] Operand 2
    GIM_CheckType, /*MI*/2, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/2, /*Op*/2, 1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (and:i64 (xor:i64 GR64:i64:$src, -1:i64), (add:i64 GR64:i64:$src, 1:i64))  =>  (BLCIC64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLCIC64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable141\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable141, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable142[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_XOR,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_ADD,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[2] src
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[2] Operand 2
    GIM_CheckType, /*MI*/2, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/2, /*Op*/2, -1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (and:i32 (xor:i32 GR32:i32:$src, -1:i32), (add:i32 GR32:i32:$src, -1:i32))  =>  (TZMSK32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::TZMSK32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable142\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable142, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable143[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_XOR,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_ADD,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[2] src
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[2] Operand 2
    GIM_CheckType, /*MI*/2, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/2, /*Op*/2, -1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (and:i64 (xor:i64 GR64:i64:$src, -1:i64), (add:i64 GR64:i64:$src, -1:i64))  =>  (TZMSK64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::TZMSK64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable143\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable143, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable144[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, 1,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_XOR,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[2] src
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[2] Operand 2
    GIM_CheckType, /*MI*/2, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/2, /*Op*/2, -1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (and:i32 (add:i32 GR32:i32:$src, 1:i32), (xor:i32 GR32:i32:$src, -1:i32))  =>  (BLCIC32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLCIC32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable144\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable144, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable145[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, 1,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_XOR,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[2] src
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[2] Operand 2
    GIM_CheckType, /*MI*/2, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/2, /*Op*/2, -1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (and:i64 (add:i64 GR64:i64:$src, 1:i64), (xor:i64 GR64:i64:$src, -1:i64))  =>  (BLCIC64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLCIC64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable145\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable145, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable146[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_XOR,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[2] src
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[2] Operand 2
    GIM_CheckType, /*MI*/2, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/2, /*Op*/2, -1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (and:i32 (add:i32 GR32:i32:$src, -1:i32), (xor:i32 GR32:i32:$src, -1:i32))  =>  (TZMSK32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::TZMSK32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable146\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable146, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable147[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_XOR,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[2] src
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[2] Operand 2
    GIM_CheckType, /*MI*/2, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/2, /*Op*/2, -1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (and:i64 (add:i64 GR64:i64:$src, -1:i64), (xor:i64 GR64:i64:$src, -1:i64))  =>  (TZMSK64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::TZMSK64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable147\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable147, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable148[] = {
    GIM_CheckFeatures, GIFBS_HasBMI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_XOR,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR32RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (and:i32 (xor:i32 GR32:i32:$src1, -1:i32), GR32:i32:$src2)  =>  (ANDN32rr:i32:i32 GR32:i32:$src1, GR32:i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::ANDN32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable148\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable148, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable149[] = {
    GIM_CheckFeatures, GIFBS_HasBMI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_XOR,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR64RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (and:i64 (xor:i64 GR64:i64:$src1, -1:i64), GR64:i64:$src2)  =>  (ANDN64rr:i64:i32 GR64:i64:$src1, GR64:i64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::ANDN64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable149\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable149, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable150[] = {
    GIM_CheckFeatures, GIFBS_HasBMI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR32RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (and:i32 (add:i32 GR32:i32:$src, -1:i32), GR32:i32:$src)  =>  (BLSR32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLSR32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable150\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable150, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable151[] = {
    GIM_CheckFeatures, GIFBS_HasBMI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR64RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (and:i64 (add:i64 GR64:i64:$src, -1:i64), GR64:i64:$src)  =>  (BLSR64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLSR64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable151\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable151, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable152[] = {
    GIM_CheckFeatures, GIFBS_HasBMI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_SUB,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] Operand 1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/1, 0,
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/2, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR32RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (and:i32 (sub:i32 0:i32, GR32:i32:$src), GR32:i32:$src)  =>  (BLSI32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLSI32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable152\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable152, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable153[] = {
    GIM_CheckFeatures, GIFBS_HasBMI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_SUB,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] Operand 1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/1, 0,
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/2, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR64RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (and:i64 (sub:i64 0:i64, GR64:i64:$src), GR64:i64:$src)  =>  (BLSI64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLSI64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable153\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable153, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable154[] = {
    GIM_CheckFeatures, GIFBS_HasBMI2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/1, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/3, /*MI*/2, /*OpIdx*/1, // MIs[3]
    GIM_CheckNumOperands, /*MI*/3, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_LSHR,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] Operand 1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/1, -1,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s8, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_TRUNC,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_s8, 
    // MIs[2] Operand 1
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/3, TargetOpcode::G_SUB,
    // MIs[3] Operand 0
    GIM_CheckType, /*MI*/3, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[3] Operand 1
    GIM_CheckType, /*MI*/3, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/3, /*Op*/1, 32,
    // MIs[3] lz
    GIM_CheckType, /*MI*/3, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/3, /*Op*/2, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR32RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    GIM_CheckIsSafeToFold, /*InsnID*/3,
    // (and:i32 (srl:i32 -1:i32, (trunc:i8 (sub:i32 32:i32, GR32:i32:$lz))), GR32:i32:$src)  =>  (BZHI32rr:i32:i32 GR32:i32:$src, GR32:i32:$lz)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BZHI32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/3, /*OpIdx*/2, // lz
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable154\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable154, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable155[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, 1,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR32RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (and:i32 (add:i32 GR32:i32:$src, 1:i32), GR32:i32:$src)  =>  (BLCFILL32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLCFILL32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable155\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable155, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable156[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, 1,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR64RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (and:i64 (add:i64 GR64:i64:$src, 1:i64), GR64:i64:$src)  =>  (BLCFILL64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLCFILL64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable156\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable156, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable157[] = {
    GIM_CheckFeatures, GIFBS_HasBMI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/2, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (and:i32 GR32:i32:$src, (add:i32 GR32:i32:$src, -1:i32))  =>  (BLSR32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLSR32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable157\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable157, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable158[] = {
    GIM_CheckFeatures, GIFBS_HasBMI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/2, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (and:i64 GR64:i64:$src, (add:i64 GR64:i64:$src, -1:i64))  =>  (BLSR64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLSR64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable158\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable158, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable159[] = {
    GIM_CheckFeatures, GIFBS_HasBMI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/2, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_SUB,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] Operand 1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/1, 0,
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/2, /*RC*/X86::GR32RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (and:i32 GR32:i32:$src, (sub:i32 0:i32, GR32:i32:$src))  =>  (BLSI32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLSI32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable159\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable159, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable160[] = {
    GIM_CheckFeatures, GIFBS_HasBMI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/2, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_SUB,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] Operand 1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/1, 0,
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/2, /*RC*/X86::GR64RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (and:i64 GR64:i64:$src, (sub:i64 0:i64, GR64:i64:$src))  =>  (BLSI64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLSI64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable160\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable160, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable161[] = {
    GIM_CheckFeatures, GIFBS_HasBMI2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/2, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/1, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/3, /*MI*/2, /*OpIdx*/1, // MIs[3]
    GIM_CheckNumOperands, /*MI*/3, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_LSHR,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] Operand 1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/1, -1,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s8, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_TRUNC,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_s8, 
    // MIs[2] Operand 1
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/3, TargetOpcode::G_SUB,
    // MIs[3] Operand 0
    GIM_CheckType, /*MI*/3, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[3] Operand 1
    GIM_CheckType, /*MI*/3, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/3, /*Op*/1, 32,
    // MIs[3] lz
    GIM_CheckType, /*MI*/3, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/3, /*Op*/2, /*RC*/X86::GR32RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    GIM_CheckIsSafeToFold, /*InsnID*/3,
    // (and:i32 GR32:i32:$src, (srl:i32 -1:i32, (trunc:i8 (sub:i32 32:i32, GR32:i32:$lz))))  =>  (BZHI32rr:i32:i32 GR32:i32:$src, GR32:i32:$lz)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BZHI32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/3, /*OpIdx*/2, // lz
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable161\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable161, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable162[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/2, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, 1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (and:i32 GR32:i32:$src, (add:i32 GR32:i32:$src, 1:i32))  =>  (BLCFILL32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLCFILL32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable162\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable162, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable163[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/2, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, 1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (and:i64 GR64:i64:$src, (add:i64 GR64:i64:$src, 1:i64))  =>  (BLCFILL64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLCFILL64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable163\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable163, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable164[] = {
    GIM_CheckFeatures, GIFBS_HasBMI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/2, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_XOR,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (and:i32 GR32:i32:$src2, (xor:i32 GR32:i32:$src1, -1:i32))  =>  (ANDN32rr:i32:i32 GR32:i32:$src1, GR32:i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::ANDN32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable164\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable164, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable165[] = {
    GIM_CheckFeatures, GIFBS_HasBMI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/2, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_XOR,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (and:i64 GR64:i64:$src2, (xor:i64 GR64:i64:$src1, -1:i64))  =>  (ANDN64rr:i64:i32 GR64:i64:$src1, GR64:i64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::ANDN64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable165\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable165, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable166[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (and:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)  =>  (VPANDrr:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPANDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable166\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable166, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable167[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (and:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)  =>  (PANDrr:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::PANDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable167\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable167, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable168[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (and:v4i64 VR256:v4i64:$src1, VR256:v4i64:$src2)  =>  (VPANDYrr:v4i64 VR256:v4i64:$src1, VR256:v4i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPANDYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable168\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable168, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable169[] = {
    GIM_CheckFeatures, GIFBS_HasDQI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VK8RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VK8RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VK8RegClassID,
    // (and:v8i1 VK8:v8i1:$src1, VK8:v8i1:$src2)  =>  (KANDBrr:v8i1 VK8:v8i1:$src1, VK8:v8i1:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::KANDBrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable169\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable169, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable170[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VK16RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VK16RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VK16RegClassID,
    // (and:v16i1 VK16:v16i1:$src1, VK16:v16i1:$src2)  =>  (KANDWrr:v16i1 VK16:v16i1:$src1, VK16:v16i1:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::KANDWrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable170\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable170, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable171[] = {
    GIM_CheckFeatures, GIFBS_HasBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v32s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VK32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v32s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VK32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v32s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VK32RegClassID,
    // (and:v32i1 VK32:v32i1:$src1, VK32:v32i1:$src2)  =>  (KANDDrr:v32i1 VK32:v32i1:$src1, VK32:v32i1:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::KANDDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable171\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable171, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable172[] = {
    GIM_CheckFeatures, GIFBS_HasBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v64s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VK64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v64s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VK64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v64s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VK64RegClassID,
    // (and:v64i1 VK64:v64i1:$src1, VK64:v64i1:$src2)  =>  (KANDQrr:v64i1 VK64:v64i1:$src1, VK64:v64i1:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::KANDQrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable172\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable172, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable173[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (and:v8i64 VR512:v8i64:$src1, VR512:v8i64:$src2)  =>  (VPANDQZrr:v8i64 VR512:v8i64:$src1, VR512:v8i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPANDQZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable173\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable173, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable174[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (and:v4i64 VR256X:v4i64:$src1, VR256X:v4i64:$src2)  =>  (VPANDQZ256rr:v4i64 VR256X:v4i64:$src1, VR256X:v4i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPANDQZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable174\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable174, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable175[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (and:v2i64 VR128X:v2i64:$src1, VR128X:v2i64:$src2)  =>  (VPANDQZ128rr:v2i64 VR128X:v2i64:$src1, VR128X:v2i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPANDQZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable175\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable175, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable176[] = {
    GIM_CheckFeatures, GIFBS_HasAVX1Only,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (and:v4i64 VR256:v4i64:$src1, VR256:v4i64:$src2)  =>  (VANDPSYrr:v4i64 VR256:v4i64:$src1, VR256:v4i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VANDPSYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable176\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable176, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable177[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR8RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR8RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR8RegClassID,
    // (and:i8 GR8:i8:$src1, GR8:i8:$src2)  =>  (AND8rr:i8:i32 GR8:i8:$src1, GR8:i8:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::AND8rr,
    GIR_AddImplicitDef, 0, X86::EFLAGS,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable177\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable177, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable178[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR16RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR16RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR16RegClassID,
    // (and:i16 GR16:i16:$src1, GR16:i16:$src2)  =>  (AND16rr:i16:i32 GR16:i16:$src1, GR16:i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::AND16rr,
    GIR_AddImplicitDef, 0, X86::EFLAGS,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable178\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable178, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable179[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR32RegClassID,
    // (and:i32 GR32:i32:$src1, GR32:i32:$src2)  =>  (AND32rr:i32:i32 GR32:i32:$src1, GR32:i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::AND32rr,
    GIR_AddImplicitDef, 0, X86::EFLAGS,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable179\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable179, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable180[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_AND,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR64RegClassID,
    // (and:i64 GR64:i64:$src1, GR64:i64:$src2)  =>  (AND64rr:i64:i32 GR64:i64:$src1, GR64:i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::AND64rr,
    GIR_AddImplicitDef, 0, X86::EFLAGS,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable180\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable180, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable181[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ASHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR8RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR8RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s8, 
    GIM_CheckConstantInt, /*MI*/0, /*Op*/2, 1,
    // (sra:i8 GR8:i8:$src1, 1:i8)  =>  (SAR8r1:i8:i32 GR8:i8:$src1)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::SAR8r1,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src1
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable181\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable181, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable182[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ASHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR16RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR16RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s8, 
    GIM_CheckConstantInt, /*MI*/0, /*Op*/2, 1,
    // (sra:i16 GR16:i16:$src1, 1:i8)  =>  (SAR16r1:i16:i32 GR16:i16:$src1)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::SAR16r1,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src1
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable182\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable182, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable183[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ASHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s8, 
    GIM_CheckConstantInt, /*MI*/0, /*Op*/2, 1,
    // (sra:i32 GR32:i32:$src1, 1:i8)  =>  (SAR32r1:i32:i32 GR32:i32:$src1)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::SAR32r1,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src1
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable183\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable183, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable184[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ASHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s8, 
    GIM_CheckConstantInt, /*MI*/0, /*Op*/2, 1,
    // (sra:i64 GR64:i64:$src1, 1:i8)  =>  (SAR64r1:i64:i32 GR64:i64:$src1)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::SAR64r1,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src1
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable184\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable184, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable185[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ASHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (sra:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2)  =>  (VPSRAVDrr:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSRAVDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable185\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable185, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable186[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ASHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (sra:v8i32 VR256:v8i32:$src1, VR256:v8i32:$src2)  =>  (VPSRAVDYrr:v8i32 VR256:v8i32:$src1, VR256:v8i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSRAVDYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable186\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable186, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable187[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ASHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (sra:v16i32 VR512:v16i32:$src1, VR512:v16i32:$src2)  =>  (VPSRAVDZrr:v16i32 VR512:v16i32:$src1, VR512:v16i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSRAVDZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable187\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable187, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable188[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ASHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (sra:v8i32 VR256X:v8i32:$src1, VR256X:v8i32:$src2)  =>  (VPSRAVDZ256rr:v8i32 VR256X:v8i32:$src1, VR256X:v8i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSRAVDZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable188\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable188, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable189[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ASHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (sra:v4i32 VR128X:v4i32:$src1, VR128X:v4i32:$src2)  =>  (VPSRAVDZ128rr:v4i32 VR128X:v4i32:$src1, VR128X:v4i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSRAVDZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable189\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable189, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable190[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ASHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (sra:v8i64 VR512:v8i64:$src1, VR512:v8i64:$src2)  =>  (VPSRAVQZrr:v8i64 VR512:v8i64:$src1, VR512:v8i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSRAVQZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable190\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable190, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable191[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ASHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (sra:v4i64 VR256X:v4i64:$src1, VR256X:v4i64:$src2)  =>  (VPSRAVQZ256rr:v4i64 VR256X:v4i64:$src1, VR256X:v4i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSRAVQZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable191\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable191, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable192[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ASHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (sra:v2i64 VR128X:v2i64:$src1, VR128X:v2i64:$src2)  =>  (VPSRAVQZ128rr:v2i64 VR128X:v2i64:$src1, VR128X:v2i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSRAVQZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable192\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable192, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable193[] = {
    GIM_CheckFeatures, GIFBS_HasBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ASHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v32s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v32s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v32s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (sra:v32i16 VR512:v32i16:$src1, VR512:v32i16:$src2)  =>  (VPSRAVWZrr:v32i16 VR512:v32i16:$src1, VR512:v32i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSRAVWZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable193\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable193, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable194[] = {
    GIM_CheckFeatures, GIFBS_HasVLX_HasBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ASHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (sra:v16i16 VR256X:v16i16:$src1, VR256X:v16i16:$src2)  =>  (VPSRAVWZ256rr:v16i16 VR256X:v16i16:$src1, VR256X:v16i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSRAVWZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable194\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable194, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable195[] = {
    GIM_CheckFeatures, GIFBS_HasVLX_HasBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ASHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (sra:v8i16 VR128X:v8i16:$src1, VR128X:v8i16:$src2)  =>  (VPSRAVWZ128rr:v8i16 VR128X:v8i16:$src1, VR128X:v8i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSRAVWZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable195\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable195, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable196[] = {
    GIM_CheckFeatures, GIFBS_FPStackf32,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::RFP32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::RFP32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::RFP32RegClassID,
    // (fadd:f32 RFP32:f32:$src1, RFP32:f32:$src2)  =>  (ADD_Fp32:f32:i16 RFP32:f32:$src1, RFP32:f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::ADD_Fp32,
    GIR_AddImplicitDef, 0, X86::FPSW,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable196\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable196, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable197[] = {
    GIM_CheckFeatures, GIFBS_FPStackf64,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::RFP64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::RFP64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::RFP64RegClassID,
    // (fadd:f64 RFP64:f64:$src1, RFP64:f64:$src2)  =>  (ADD_Fp64:f64:i16 RFP64:f64:$src1, RFP64:f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::ADD_Fp64,
    GIR_AddImplicitDef, 0, X86::FPSW,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable197\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable197, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable198[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s80, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::RFP80RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s80, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::RFP80RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s80, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::RFP80RegClassID,
    // (fadd:f80 RFP80:f80:$src1, RFP80:f80:$src2)  =>  (ADD_Fp80:f80:i16 RFP80:f80:$src1, RFP80:f80:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::ADD_Fp80,
    GIR_AddImplicitDef, 0, X86::FPSW,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable198\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable198, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable199[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (fadd:v4f32 VR128:v4f32:$src1, VR128:v4f32:$src2)  =>  (VADDPSrr:v4f32 VR128:v4f32:$src1, VR128:v4f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VADDPSrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable199\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable199, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable200[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (fadd:v2f64 VR128:v2f64:$src1, VR128:v2f64:$src2)  =>  (VADDPDrr:v2f64 VR128:v2f64:$src1, VR128:v2f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VADDPDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable200\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable200, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable201[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (fadd:v8f32 VR256:v8f32:$src1, VR256:v8f32:$src2)  =>  (VADDPSYrr:v8f32 VR256:v8f32:$src1, VR256:v8f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VADDPSYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable201\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable201, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable202[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (fadd:v4f64 VR256:v4f64:$src1, VR256:v4f64:$src2)  =>  (VADDPDYrr:v4f64 VR256:v4f64:$src1, VR256:v4f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VADDPDYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable202\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable202, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable203[] = {
    GIM_CheckFeatures, GIFBS_UseSSE1,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (fadd:v4f32 VR128:v4f32:$src1, VR128:v4f32:$src2)  =>  (ADDPSrr:v4f32 VR128:v4f32:$src1, VR128:v4f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::ADDPSrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable203\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable203, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable204[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (fadd:v2f64 VR128:v2f64:$src1, VR128:v2f64:$src2)  =>  (ADDPDrr:v2f64 VR128:v2f64:$src1, VR128:v2f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::ADDPDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable204\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable204, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable205[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::FR32RegClassID,
    // (fadd:f32 FR32:f32:$src1, FR32:f32:$src2)  =>  (VADDSSrr:f32 FR32:f32:$src1, FR32:f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VADDSSrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable205\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable205, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable206[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::FR64RegClassID,
    // (fadd:f64 FR64:f64:$src1, FR64:f64:$src2)  =>  (VADDSDrr:f64 FR64:f64:$src1, FR64:f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VADDSDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable206\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable206, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable207[] = {
    GIM_CheckFeatures, GIFBS_UseSSE1,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::FR32RegClassID,
    // (fadd:f32 FR32:f32:$src1, FR32:f32:$src2)  =>  (ADDSSrr:f32 FR32:f32:$src1, FR32:f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::ADDSSrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable207\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable207, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable208[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::FR64RegClassID,
    // (fadd:f64 FR64:f64:$src1, FR64:f64:$src2)  =>  (ADDSDrr:f64 FR64:f64:$src1, FR64:f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::ADDSDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable208\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable208, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable209[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR32XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR32XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::FR32XRegClassID,
    // (fadd:f32 FR32X:f32:$src1, FR32X:f32:$src2)  =>  (VADDSSZrr:f32 FR32X:f32:$src1, FR32X:f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VADDSSZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable209\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable209, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable210[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR64XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR64XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::FR64XRegClassID,
    // (fadd:f64 FR64X:f64:$src1, FR64X:f64:$src2)  =>  (VADDSDZrr:f64 FR64X:f64:$src1, FR64X:f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VADDSDZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable210\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable210, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable211[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (fadd:v16f32 VR512:v16f32:$src1, VR512:v16f32:$src2)  =>  (VADDPSZrr:v16f32 VR512:v16f32:$src1, VR512:v16f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VADDPSZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable211\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable211, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable212[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (fadd:v8f64 VR512:v8f64:$src1, VR512:v8f64:$src2)  =>  (VADDPDZrr:v8f64 VR512:v8f64:$src1, VR512:v8f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VADDPDZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable212\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable212, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable213[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (fadd:v4f32 VR128X:v4f32:$src1, VR128X:v4f32:$src2)  =>  (VADDPSZ128rr:v4f32 VR128X:v4f32:$src1, VR128X:v4f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VADDPSZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable213\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable213, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable214[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (fadd:v8f32 VR256X:v8f32:$src1, VR256X:v8f32:$src2)  =>  (VADDPSZ256rr:v8f32 VR256X:v8f32:$src1, VR256X:v8f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VADDPSZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable214\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable214, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable215[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (fadd:v2f64 VR128X:v2f64:$src1, VR128X:v2f64:$src2)  =>  (VADDPDZ128rr:v2f64 VR128X:v2f64:$src1, VR128X:v2f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VADDPDZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable215\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable215, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable216[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FADD,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (fadd:v4f64 VR256X:v4f64:$src1, VR256X:v4f64:$src2)  =>  (VADDPDZ256rr:v4f64 VR256X:v4f64:$src1, VR256X:v4f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VADDPDZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable216\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable216, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable217[] = {
    GIM_CheckFeatures, GIFBS_FPStackf32,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FDIV,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::RFP32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::RFP32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::RFP32RegClassID,
    // (fdiv:f32 RFP32:f32:$src1, RFP32:f32:$src2)  =>  (DIV_Fp32:f32:i16 RFP32:f32:$src1, RFP32:f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::DIV_Fp32,
    GIR_AddImplicitDef, 0, X86::FPSW,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable217\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable217, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable218[] = {
    GIM_CheckFeatures, GIFBS_FPStackf64,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FDIV,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::RFP64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::RFP64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::RFP64RegClassID,
    // (fdiv:f64 RFP64:f64:$src1, RFP64:f64:$src2)  =>  (DIV_Fp64:f64:i16 RFP64:f64:$src1, RFP64:f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::DIV_Fp64,
    GIR_AddImplicitDef, 0, X86::FPSW,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable218\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable218, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable219[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FDIV,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s80, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::RFP80RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s80, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::RFP80RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s80, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::RFP80RegClassID,
    // (fdiv:f80 RFP80:f80:$src1, RFP80:f80:$src2)  =>  (DIV_Fp80:f80:i16 RFP80:f80:$src1, RFP80:f80:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::DIV_Fp80,
    GIR_AddImplicitDef, 0, X86::FPSW,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable219\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable219, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable220[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FDIV,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (fdiv:v4f32 VR128:v4f32:$src1, VR128:v4f32:$src2)  =>  (VDIVPSrr:v4f32 VR128:v4f32:$src1, VR128:v4f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VDIVPSrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable220\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable220, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable221[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FDIV,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (fdiv:v2f64 VR128:v2f64:$src1, VR128:v2f64:$src2)  =>  (VDIVPDrr:v2f64 VR128:v2f64:$src1, VR128:v2f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VDIVPDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable221\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable221, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable222[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FDIV,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (fdiv:v8f32 VR256:v8f32:$src1, VR256:v8f32:$src2)  =>  (VDIVPSYrr:v8f32 VR256:v8f32:$src1, VR256:v8f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VDIVPSYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable222\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable222, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable223[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FDIV,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (fdiv:v4f64 VR256:v4f64:$src1, VR256:v4f64:$src2)  =>  (VDIVPDYrr:v4f64 VR256:v4f64:$src1, VR256:v4f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VDIVPDYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable223\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable223, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable224[] = {
    GIM_CheckFeatures, GIFBS_UseSSE1,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FDIV,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (fdiv:v4f32 VR128:v4f32:$src1, VR128:v4f32:$src2)  =>  (DIVPSrr:v4f32 VR128:v4f32:$src1, VR128:v4f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::DIVPSrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable224\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable224, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable225[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FDIV,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (fdiv:v2f64 VR128:v2f64:$src1, VR128:v2f64:$src2)  =>  (DIVPDrr:v2f64 VR128:v2f64:$src1, VR128:v2f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::DIVPDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable225\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable225, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable226[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FDIV,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::FR32RegClassID,
    // (fdiv:f32 FR32:f32:$src1, FR32:f32:$src2)  =>  (VDIVSSrr:f32 FR32:f32:$src1, FR32:f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VDIVSSrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable226\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable226, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable227[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FDIV,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::FR64RegClassID,
    // (fdiv:f64 FR64:f64:$src1, FR64:f64:$src2)  =>  (VDIVSDrr:f64 FR64:f64:$src1, FR64:f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VDIVSDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable227\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable227, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable228[] = {
    GIM_CheckFeatures, GIFBS_UseSSE1,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FDIV,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::FR32RegClassID,
    // (fdiv:f32 FR32:f32:$src1, FR32:f32:$src2)  =>  (DIVSSrr:f32 FR32:f32:$src1, FR32:f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::DIVSSrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable228\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable228, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable229[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FDIV,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::FR64RegClassID,
    // (fdiv:f64 FR64:f64:$src1, FR64:f64:$src2)  =>  (DIVSDrr:f64 FR64:f64:$src1, FR64:f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::DIVSDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable229\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable229, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable230[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FDIV,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR32XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR32XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::FR32XRegClassID,
    // (fdiv:f32 FR32X:f32:$src1, FR32X:f32:$src2)  =>  (VDIVSSZrr:f32 FR32X:f32:$src1, FR32X:f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VDIVSSZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable230\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable230, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable231[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FDIV,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR64XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR64XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::FR64XRegClassID,
    // (fdiv:f64 FR64X:f64:$src1, FR64X:f64:$src2)  =>  (VDIVSDZrr:f64 FR64X:f64:$src1, FR64X:f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VDIVSDZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable231\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable231, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable232[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FDIV,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (fdiv:v16f32 VR512:v16f32:$src1, VR512:v16f32:$src2)  =>  (VDIVPSZrr:v16f32 VR512:v16f32:$src1, VR512:v16f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VDIVPSZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable232\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable232, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable233[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FDIV,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (fdiv:v8f64 VR512:v8f64:$src1, VR512:v8f64:$src2)  =>  (VDIVPDZrr:v8f64 VR512:v8f64:$src1, VR512:v8f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VDIVPDZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable233\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable233, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable234[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FDIV,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (fdiv:v4f32 VR128X:v4f32:$src1, VR128X:v4f32:$src2)  =>  (VDIVPSZ128rr:v4f32 VR128X:v4f32:$src1, VR128X:v4f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VDIVPSZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable234\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable234, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable235[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FDIV,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (fdiv:v8f32 VR256X:v8f32:$src1, VR256X:v8f32:$src2)  =>  (VDIVPSZ256rr:v8f32 VR256X:v8f32:$src1, VR256X:v8f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VDIVPSZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable235\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable235, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable236[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FDIV,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (fdiv:v2f64 VR128X:v2f64:$src1, VR128X:v2f64:$src2)  =>  (VDIVPDZ128rr:v2f64 VR128X:v2f64:$src1, VR128X:v2f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VDIVPDZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable236\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable236, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable237[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FDIV,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (fdiv:v4f64 VR256X:v4f64:$src1, VR256X:v4f64:$src2)  =>  (VDIVPDZ256rr:v4f64 VR256X:v4f64:$src1, VR256X:v4f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VDIVPDZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable237\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable237, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable238[] = {
    GIM_CheckFeatures, GIFBS_FPStackf32,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FMUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::RFP32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::RFP32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::RFP32RegClassID,
    // (fmul:f32 RFP32:f32:$src1, RFP32:f32:$src2)  =>  (MUL_Fp32:f32:i16 RFP32:f32:$src1, RFP32:f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::MUL_Fp32,
    GIR_AddImplicitDef, 0, X86::FPSW,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable238\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable238, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable239[] = {
    GIM_CheckFeatures, GIFBS_FPStackf64,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FMUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::RFP64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::RFP64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::RFP64RegClassID,
    // (fmul:f64 RFP64:f64:$src1, RFP64:f64:$src2)  =>  (MUL_Fp64:f64:i16 RFP64:f64:$src1, RFP64:f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::MUL_Fp64,
    GIR_AddImplicitDef, 0, X86::FPSW,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable239\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable239, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable240[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FMUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s80, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::RFP80RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s80, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::RFP80RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s80, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::RFP80RegClassID,
    // (fmul:f80 RFP80:f80:$src1, RFP80:f80:$src2)  =>  (MUL_Fp80:f80:i16 RFP80:f80:$src1, RFP80:f80:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::MUL_Fp80,
    GIR_AddImplicitDef, 0, X86::FPSW,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable240\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable240, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable241[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FMUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (fmul:v4f32 VR128:v4f32:$src1, VR128:v4f32:$src2)  =>  (VMULPSrr:v4f32 VR128:v4f32:$src1, VR128:v4f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VMULPSrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable241\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable241, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable242[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FMUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (fmul:v2f64 VR128:v2f64:$src1, VR128:v2f64:$src2)  =>  (VMULPDrr:v2f64 VR128:v2f64:$src1, VR128:v2f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VMULPDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable242\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable242, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable243[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FMUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (fmul:v8f32 VR256:v8f32:$src1, VR256:v8f32:$src2)  =>  (VMULPSYrr:v8f32 VR256:v8f32:$src1, VR256:v8f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VMULPSYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable243\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable243, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable244[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FMUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (fmul:v4f64 VR256:v4f64:$src1, VR256:v4f64:$src2)  =>  (VMULPDYrr:v4f64 VR256:v4f64:$src1, VR256:v4f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VMULPDYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable244\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable244, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable245[] = {
    GIM_CheckFeatures, GIFBS_UseSSE1,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FMUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (fmul:v4f32 VR128:v4f32:$src1, VR128:v4f32:$src2)  =>  (MULPSrr:v4f32 VR128:v4f32:$src1, VR128:v4f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::MULPSrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable245\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable245, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable246[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FMUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (fmul:v2f64 VR128:v2f64:$src1, VR128:v2f64:$src2)  =>  (MULPDrr:v2f64 VR128:v2f64:$src1, VR128:v2f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::MULPDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable246\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable246, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable247[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FMUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::FR32RegClassID,
    // (fmul:f32 FR32:f32:$src1, FR32:f32:$src2)  =>  (VMULSSrr:f32 FR32:f32:$src1, FR32:f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VMULSSrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable247\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable247, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable248[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FMUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::FR64RegClassID,
    // (fmul:f64 FR64:f64:$src1, FR64:f64:$src2)  =>  (VMULSDrr:f64 FR64:f64:$src1, FR64:f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VMULSDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable248\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable248, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable249[] = {
    GIM_CheckFeatures, GIFBS_UseSSE1,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FMUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::FR32RegClassID,
    // (fmul:f32 FR32:f32:$src1, FR32:f32:$src2)  =>  (MULSSrr:f32 FR32:f32:$src1, FR32:f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::MULSSrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable249\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable249, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable250[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FMUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::FR64RegClassID,
    // (fmul:f64 FR64:f64:$src1, FR64:f64:$src2)  =>  (MULSDrr:f64 FR64:f64:$src1, FR64:f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::MULSDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable250\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable250, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable251[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FMUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR32XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR32XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::FR32XRegClassID,
    // (fmul:f32 FR32X:f32:$src1, FR32X:f32:$src2)  =>  (VMULSSZrr:f32 FR32X:f32:$src1, FR32X:f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VMULSSZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable251\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable251, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable252[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FMUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR64XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR64XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::FR64XRegClassID,
    // (fmul:f64 FR64X:f64:$src1, FR64X:f64:$src2)  =>  (VMULSDZrr:f64 FR64X:f64:$src1, FR64X:f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VMULSDZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable252\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable252, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable253[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FMUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (fmul:v16f32 VR512:v16f32:$src1, VR512:v16f32:$src2)  =>  (VMULPSZrr:v16f32 VR512:v16f32:$src1, VR512:v16f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VMULPSZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable253\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable253, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable254[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FMUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (fmul:v8f64 VR512:v8f64:$src1, VR512:v8f64:$src2)  =>  (VMULPDZrr:v8f64 VR512:v8f64:$src1, VR512:v8f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VMULPDZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable254\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable254, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable255[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FMUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (fmul:v4f32 VR128X:v4f32:$src1, VR128X:v4f32:$src2)  =>  (VMULPSZ128rr:v4f32 VR128X:v4f32:$src1, VR128X:v4f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VMULPSZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable255\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable255, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable256[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FMUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (fmul:v8f32 VR256X:v8f32:$src1, VR256X:v8f32:$src2)  =>  (VMULPSZ256rr:v8f32 VR256X:v8f32:$src1, VR256X:v8f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VMULPSZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable256\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable256, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable257[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FMUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (fmul:v2f64 VR128X:v2f64:$src1, VR128X:v2f64:$src2)  =>  (VMULPDZ128rr:v2f64 VR128X:v2f64:$src1, VR128X:v2f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VMULPDZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable257\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable257, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable258[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FMUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (fmul:v4f64 VR256X:v4f64:$src1, VR256X:v4f64:$src2)  =>  (VMULPDZ256rr:v4f64 VR256X:v4f64:$src1, VR256X:v4f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VMULPDZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable258\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable258, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable259[] = {
    GIM_CheckFeatures, GIFBS_FPStackf32,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FSUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::RFP32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::RFP32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::RFP32RegClassID,
    // (fsub:f32 RFP32:f32:$src1, RFP32:f32:$src2)  =>  (SUB_Fp32:f32:i16 RFP32:f32:$src1, RFP32:f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::SUB_Fp32,
    GIR_AddImplicitDef, 0, X86::FPSW,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable259\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable259, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable260[] = {
    GIM_CheckFeatures, GIFBS_FPStackf64,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FSUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::RFP64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::RFP64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::RFP64RegClassID,
    // (fsub:f64 RFP64:f64:$src1, RFP64:f64:$src2)  =>  (SUB_Fp64:f64:i16 RFP64:f64:$src1, RFP64:f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::SUB_Fp64,
    GIR_AddImplicitDef, 0, X86::FPSW,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable260\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable260, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable261[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FSUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s80, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::RFP80RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s80, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::RFP80RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s80, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::RFP80RegClassID,
    // (fsub:f80 RFP80:f80:$src1, RFP80:f80:$src2)  =>  (SUB_Fp80:f80:i16 RFP80:f80:$src1, RFP80:f80:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::SUB_Fp80,
    GIR_AddImplicitDef, 0, X86::FPSW,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable261\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable261, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable262[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FSUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (fsub:v4f32 VR128:v4f32:$src1, VR128:v4f32:$src2)  =>  (VSUBPSrr:v4f32 VR128:v4f32:$src1, VR128:v4f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VSUBPSrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable262\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable262, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable263[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FSUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (fsub:v2f64 VR128:v2f64:$src1, VR128:v2f64:$src2)  =>  (VSUBPDrr:v2f64 VR128:v2f64:$src1, VR128:v2f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VSUBPDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable263\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable263, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable264[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FSUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (fsub:v8f32 VR256:v8f32:$src1, VR256:v8f32:$src2)  =>  (VSUBPSYrr:v8f32 VR256:v8f32:$src1, VR256:v8f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VSUBPSYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable264\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable264, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable265[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FSUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (fsub:v4f64 VR256:v4f64:$src1, VR256:v4f64:$src2)  =>  (VSUBPDYrr:v4f64 VR256:v4f64:$src1, VR256:v4f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VSUBPDYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable265\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable265, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable266[] = {
    GIM_CheckFeatures, GIFBS_UseSSE1,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FSUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (fsub:v4f32 VR128:v4f32:$src1, VR128:v4f32:$src2)  =>  (SUBPSrr:v4f32 VR128:v4f32:$src1, VR128:v4f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::SUBPSrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable266\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable266, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable267[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FSUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (fsub:v2f64 VR128:v2f64:$src1, VR128:v2f64:$src2)  =>  (SUBPDrr:v2f64 VR128:v2f64:$src1, VR128:v2f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::SUBPDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable267\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable267, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable268[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FSUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::FR32RegClassID,
    // (fsub:f32 FR32:f32:$src1, FR32:f32:$src2)  =>  (VSUBSSrr:f32 FR32:f32:$src1, FR32:f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VSUBSSrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable268\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable268, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable269[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FSUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::FR64RegClassID,
    // (fsub:f64 FR64:f64:$src1, FR64:f64:$src2)  =>  (VSUBSDrr:f64 FR64:f64:$src1, FR64:f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VSUBSDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable269\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable269, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable270[] = {
    GIM_CheckFeatures, GIFBS_UseSSE1,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FSUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::FR32RegClassID,
    // (fsub:f32 FR32:f32:$src1, FR32:f32:$src2)  =>  (SUBSSrr:f32 FR32:f32:$src1, FR32:f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::SUBSSrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable270\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable270, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable271[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FSUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::FR64RegClassID,
    // (fsub:f64 FR64:f64:$src1, FR64:f64:$src2)  =>  (SUBSDrr:f64 FR64:f64:$src1, FR64:f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::SUBSDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable271\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable271, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable272[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FSUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR32XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR32XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::FR32XRegClassID,
    // (fsub:f32 FR32X:f32:$src1, FR32X:f32:$src2)  =>  (VSUBSSZrr:f32 FR32X:f32:$src1, FR32X:f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VSUBSSZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable272\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable272, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable273[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FSUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR64XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR64XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::FR64XRegClassID,
    // (fsub:f64 FR64X:f64:$src1, FR64X:f64:$src2)  =>  (VSUBSDZrr:f64 FR64X:f64:$src1, FR64X:f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VSUBSDZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable273\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable273, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable274[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FSUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (fsub:v16f32 VR512:v16f32:$src1, VR512:v16f32:$src2)  =>  (VSUBPSZrr:v16f32 VR512:v16f32:$src1, VR512:v16f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VSUBPSZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable274\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable274, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable275[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FSUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (fsub:v8f64 VR512:v8f64:$src1, VR512:v8f64:$src2)  =>  (VSUBPDZrr:v8f64 VR512:v8f64:$src1, VR512:v8f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VSUBPDZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable275\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable275, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable276[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FSUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (fsub:v4f32 VR128X:v4f32:$src1, VR128X:v4f32:$src2)  =>  (VSUBPSZ128rr:v4f32 VR128X:v4f32:$src1, VR128X:v4f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VSUBPSZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable276\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable276, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable277[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FSUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (fsub:v8f32 VR256X:v8f32:$src1, VR256X:v8f32:$src2)  =>  (VSUBPSZ256rr:v8f32 VR256X:v8f32:$src1, VR256X:v8f32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VSUBPSZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable277\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable277, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable278[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FSUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (fsub:v2f64 VR128X:v2f64:$src1, VR128X:v2f64:$src2)  =>  (VSUBPDZ128rr:v2f64 VR128X:v2f64:$src1, VR128X:v2f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VSUBPDZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable278\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable278, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable279[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FSUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (fsub:v4f64 VR256X:v4f64:$src1, VR256X:v4f64:$src2)  =>  (VSUBPDZ256rr:v4f64 VR256X:v4f64:$src1, VR256X:v4f64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VSUBPDZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable279\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable279, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable280[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vphsubwd,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4i32 6074:iPTR, VR128:v8i16:$src)  =>  (VPHSUBWDrr:v4i32 VR128:v8i16:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPHSUBWDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable280\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable280, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable281[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vphsubdq,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2i64 6073:iPTR, VR128:v4i32:$src)  =>  (VPHSUBDQrr:v2i64 VR128:v4i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPHSUBDQrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable281\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable281, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable282[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vphsubbw,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v8i16 6072:iPTR, VR128:v16i8:$src)  =>  (VPHSUBBWrr:v8i16 VR128:v16i8:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPHSUBBWrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable282\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable282, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable283[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vphaddwq,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2i64 6071:iPTR, VR128:v8i16:$src)  =>  (VPHADDWQrr:v2i64 VR128:v8i16:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPHADDWQrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable283\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable283, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable284[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vphaddwd,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4i32 6070:iPTR, VR128:v8i16:$src)  =>  (VPHADDWDrr:v4i32 VR128:v8i16:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPHADDWDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable284\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable284, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable285[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vphadduwq,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2i64 6069:iPTR, VR128:v8i16:$src)  =>  (VPHADDUWQrr:v2i64 VR128:v8i16:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPHADDUWQrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable285\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable285, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable286[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vphadduwd,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4i32 6068:iPTR, VR128:v8i16:$src)  =>  (VPHADDUWDrr:v4i32 VR128:v8i16:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPHADDUWDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable286\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable286, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable287[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vphaddudq,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2i64 6067:iPTR, VR128:v4i32:$src)  =>  (VPHADDUDQrr:v2i64 VR128:v4i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPHADDUDQrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable287\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable287, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable288[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vphaddubw,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v8i16 6066:iPTR, VR128:v16i8:$src)  =>  (VPHADDUBWrr:v8i16 VR128:v16i8:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPHADDUBWrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable288\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable288, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable289[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vphaddubq,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2i64 6065:iPTR, VR128:v16i8:$src)  =>  (VPHADDUBQrr:v2i64 VR128:v16i8:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPHADDUBQrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable289\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable289, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable290[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vphaddubd,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4i32 6064:iPTR, VR128:v16i8:$src)  =>  (VPHADDUBDrr:v4i32 VR128:v16i8:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPHADDUBDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable290\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable290, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable291[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vphadddq,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2i64 6063:iPTR, VR128:v4i32:$src)  =>  (VPHADDDQrr:v2i64 VR128:v4i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPHADDDQrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable291\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable291, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable292[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vphaddbw,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v8i16 6062:iPTR, VR128:v16i8:$src)  =>  (VPHADDBWrr:v8i16 VR128:v16i8:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPHADDBWrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable292\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable292, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable293[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vphaddbq,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2i64 6061:iPTR, VR128:v16i8:$src)  =>  (VPHADDBQrr:v2i64 VR128:v16i8:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPHADDBQrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable293\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable293, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable294[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vphaddbd,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4i32 6060:iPTR, VR128:v16i8:$src)  =>  (VPHADDBDrr:v4i32 VR128:v16i8:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPHADDBDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable294\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable294, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable295[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vfrcz_ss,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4f32 6047:iPTR, VR128:v4f32:$src)  =>  (VFRCZSSrr:v4f32 VR128:v4f32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VFRCZSSrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable295\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable295, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable296[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vfrcz_ps,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4f32 6044:iPTR, VR128:v4f32:$src)  =>  (VFRCZPSrr:v4f32 VR128:v4f32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VFRCZPSrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable296\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable296, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable297[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vfrcz_ps_256,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (intrinsic_wo_chain:v8f32 6045:iPTR, VR256:v8f32:$src)  =>  (VFRCZPSrrY:v8f32 VR256:v8f32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VFRCZPSrrY,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable297\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable297, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable298[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vfrcz_sd,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2f64 6046:iPTR, VR128:v2f64:$src)  =>  (VFRCZSDrr:v2f64 VR128:v2f64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VFRCZSDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable298\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable298, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable299[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vfrcz_pd,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2f64 6042:iPTR, VR128:v2f64:$src)  =>  (VFRCZPDrr:v2f64 VR128:v2f64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VFRCZPDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable299\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable299, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable300[] = {
    GIM_CheckFeatures, GIFBS_HasXOP,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_xop_vfrcz_pd_256,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (intrinsic_wo_chain:v4f64 6043:iPTR, VR256:v4f64:$src)  =>  (VFRCZPDrrY:v4f64 VR256:v4f64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VFRCZPDrrY,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable300\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable300, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable301[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_cvtsd2si,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:i32 5885:iPTR, VR128:v2f64:$src)  =>  (VCVTSD2SIrr:i32 VR128:v2f64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VCVTSD2SIrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable301\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable301, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable302[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_cvtsd2si64,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:i64 5886:iPTR, VR128:v2f64:$src)  =>  (VCVTSD2SI64rr:i64 VR128:v2f64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VCVTSD2SI64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable302\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable302, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable303[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_cvtsd2si,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:i32 5885:iPTR, VR128:v2f64:$src)  =>  (CVTSD2SIrr:i32 VR128:v2f64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::CVTSD2SIrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable303\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable303, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable304[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_cvtsd2si64,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:i64 5886:iPTR, VR128:v2f64:$src)  =>  (CVTSD2SI64rr:i64 VR128:v2f64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::CVTSD2SI64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable304\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable304, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable305[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse_cvttss2si,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:i32 5849:iPTR, VR128:v4f32:$src)  =>  (Int_VCVTTSS2SIrr:i32 VR128:v4f32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::Int_VCVTTSS2SIrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable305\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable305, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable306[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse_cvttss2si64,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:i64 5850:iPTR, VR128:v4f32:$src)  =>  (Int_VCVTTSS2SI64rr:i64 VR128:v4f32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::Int_VCVTTSS2SI64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable306\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable306, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable307[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_cvttsd2si,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:i32 5893:iPTR, VR128:v2f64:$src)  =>  (Int_VCVTTSD2SIrr:i32 VR128:v2f64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::Int_VCVTTSD2SIrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable307\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable307, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable308[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_cvttsd2si64,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:i64 5894:iPTR, VR128:v2f64:$src)  =>  (Int_VCVTTSD2SI64rr:i64 VR128:v2f64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::Int_VCVTTSD2SI64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable308\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable308, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable309[] = {
    GIM_CheckFeatures, GIFBS_UseSSE1,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse_cvttss2si,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:i32 5849:iPTR, VR128:v4f32:$src)  =>  (Int_CVTTSS2SIrr:i32 VR128:v4f32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::Int_CVTTSS2SIrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable309\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable309, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable310[] = {
    GIM_CheckFeatures, GIFBS_UseSSE1,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse_cvttss2si64,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:i64 5850:iPTR, VR128:v4f32:$src)  =>  (Int_CVTTSS2SI64rr:i64 VR128:v4f32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::Int_CVTTSS2SI64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable310\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable310, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable311[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_cvttsd2si,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:i32 5893:iPTR, VR128:v2f64:$src)  =>  (Int_CVTTSD2SIrr:i32 VR128:v2f64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::Int_CVTTSD2SIrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable311\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable311, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable312[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_cvttsd2si64,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:i64 5894:iPTR, VR128:v2f64:$src)  =>  (Int_CVTTSD2SI64rr:i64 VR128:v2f64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::Int_CVTTSD2SI64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable312\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable312, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable313[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse_cvtss2si,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:i32 5845:iPTR, VR128:v4f32:$src)  =>  (VCVTSS2SIrr:i32 VR128:v4f32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VCVTSS2SIrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable313\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable313, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable314[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse_cvtss2si64,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:i64 5846:iPTR, VR128:v4f32:$src)  =>  (VCVTSS2SI64rr:i64 VR128:v4f32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VCVTSS2SI64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable314\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable314, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable315[] = {
    GIM_CheckFeatures, GIFBS_UseSSE1,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse_cvtss2si,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:i32 5845:iPTR, VR128:v4f32:$src)  =>  (CVTSS2SIrr:i32 VR128:v4f32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::CVTSS2SIrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable315\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable315, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable316[] = {
    GIM_CheckFeatures, GIFBS_UseSSE1,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse_cvtss2si64,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:i64 5846:iPTR, VR128:v4f32:$src)  =>  (CVTSS2SI64rr:i64 VR128:v4f32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::CVTSS2SI64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable316\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable316, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable317[] = {
    GIM_CheckFeatures, GIFBS_HasAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_cvtps2dq,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4i32 5884:iPTR, VR128:v4f32:$src)  =>  (VCVTPS2DQrr:v4i32 VR128:v4f32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VCVTPS2DQrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable317\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable317, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable318[] = {
    GIM_CheckFeatures, GIFBS_HasAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_avx_cvt_ps2dq_256,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (intrinsic_wo_chain:v8i32 4671:iPTR, VR256:v8f32:$src)  =>  (VCVTPS2DQYrr:v8i32 VR256:v8f32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VCVTPS2DQYrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable318\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable318, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable319[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_cvtps2dq,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4i32 5884:iPTR, VR128:v4f32:$src)  =>  (CVTPS2DQrr:v4i32 VR128:v4f32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::CVTPS2DQrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable319\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable319, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable320[] = {
    GIM_CheckFeatures, GIFBS_HasAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse41_phminposuw,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v8i16 5964:iPTR, VR128:v8i16:$src)  =>  (VPHMINPOSUWrr128:v8i16 VR128:v8i16:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPHMINPOSUWrr128,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable320\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable320, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable321[] = {
    GIM_CheckFeatures, GIFBS_UseSSE41,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse41_phminposuw,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v8i16 5964:iPTR, VR128:v8i16:$src)  =>  (PHMINPOSUWrr128:v8i16 VR128:v8i16:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::PHMINPOSUWrr128,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable321\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable321, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable322[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_HasAES,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_aesni_aesimc,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2i64 4661:iPTR, VR128:v2i64:$src1)  =>  (VAESIMCrr:v2i64 VR128:v2i64:$src1)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VAESIMCrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable322\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable322, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable323[] = {
    GIM_CheckFeatures, GIFBS_HasAES,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_aesni_aesimc,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2i64 4661:iPTR, VR128:v2i64:$src1)  =>  (AESIMCrr:v2i64 VR128:v2i64:$src1)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::AESIMCrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src1
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable323\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable323, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable324[] = {
    GIM_CheckFeatures, GIFBS_HasF16C,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_vcvtph2ps_128,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4f32 6029:iPTR, VR128:v8i16:$src)  =>  (VCVTPH2PSrr:v4f32 VR128:v8i16:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VCVTPH2PSrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable324\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable324, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable325[] = {
    GIM_CheckFeatures, GIFBS_HasF16C,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_vcvtph2ps_256,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v8f32 6030:iPTR, VR128:v8i16:$src)  =>  (VCVTPH2PSYrr:v8f32 VR128:v8i16:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VCVTPH2PSYrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable325\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable325, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable326[] = {
    GIM_CheckFeatures, GIFBS_UseSSE1,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse_rcp_ss,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4f32 5859:iPTR, VR128:v4f32:$src)  =>  (RCPSSr_Int:v4f32 VR128:v4f32:$src, VR128:v4f32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::RCPSSr_Int,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable326\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable326, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable327[] = {
    GIM_CheckFeatures, GIFBS_UseSSE1,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse_rsqrt_ss,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4f32 5861:iPTR, VR128:v4f32:$src)  =>  (RSQRTSSr_Int:v4f32 VR128:v4f32:$src, VR128:v4f32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::RSQRTSSr_Int,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable327\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable327, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable328[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_sqrt_sd,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2f64 5940:iPTR, VR128:v2f64:$src)  =>  (SQRTSDr_Int:v2f64 VR128:v2f64:$src, VR128:v2f64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::SQRTSDr_Int,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable328\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable328, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable329[] = {
    GIM_CheckFeatures, GIFBS_UseSSE1,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse_sqrt_ss,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4f32 5864:iPTR, VR128:v4f32:$src)  =>  (SQRTSSr_Int:v4f32 VR128:v4f32:$src, VR128:v4f32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::SQRTSSr_Int,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable329\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable329, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable330[] = {
    GIM_CheckFeatures, GIFBS_HasAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse_rcp_ss,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4f32 5859:iPTR, VR128:v4f32:$src)  =>  (VRCPSSr_Int:v4f32 VR128:v4f32:$src, VR128:v4f32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VRCPSSr_Int,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable330\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable330, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable331[] = {
    GIM_CheckFeatures, GIFBS_HasAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse_rsqrt_ss,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4f32 5861:iPTR, VR128:v4f32:$src)  =>  (VRSQRTSSr_Int:v4f32 VR128:v4f32:$src, VR128:v4f32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VRSQRTSSr_Int,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable331\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable331, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable332[] = {
    GIM_CheckFeatures, GIFBS_HasAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_sqrt_sd,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v2f64 5940:iPTR, VR128:v2f64:$src)  =>  (VSQRTSDr_Int:v2f64 VR128:v2f64:$src, VR128:v2f64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VSQRTSDr_Int,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable332\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable332, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable333[] = {
    GIM_CheckFeatures, GIFBS_HasAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse_sqrt_ss,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (intrinsic_wo_chain:v4f32 5864:iPTR, VR128:v4f32:$src)  =>  (VSQRTSSr_Int:v4f32 VR128:v4f32:$src, VR128:v4f32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VSQRTSSr_Int,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable333\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable333, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable334[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse_cvtss2si,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (intrinsic_wo_chain:i32 5845:iPTR, VR128X:v4f32:$src)  =>  (VCVTSS2SIZrr:i32 VR128X:v4f32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VCVTSS2SIZrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable334\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable334, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable335[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse_cvtss2si64,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (intrinsic_wo_chain:i64 5846:iPTR, VR128X:v4f32:$src)  =>  (VCVTSS2SI64Zrr:i64 VR128X:v4f32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VCVTSS2SI64Zrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable335\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable335, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable336[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_cvtsd2si,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (intrinsic_wo_chain:i32 5885:iPTR, VR128X:v2f64:$src)  =>  (VCVTSD2SIZrr:i32 VR128X:v2f64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VCVTSD2SIZrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable336\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable336, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable337[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_cvtsd2si64,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (intrinsic_wo_chain:i64 5886:iPTR, VR128X:v2f64:$src)  =>  (VCVTSD2SI64Zrr:i64 VR128X:v2f64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VCVTSD2SI64Zrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable337\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable337, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable338[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse_cvttss2si,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (intrinsic_wo_chain:i32 5849:iPTR, VR128X:v4f32:$src)  =>  (VCVTTSS2SIZrr_Int:i32 VR128X:v4f32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VCVTTSS2SIZrr_Int,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable338\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable338, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable339[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse_cvttss2si64,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (intrinsic_wo_chain:i64 5850:iPTR, VR128X:v4f32:$src)  =>  (VCVTTSS2SI64Zrr_Int:i64 VR128X:v4f32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VCVTTSS2SI64Zrr_Int,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable339\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable339, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable340[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_cvttsd2si,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (intrinsic_wo_chain:i32 5893:iPTR, VR128X:v2f64:$src)  =>  (VCVTTSD2SIZrr_Int:i32 VR128X:v2f64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VCVTTSD2SIZrr_Int,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable340\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable340, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable341[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_INTRINSIC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckIntrinsicID, /*MI*/0, /*Op*/1, Intrinsic::x86_sse2_cvttsd2si64,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (intrinsic_wo_chain:i64 5894:iPTR, VR128X:v2f64:$src)  =>  (VCVTTSD2SI64Zrr_Int:i64 VR128X:v2f64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VCVTTSD2SI64Zrr_Int,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable341\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable341, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable342[] = {
    GIM_CheckFeatures, GIFBS_HasBMI2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/1, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/3, /*MI*/2, /*OpIdx*/1, // MIs[3]
    GIM_CheckNumOperands, /*MI*/3, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/4, /*MI*/0, /*OpIdx*/2, // MIs[4]
    GIM_CheckNumOperands, /*MI*/4, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/5, /*MI*/4, /*OpIdx*/1, // MIs[5]
    GIM_CheckNumOperands, /*MI*/5, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_LSHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_SHL,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s8, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_TRUNC,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_s8, 
    // MIs[2] Operand 1
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/3, TargetOpcode::G_SUB,
    // MIs[3] Operand 0
    GIM_CheckType, /*MI*/3, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[3] Operand 1
    GIM_CheckType, /*MI*/3, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/3, /*Op*/1, 32,
    // MIs[3] lz
    GIM_CheckType, /*MI*/3, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/3, /*Op*/2, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s8, 
    GIM_CheckOpcode, /*MI*/4, TargetOpcode::G_TRUNC,
    // MIs[4] Operand 0
    GIM_CheckType, /*MI*/4, /*Op*/0, /*Type*/GILLT_s8, 
    // MIs[4] Operand 1
    GIM_CheckType, /*MI*/4, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/5, TargetOpcode::G_SUB,
    // MIs[5] Operand 0
    GIM_CheckType, /*MI*/5, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[5] Operand 1
    GIM_CheckType, /*MI*/5, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/5, /*Op*/1, 32,
    // MIs[5] lz
    GIM_CheckType, /*MI*/5, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/5, /*Op*/2, /*RC*/X86::GR32RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    GIM_CheckIsSafeToFold, /*InsnID*/3,
    GIM_CheckIsSafeToFold, /*InsnID*/4,
    GIM_CheckIsSafeToFold, /*InsnID*/5,
    // (srl:i32 (shl:i32 GR32:i32:$src, (trunc:i8 (sub:i32 32:i32, GR32:i32:$lz))), (trunc:i8 (sub:i32 32:i32, GR32:i32:$lz)))  =>  (BZHI32rr:i32:i32 GR32:i32:$src, GR32:i32:$lz)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BZHI32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/3, /*OpIdx*/2, // lz
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable342\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable342, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable343[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_LSHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR8RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR8RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s8, 
    GIM_CheckConstantInt, /*MI*/0, /*Op*/2, 1,
    // (srl:i8 GR8:i8:$src1, 1:i8)  =>  (SHR8r1:i8:i32 GR8:i8:$src1)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::SHR8r1,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src1
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable343\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable343, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable344[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_LSHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR16RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR16RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s8, 
    GIM_CheckConstantInt, /*MI*/0, /*Op*/2, 1,
    // (srl:i16 GR16:i16:$src1, 1:i8)  =>  (SHR16r1:i16:i32 GR16:i16:$src1)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::SHR16r1,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src1
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable344\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable344, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable345[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_LSHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s8, 
    GIM_CheckConstantInt, /*MI*/0, /*Op*/2, 1,
    // (srl:i32 GR32:i32:$src1, 1:i8)  =>  (SHR32r1:i32:i32 GR32:i32:$src1)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::SHR32r1,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src1
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable345\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable345, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable346[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_LSHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s8, 
    GIM_CheckConstantInt, /*MI*/0, /*Op*/2, 1,
    // (srl:i64 GR64:i64:$src1, 1:i8)  =>  (SHR64r1:i64:i32 GR64:i64:$src1)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::SHR64r1,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src1
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable346\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable346, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable347[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_LSHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (srl:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2)  =>  (VPSRLVDrr:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSRLVDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable347\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable347, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable348[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_LSHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (srl:v8i32 VR256:v8i32:$src1, VR256:v8i32:$src2)  =>  (VPSRLVDYrr:v8i32 VR256:v8i32:$src1, VR256:v8i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSRLVDYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable348\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable348, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable349[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_LSHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (srl:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)  =>  (VPSRLVQrr:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSRLVQrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable349\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable349, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable350[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_LSHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (srl:v4i64 VR256:v4i64:$src1, VR256:v4i64:$src2)  =>  (VPSRLVQYrr:v4i64 VR256:v4i64:$src1, VR256:v4i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSRLVQYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable350\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable350, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable351[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_LSHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (srl:v16i32 VR512:v16i32:$src1, VR512:v16i32:$src2)  =>  (VPSRLVDZrr:v16i32 VR512:v16i32:$src1, VR512:v16i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSRLVDZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable351\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable351, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable352[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_LSHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (srl:v8i32 VR256X:v8i32:$src1, VR256X:v8i32:$src2)  =>  (VPSRLVDZ256rr:v8i32 VR256X:v8i32:$src1, VR256X:v8i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSRLVDZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable352\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable352, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable353[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_LSHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (srl:v4i32 VR128X:v4i32:$src1, VR128X:v4i32:$src2)  =>  (VPSRLVDZ128rr:v4i32 VR128X:v4i32:$src1, VR128X:v4i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSRLVDZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable353\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable353, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable354[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_LSHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (srl:v8i64 VR512:v8i64:$src1, VR512:v8i64:$src2)  =>  (VPSRLVQZrr:v8i64 VR512:v8i64:$src1, VR512:v8i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSRLVQZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable354\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable354, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable355[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_LSHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (srl:v4i64 VR256X:v4i64:$src1, VR256X:v4i64:$src2)  =>  (VPSRLVQZ256rr:v4i64 VR256X:v4i64:$src1, VR256X:v4i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSRLVQZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable355\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable355, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable356[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_LSHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (srl:v2i64 VR128X:v2i64:$src1, VR128X:v2i64:$src2)  =>  (VPSRLVQZ128rr:v2i64 VR128X:v2i64:$src1, VR128X:v2i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSRLVQZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable356\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable356, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable357[] = {
    GIM_CheckFeatures, GIFBS_HasBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_LSHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v32s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v32s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v32s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (srl:v32i16 VR512:v32i16:$src1, VR512:v32i16:$src2)  =>  (VPSRLVWZrr:v32i16 VR512:v32i16:$src1, VR512:v32i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSRLVWZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable357\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable357, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable358[] = {
    GIM_CheckFeatures, GIFBS_HasVLX_HasBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_LSHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (srl:v16i16 VR256X:v16i16:$src1, VR256X:v16i16:$src2)  =>  (VPSRLVWZ256rr:v16i16 VR256X:v16i16:$src1, VR256X:v16i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSRLVWZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable358\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable358, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable359[] = {
    GIM_CheckFeatures, GIFBS_HasVLX_HasBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_LSHR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (srl:v8i16 VR128X:v8i16:$src1, VR128X:v8i16:$src2)  =>  (VPSRLVWZ128rr:v8i16 VR128X:v8i16:$src1, VR128X:v8i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSRLVWZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable359\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable359, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable360[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX_Or_NoBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_MUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (mul:v8i16 VR128:v8i16:$src1, VR128:v8i16:$src2)  =>  (VPMULLWrr:v8i16 VR128:v8i16:$src1, VR128:v8i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPMULLWrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable360\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable360, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable361[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_MUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (mul:v8i16 VR128:v8i16:$src1, VR128:v8i16:$src2)  =>  (PMULLWrr:v8i16 VR128:v8i16:$src1, VR128:v8i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::PMULLWrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable361\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable361, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable362[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2_NoVLX_Or_NoBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_MUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (mul:v16i16 VR256:v16i16:$src1, VR256:v16i16:$src2)  =>  (VPMULLWYrr:v16i16 VR256:v16i16:$src1, VR256:v16i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPMULLWYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable362\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable362, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable363[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_MUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (mul:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2)  =>  (VPMULLDrr:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPMULLDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable363\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable363, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable364[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_MUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (mul:v8i32 VR256:v8i32:$src1, VR256:v8i32:$src2)  =>  (VPMULLDYrr:v8i32 VR256:v8i32:$src1, VR256:v8i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPMULLDYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable364\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable364, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable365[] = {
    GIM_CheckFeatures, GIFBS_UseSSE41,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_MUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (mul:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2)  =>  (PMULLDrr:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::PMULLDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable365\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable365, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable366[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_MUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (mul:v16i32 VR512:v16i32:$src1, VR512:v16i32:$src2)  =>  (VPMULLDZrr:v16i32 VR512:v16i32:$src1, VR512:v16i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPMULLDZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable366\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable366, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable367[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_MUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (mul:v8i32 VR256X:v8i32:$src1, VR256X:v8i32:$src2)  =>  (VPMULLDZ256rr:v8i32 VR256X:v8i32:$src1, VR256X:v8i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPMULLDZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable367\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable367, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable368[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_MUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (mul:v4i32 VR128X:v4i32:$src1, VR128X:v4i32:$src2)  =>  (VPMULLDZ128rr:v4i32 VR128X:v4i32:$src1, VR128X:v4i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPMULLDZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable368\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable368, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable369[] = {
    GIM_CheckFeatures, GIFBS_HasBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_MUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v32s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v32s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v32s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (mul:v32i16 VR512:v32i16:$src1, VR512:v32i16:$src2)  =>  (VPMULLWZrr:v32i16 VR512:v32i16:$src1, VR512:v32i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPMULLWZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable369\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable369, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable370[] = {
    GIM_CheckFeatures, GIFBS_HasBWI_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_MUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (mul:v16i16 VR256X:v16i16:$src1, VR256X:v16i16:$src2)  =>  (VPMULLWZ256rr:v16i16 VR256X:v16i16:$src1, VR256X:v16i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPMULLWZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable370\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable370, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable371[] = {
    GIM_CheckFeatures, GIFBS_HasBWI_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_MUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (mul:v8i16 VR128X:v8i16:$src1, VR128X:v8i16:$src2)  =>  (VPMULLWZ128rr:v8i16 VR128X:v8i16:$src1, VR128X:v8i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPMULLWZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable371\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable371, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable372[] = {
    GIM_CheckFeatures, GIFBS_HasDQI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_MUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (mul:v8i64 VR512:v8i64:$src1, VR512:v8i64:$src2)  =>  (VPMULLQZrr:v8i64 VR512:v8i64:$src1, VR512:v8i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPMULLQZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable372\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable372, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable373[] = {
    GIM_CheckFeatures, GIFBS_HasDQI_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_MUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (mul:v4i64 VR256X:v4i64:$src1, VR256X:v4i64:$src2)  =>  (VPMULLQZ256rr:v4i64 VR256X:v4i64:$src1, VR256X:v4i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPMULLQZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable373\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable373, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable374[] = {
    GIM_CheckFeatures, GIFBS_HasDQI_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_MUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (mul:v2i64 VR128X:v2i64:$src1, VR128X:v2i64:$src2)  =>  (VPMULLQZ128rr:v2i64 VR128X:v2i64:$src1, VR128X:v2i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPMULLQZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable374\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable374, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable375[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_MUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR16RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR16RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR16RegClassID,
    // (mul:i16 GR16:i16:$src1, GR16:i16:$src2)  =>  (IMUL16rr:i16:i32 GR16:i16:$src1, GR16:i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::IMUL16rr,
    GIR_AddImplicitDef, 0, X86::EFLAGS,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable375\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable375, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable376[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_MUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR32RegClassID,
    // (mul:i32 GR32:i32:$src1, GR32:i32:$src2)  =>  (IMUL32rr:i32:i32 GR32:i32:$src1, GR32:i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::IMUL32rr,
    GIR_AddImplicitDef, 0, X86::EFLAGS,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable376\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable376, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable377[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_MUL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR64RegClassID,
    // (mul:i64 GR64:i64:$src1, GR64:i64:$src2)  =>  (IMUL64rr:i64:i32 GR64:i64:$src1, GR64:i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::IMUL64rr,
    GIR_AddImplicitDef, 0, X86::EFLAGS,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable377\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable377, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable378[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v4s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v4s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR256RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (or:v4i64 (bitconvert:v4i64 VR256:v8f32:$src1), (bitconvert:v4i64 VR256:v8f32:$src2))  =>  (VORPSYrr:v4i64 VR256:v8f32:$src1, VR256:v8f32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VORPSYrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable378\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable378, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable379[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v4s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v4s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR256RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (or:v4i64 (bitconvert:v4i64 VR256:v4f64:$src1), (bitconvert:v4i64 VR256:v4f64:$src2))  =>  (VORPDYrr:v4i64 VR256:v4f64:$src1, VR256:v4f64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VORPDYrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable379\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable379, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable380[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR128RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (or:v2i64 (bitconvert:v2i64 VR128:v4f32:$src1), (bitconvert:v2i64 VR128:v4f32:$src2))  =>  (VORPSrr:v2i64 VR128:v4f32:$src1, VR128:v4f32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VORPSrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable380\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable380, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable381[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR128RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (or:v2i64 (bitconvert:v2i64 VR128:v2f64:$src1), (bitconvert:v2i64 VR128:v2f64:$src2))  =>  (VORPDrr:v2i64 VR128:v2f64:$src1, VR128:v2f64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VORPDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable381\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable381, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable382[] = {
    GIM_CheckFeatures, GIFBS_UseSSE1,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR128RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (or:v2i64 (bitconvert:v2i64 VR128:v4f32:$src1), (bitconvert:v2i64 VR128:v4f32:$src2))  =>  (ORPSrr:v2i64 VR128:v4f32:$src1, VR128:v4f32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::ORPSrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable382\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable382, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable383[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR128RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (or:v2i64 (bitconvert:v2i64 VR128:v2f64:$src1), (bitconvert:v2i64 VR128:v2f64:$src2))  =>  (ORPDrr:v2i64 VR128:v2f64:$src1, VR128:v2f64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::ORPDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable383\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable383, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable384[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v8s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v8s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR512RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (or:v8i64 (bitconvert:v8i64 VR512:v16i32:$src1), (bitconvert:v8i64 VR512:v16i32:$src2))  =>  (VPORDZrr:v8i64 VR512:v16i32:$src1, VR512:v16i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPORDZrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable384\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable384, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable385[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v4s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v4s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (or:v4i64 (bitconvert:v4i64 VR256X:v8i32:$src1), (bitconvert:v4i64 VR256X:v8i32:$src2))  =>  (VPORDZ256rr:v4i64 VR256X:v8i32:$src1, VR256X:v8i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPORDZ256rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable385\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable385, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable386[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (or:v2i64 (bitconvert:v2i64 VR128X:v4i32:$src1), (bitconvert:v2i64 VR128X:v4i32:$src2))  =>  (VPORDZ128rr:v2i64 VR128X:v4i32:$src1, VR128X:v4i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPORDZ128rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable386\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable386, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable387[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_XOR,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_ADD,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[2] src
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[2] Operand 2
    GIM_CheckType, /*MI*/2, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/2, /*Op*/2, -1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (or:i32 (xor:i32 GR32:i32:$src, -1:i32), (add:i32 GR32:i32:$src, -1:i32))  =>  (BLSIC32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLSIC32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable387\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable387, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable388[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_XOR,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_ADD,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[2] src
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[2] Operand 2
    GIM_CheckType, /*MI*/2, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/2, /*Op*/2, -1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (or:i64 (xor:i64 GR64:i64:$src, -1:i64), (add:i64 GR64:i64:$src, -1:i64))  =>  (BLSIC64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLSIC64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable388\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable388, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable389[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_XOR,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_ADD,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[2] src
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[2] Operand 2
    GIM_CheckType, /*MI*/2, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/2, /*Op*/2, 1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (or:i32 (xor:i32 GR32:i32:$src, -1:i32), (add:i32 GR32:i32:$src, 1:i32))  =>  (T1MSKC32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::T1MSKC32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable389\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable389, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable390[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_XOR,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_ADD,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[2] src
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[2] Operand 2
    GIM_CheckType, /*MI*/2, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/2, /*Op*/2, 1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (or:i64 (xor:i64 GR64:i64:$src, -1:i64), (add:i64 GR64:i64:$src, 1:i64))  =>  (T1MSKC64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::T1MSKC64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable390\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable390, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable391[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_XOR,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[2] src
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[2] Operand 2
    GIM_CheckType, /*MI*/2, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/2, /*Op*/2, -1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (or:i32 (add:i32 GR32:i32:$src, -1:i32), (xor:i32 GR32:i32:$src, -1:i32))  =>  (BLSIC32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLSIC32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable391\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable391, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable392[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_XOR,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[2] src
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[2] Operand 2
    GIM_CheckType, /*MI*/2, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/2, /*Op*/2, -1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (or:i64 (add:i64 GR64:i64:$src, -1:i64), (xor:i64 GR64:i64:$src, -1:i64))  =>  (BLSIC64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLSIC64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable392\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable392, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable393[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, 1,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_XOR,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[2] src
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[2] Operand 2
    GIM_CheckType, /*MI*/2, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/2, /*Op*/2, -1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (or:i32 (add:i32 GR32:i32:$src, 1:i32), (xor:i32 GR32:i32:$src, -1:i32))  =>  (T1MSKC32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::T1MSKC32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable393\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable393, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable394[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, 1,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_XOR,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[2] src
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[2] Operand 2
    GIM_CheckType, /*MI*/2, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/2, /*Op*/2, -1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (or:i64 (add:i64 GR64:i64:$src, 1:i64), (xor:i64 GR64:i64:$src, -1:i64))  =>  (T1MSKC64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::T1MSKC64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable394\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable394, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable395[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/1, /*OpIdx*/1, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_XOR,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] Operand 1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_ADD,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[2] src
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[2] Operand 2
    GIM_CheckType, /*MI*/2, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/2, /*Op*/2, 1,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR32RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (or:i32 (xor:i32 (add:i32 GR32:i32:$src, 1:i32), -1:i32), GR32:i32:$src)  =>  (BLCI32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLCI32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable395\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable395, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable396[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/1, /*OpIdx*/1, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_XOR,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] Operand 1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_ADD,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[2] src
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[2] Operand 2
    GIM_CheckType, /*MI*/2, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/2, /*Op*/2, 1,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR64RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (or:i64 (xor:i64 (add:i64 GR64:i64:$src, 1:i64), -1:i64), GR64:i64:$src)  =>  (BLCI64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLCI64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable396\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable396, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable397[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_SUB,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] Operand 1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/1, -2,
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/2, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR32RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (or:i32 (sub:i32 -2:i32, GR32:i32:$src), GR32:i32:$src)  =>  (BLCI32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLCI32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable397\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable397, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable398[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_SUB,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] Operand 1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/1, -2,
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/2, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR64RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (or:i64 (sub:i64 -2:i64, GR64:i64:$src), GR64:i64:$src)  =>  (BLCI64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLCI64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/2, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable398\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable398, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable399[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, 1,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR32RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (or:i32 (add:i32 GR32:i32:$src, 1:i32), GR32:i32:$src)  =>  (BLCS32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLCS32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable399\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable399, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable400[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, 1,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR64RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (or:i64 (add:i64 GR64:i64:$src, 1:i64), GR64:i64:$src)  =>  (BLCS64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLCS64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable400\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable400, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable401[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR32RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (or:i32 (add:i32 GR32:i32:$src, -1:i32), GR32:i32:$src)  =>  (BLSFILL32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLSFILL32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable401\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable401, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable402[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR64RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (or:i64 (add:i64 GR64:i64:$src, -1:i64), GR64:i64:$src)  =>  (BLSFILL64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLSFILL64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable402\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable402, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable403[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/2, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/1, /*OpIdx*/1, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_XOR,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] Operand 1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_ADD,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[2] src
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[2] Operand 2
    GIM_CheckType, /*MI*/2, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/2, /*Op*/2, 1,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (or:i32 GR32:i32:$src, (xor:i32 (add:i32 GR32:i32:$src, 1:i32), -1:i32))  =>  (BLCI32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLCI32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable403\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable403, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable404[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/2, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/1, /*OpIdx*/1, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_XOR,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] Operand 1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_ADD,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[2] src
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[2] Operand 2
    GIM_CheckType, /*MI*/2, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/2, /*Op*/2, 1,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (or:i64 GR64:i64:$src, (xor:i64 (add:i64 GR64:i64:$src, 1:i64), -1:i64))  =>  (BLCI64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLCI64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable404\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable404, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable405[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/2, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_SUB,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] Operand 1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/1, -2,
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/2, /*RC*/X86::GR32RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (or:i32 GR32:i32:$src, (sub:i32 -2:i32, GR32:i32:$src))  =>  (BLCI32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLCI32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable405\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable405, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable406[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/2, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_SUB,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] Operand 1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/1, -2,
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/2, /*RC*/X86::GR64RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (or:i64 GR64:i64:$src, (sub:i64 -2:i64, GR64:i64:$src))  =>  (BLCI64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLCI64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable406\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable406, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable407[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/2, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, 1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (or:i32 GR32:i32:$src, (add:i32 GR32:i32:$src, 1:i32))  =>  (BLCS32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLCS32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable407\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable407, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable408[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/2, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, 1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (or:i64 GR64:i64:$src, (add:i64 GR64:i64:$src, 1:i64))  =>  (BLCS64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLCS64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable408\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable408, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable409[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/2, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (or:i32 GR32:i32:$src, (add:i32 GR32:i32:$src, -1:i32))  =>  (BLSFILL32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLSFILL32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable409\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable409, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable410[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/2, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (or:i64 GR64:i64:$src, (add:i64 GR64:i64:$src, -1:i64))  =>  (BLSFILL64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLSFILL64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable410\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable410, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable411[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (or:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)  =>  (VPORrr:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPORrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable411\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable411, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable412[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (or:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)  =>  (PORrr:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::PORrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable412\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable412, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable413[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (or:v4i64 VR256:v4i64:$src1, VR256:v4i64:$src2)  =>  (VPORYrr:v4i64 VR256:v4i64:$src1, VR256:v4i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPORYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable413\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable413, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable414[] = {
    GIM_CheckFeatures, GIFBS_HasDQI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VK8RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VK8RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VK8RegClassID,
    // (or:v8i1 VK8:v8i1:$src1, VK8:v8i1:$src2)  =>  (KORBrr:v8i1 VK8:v8i1:$src1, VK8:v8i1:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::KORBrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable414\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable414, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable415[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VK16RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VK16RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VK16RegClassID,
    // (or:v16i1 VK16:v16i1:$src1, VK16:v16i1:$src2)  =>  (KORWrr:v16i1 VK16:v16i1:$src1, VK16:v16i1:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::KORWrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable415\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable415, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable416[] = {
    GIM_CheckFeatures, GIFBS_HasBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v32s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VK32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v32s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VK32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v32s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VK32RegClassID,
    // (or:v32i1 VK32:v32i1:$src1, VK32:v32i1:$src2)  =>  (KORDrr:v32i1 VK32:v32i1:$src1, VK32:v32i1:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::KORDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable416\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable416, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable417[] = {
    GIM_CheckFeatures, GIFBS_HasBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v64s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VK64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v64s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VK64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v64s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VK64RegClassID,
    // (or:v64i1 VK64:v64i1:$src1, VK64:v64i1:$src2)  =>  (KORQrr:v64i1 VK64:v64i1:$src1, VK64:v64i1:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::KORQrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable417\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable417, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable418[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (or:v8i64 VR512:v8i64:$src1, VR512:v8i64:$src2)  =>  (VPORQZrr:v8i64 VR512:v8i64:$src1, VR512:v8i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPORQZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable418\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable418, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable419[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (or:v4i64 VR256X:v4i64:$src1, VR256X:v4i64:$src2)  =>  (VPORQZ256rr:v4i64 VR256X:v4i64:$src1, VR256X:v4i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPORQZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable419\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable419, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable420[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (or:v2i64 VR128X:v2i64:$src1, VR128X:v2i64:$src2)  =>  (VPORQZ128rr:v2i64 VR128X:v2i64:$src1, VR128X:v2i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPORQZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable420\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable420, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable421[] = {
    GIM_CheckFeatures, GIFBS_HasAVX1Only,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (or:v4i64 VR256:v4i64:$src1, VR256:v4i64:$src2)  =>  (VORPSYrr:v4i64 VR256:v4i64:$src1, VR256:v4i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VORPSYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable421\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable421, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable422[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR8RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR8RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR8RegClassID,
    // (or:i8 GR8:i8:$src1, GR8:i8:$src2)  =>  (OR8rr:i8:i32 GR8:i8:$src1, GR8:i8:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::OR8rr,
    GIR_AddImplicitDef, 0, X86::EFLAGS,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable422\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable422, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable423[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR16RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR16RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR16RegClassID,
    // (or:i16 GR16:i16:$src1, GR16:i16:$src2)  =>  (OR16rr:i16:i32 GR16:i16:$src1, GR16:i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::OR16rr,
    GIR_AddImplicitDef, 0, X86::EFLAGS,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable423\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable423, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable424[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR32RegClassID,
    // (or:i32 GR32:i32:$src1, GR32:i32:$src2)  =>  (OR32rr:i32:i32 GR32:i32:$src1, GR32:i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::OR32rr,
    GIR_AddImplicitDef, 0, X86::EFLAGS,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable424\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable424, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable425[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_OR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR64RegClassID,
    // (or:i64 GR64:i64:$src1, GR64:i64:$src2)  =>  (OR64rr:i64:i32 GR64:i64:$src1, GR64:i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::OR64rr,
    GIR_AddImplicitDef, 0, X86::EFLAGS,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable425\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable425, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable426[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SHL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR8RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR8RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s8, 
    GIM_CheckConstantInt, /*MI*/0, /*Op*/2, 1,
    // (shl:i8 GR8:i8:$src1, 1:i8)  =>  (ADD8rr:i8:i32 GR8:i8:$src1, GR8:i8:$src1)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::ADD8rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src1
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable426\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable426, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable427[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SHL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR16RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR16RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s8, 
    GIM_CheckConstantInt, /*MI*/0, /*Op*/2, 1,
    // (shl:i16 GR16:i16:$src1, 1:i8)  =>  (ADD16rr:i16:i32 GR16:i16:$src1, GR16:i16:$src1)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::ADD16rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src1
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable427\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable427, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable428[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SHL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s8, 
    GIM_CheckConstantInt, /*MI*/0, /*Op*/2, 1,
    // (shl:i32 GR32:i32:$src1, 1:i8)  =>  (ADD32rr:i32:i32 GR32:i32:$src1, GR32:i32:$src1)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::ADD32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src1
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable428\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable428, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable429[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SHL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s8, 
    GIM_CheckConstantInt, /*MI*/0, /*Op*/2, 1,
    // (shl:i64 GR64:i64:$src1, 1:i8)  =>  (ADD64rr:i64:i32 GR64:i64:$src1, GR64:i64:$src1)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::ADD64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src1
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable429\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable429, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable430[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SHL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (shl:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2)  =>  (VPSLLVDrr:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSLLVDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable430\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable430, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable431[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SHL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (shl:v8i32 VR256:v8i32:$src1, VR256:v8i32:$src2)  =>  (VPSLLVDYrr:v8i32 VR256:v8i32:$src1, VR256:v8i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSLLVDYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable431\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable431, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable432[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SHL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (shl:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)  =>  (VPSLLVQrr:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSLLVQrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable432\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable432, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable433[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SHL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (shl:v4i64 VR256:v4i64:$src1, VR256:v4i64:$src2)  =>  (VPSLLVQYrr:v4i64 VR256:v4i64:$src1, VR256:v4i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSLLVQYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable433\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable433, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable434[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SHL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (shl:v16i32 VR512:v16i32:$src1, VR512:v16i32:$src2)  =>  (VPSLLVDZrr:v16i32 VR512:v16i32:$src1, VR512:v16i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSLLVDZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable434\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable434, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable435[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SHL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (shl:v8i32 VR256X:v8i32:$src1, VR256X:v8i32:$src2)  =>  (VPSLLVDZ256rr:v8i32 VR256X:v8i32:$src1, VR256X:v8i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSLLVDZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable435\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable435, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable436[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SHL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (shl:v4i32 VR128X:v4i32:$src1, VR128X:v4i32:$src2)  =>  (VPSLLVDZ128rr:v4i32 VR128X:v4i32:$src1, VR128X:v4i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSLLVDZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable436\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable436, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable437[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SHL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (shl:v8i64 VR512:v8i64:$src1, VR512:v8i64:$src2)  =>  (VPSLLVQZrr:v8i64 VR512:v8i64:$src1, VR512:v8i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSLLVQZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable437\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable437, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable438[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SHL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (shl:v4i64 VR256X:v4i64:$src1, VR256X:v4i64:$src2)  =>  (VPSLLVQZ256rr:v4i64 VR256X:v4i64:$src1, VR256X:v4i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSLLVQZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable438\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable438, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable439[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SHL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (shl:v2i64 VR128X:v2i64:$src1, VR128X:v2i64:$src2)  =>  (VPSLLVQZ128rr:v2i64 VR128X:v2i64:$src1, VR128X:v2i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSLLVQZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable439\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable439, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable440[] = {
    GIM_CheckFeatures, GIFBS_HasBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SHL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v32s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v32s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v32s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (shl:v32i16 VR512:v32i16:$src1, VR512:v32i16:$src2)  =>  (VPSLLVWZrr:v32i16 VR512:v32i16:$src1, VR512:v32i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSLLVWZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable440\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable440, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable441[] = {
    GIM_CheckFeatures, GIFBS_HasVLX_HasBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SHL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (shl:v16i16 VR256X:v16i16:$src1, VR256X:v16i16:$src2)  =>  (VPSLLVWZ256rr:v16i16 VR256X:v16i16:$src1, VR256X:v16i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSLLVWZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable441\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable441, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable442[] = {
    GIM_CheckFeatures, GIFBS_HasVLX_HasBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SHL,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (shl:v8i16 VR128X:v8i16:$src1, VR128X:v8i16:$src2)  =>  (VPSLLVWZ128rr:v8i16 VR128X:v8i16:$src1, VR128X:v8i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSLLVWZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable442\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable442, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable443[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX_Or_NoBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (sub:v16i8 VR128:v16i8:$src1, VR128:v16i8:$src2)  =>  (VPSUBBrr:v16i8 VR128:v16i8:$src1, VR128:v16i8:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSUBBrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable443\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable443, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable444[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (sub:v16i8 VR128:v16i8:$src1, VR128:v16i8:$src2)  =>  (PSUBBrr:v16i8 VR128:v16i8:$src1, VR128:v16i8:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::PSUBBrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable444\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable444, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable445[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2_NoVLX_Or_NoBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v32s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v32s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v32s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (sub:v32i8 VR256:v32i8:$src1, VR256:v32i8:$src2)  =>  (VPSUBBYrr:v32i8 VR256:v32i8:$src1, VR256:v32i8:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSUBBYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable445\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable445, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable446[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX_Or_NoBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (sub:v8i16 VR128:v8i16:$src1, VR128:v8i16:$src2)  =>  (VPSUBWrr:v8i16 VR128:v8i16:$src1, VR128:v8i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSUBWrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable446\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable446, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable447[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (sub:v8i16 VR128:v8i16:$src1, VR128:v8i16:$src2)  =>  (PSUBWrr:v8i16 VR128:v8i16:$src1, VR128:v8i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::PSUBWrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable447\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable447, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable448[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2_NoVLX_Or_NoBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (sub:v16i16 VR256:v16i16:$src1, VR256:v16i16:$src2)  =>  (VPSUBWYrr:v16i16 VR256:v16i16:$src1, VR256:v16i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSUBWYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable448\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable448, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable449[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (sub:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2)  =>  (VPSUBDrr:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSUBDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable449\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable449, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable450[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (sub:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2)  =>  (PSUBDrr:v4i32 VR128:v4i32:$src1, VR128:v4i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::PSUBDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable450\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable450, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable451[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (sub:v8i32 VR256:v8i32:$src1, VR256:v8i32:$src2)  =>  (VPSUBDYrr:v8i32 VR256:v8i32:$src1, VR256:v8i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSUBDYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable451\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable451, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable452[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (sub:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)  =>  (VPSUBQrr:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSUBQrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable452\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable452, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable453[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (sub:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)  =>  (PSUBQrr:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::PSUBQrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable453\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable453, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable454[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (sub:v4i64 VR256:v4i64:$src1, VR256:v4i64:$src2)  =>  (VPSUBQYrr:v4i64 VR256:v4i64:$src1, VR256:v4i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSUBQYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable454\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable454, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable455[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (sub:v8i64 VR512:v8i64:$src1, VR512:v8i64:$src2)  =>  (VPSUBQZrr:v8i64 VR512:v8i64:$src1, VR512:v8i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSUBQZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable455\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable455, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable456[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (sub:v4i64 VR256X:v4i64:$src1, VR256X:v4i64:$src2)  =>  (VPSUBQZ256rr:v4i64 VR256X:v4i64:$src1, VR256X:v4i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSUBQZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable456\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable456, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable457[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (sub:v2i64 VR128X:v2i64:$src1, VR128X:v2i64:$src2)  =>  (VPSUBQZ128rr:v2i64 VR128X:v2i64:$src1, VR128X:v2i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSUBQZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable457\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable457, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable458[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (sub:v16i32 VR512:v16i32:$src1, VR512:v16i32:$src2)  =>  (VPSUBDZrr:v16i32 VR512:v16i32:$src1, VR512:v16i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSUBDZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable458\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable458, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable459[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (sub:v8i32 VR256X:v8i32:$src1, VR256X:v8i32:$src2)  =>  (VPSUBDZ256rr:v8i32 VR256X:v8i32:$src1, VR256X:v8i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSUBDZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable459\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable459, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable460[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (sub:v4i32 VR128X:v4i32:$src1, VR128X:v4i32:$src2)  =>  (VPSUBDZ128rr:v4i32 VR128X:v4i32:$src1, VR128X:v4i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSUBDZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable460\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable460, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable461[] = {
    GIM_CheckFeatures, GIFBS_HasBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v32s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v32s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v32s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (sub:v32i16 VR512:v32i16:$src1, VR512:v32i16:$src2)  =>  (VPSUBWZrr:v32i16 VR512:v32i16:$src1, VR512:v32i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSUBWZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable461\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable461, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable462[] = {
    GIM_CheckFeatures, GIFBS_HasBWI_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (sub:v16i16 VR256X:v16i16:$src1, VR256X:v16i16:$src2)  =>  (VPSUBWZ256rr:v16i16 VR256X:v16i16:$src1, VR256X:v16i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSUBWZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable462\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable462, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable463[] = {
    GIM_CheckFeatures, GIFBS_HasBWI_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (sub:v8i16 VR128X:v8i16:$src1, VR128X:v8i16:$src2)  =>  (VPSUBWZ128rr:v8i16 VR128X:v8i16:$src1, VR128X:v8i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSUBWZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable463\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable463, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable464[] = {
    GIM_CheckFeatures, GIFBS_HasBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v64s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v64s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v64s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (sub:v64i8 VR512:v64i8:$src1, VR512:v64i8:$src2)  =>  (VPSUBBZrr:v64i8 VR512:v64i8:$src1, VR512:v64i8:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSUBBZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable464\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable464, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable465[] = {
    GIM_CheckFeatures, GIFBS_HasBWI_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v32s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v32s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v32s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (sub:v32i8 VR256X:v32i8:$src1, VR256X:v32i8:$src2)  =>  (VPSUBBZ256rr:v32i8 VR256X:v32i8:$src1, VR256X:v32i8:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSUBBZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable465\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable465, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable466[] = {
    GIM_CheckFeatures, GIFBS_HasBWI_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (sub:v16i8 VR128X:v16i8:$src1, VR128X:v16i8:$src2)  =>  (VPSUBBZ128rr:v16i8 VR128X:v16i8:$src1, VR128X:v16i8:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPSUBBZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable466\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable466, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable467[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR8RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR8RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR8RegClassID,
    // (sub:i8 GR8:i8:$src1, GR8:i8:$src2)  =>  (SUB8rr:i8:i32 GR8:i8:$src1, GR8:i8:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::SUB8rr,
    GIR_AddImplicitDef, 0, X86::EFLAGS,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable467\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable467, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable468[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR16RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR16RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR16RegClassID,
    // (sub:i16 GR16:i16:$src1, GR16:i16:$src2)  =>  (SUB16rr:i16:i32 GR16:i16:$src1, GR16:i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::SUB16rr,
    GIR_AddImplicitDef, 0, X86::EFLAGS,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable468\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable468, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable469[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR32RegClassID,
    // (sub:i32 GR32:i32:$src1, GR32:i32:$src2)  =>  (SUB32rr:i32:i32 GR32:i32:$src1, GR32:i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::SUB32rr,
    GIR_AddImplicitDef, 0, X86::EFLAGS,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable469\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable469, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable470[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SUB,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR64RegClassID,
    // (sub:i64 GR64:i64:$src1, GR64:i64:$src2)  =>  (SUB64rr:i64:i32 GR64:i64:$src1, GR64:i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::SUB64rr,
    GIR_AddImplicitDef, 0, X86::EFLAGS,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable470\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable470, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable471[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v4s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v4s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR256RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (xor:v4i64 (bitconvert:v4i64 VR256:v8f32:$src1), (bitconvert:v4i64 VR256:v8f32:$src2))  =>  (VXORPSYrr:v4i64 VR256:v8f32:$src1, VR256:v8f32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VXORPSYrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable471\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable471, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable472[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v4s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v4s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR256RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (xor:v4i64 (bitconvert:v4i64 VR256:v4f64:$src1), (bitconvert:v4i64 VR256:v4f64:$src2))  =>  (VXORPDYrr:v4i64 VR256:v4f64:$src1, VR256:v4f64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VXORPDYrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable472\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable472, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable473[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR128RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (xor:v2i64 (bitconvert:v2i64 VR128:v4f32:$src1), (bitconvert:v2i64 VR128:v4f32:$src2))  =>  (VXORPSrr:v2i64 VR128:v4f32:$src1, VR128:v4f32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VXORPSrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable473\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable473, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable474[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR128RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (xor:v2i64 (bitconvert:v2i64 VR128:v2f64:$src1), (bitconvert:v2i64 VR128:v2f64:$src2))  =>  (VXORPDrr:v2i64 VR128:v2f64:$src1, VR128:v2f64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VXORPDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable474\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable474, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable475[] = {
    GIM_CheckFeatures, GIFBS_UseSSE1,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR128RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (xor:v2i64 (bitconvert:v2i64 VR128:v4f32:$src1), (bitconvert:v2i64 VR128:v4f32:$src2))  =>  (XORPSrr:v2i64 VR128:v4f32:$src1, VR128:v4f32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::XORPSrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable475\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable475, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable476[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR128RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (xor:v2i64 (bitconvert:v2i64 VR128:v2f64:$src1), (bitconvert:v2i64 VR128:v2f64:$src2))  =>  (XORPDrr:v2i64 VR128:v2f64:$src1, VR128:v2f64:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::XORPDrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable476\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable476, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable477[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v8s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v8s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR512RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (xor:v8i64 (bitconvert:v8i64 VR512:v16i32:$src1), (bitconvert:v8i64 VR512:v16i32:$src2))  =>  (VPXORDZrr:v8i64 VR512:v16i32:$src1, VR512:v16i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPXORDZrr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable477\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable477, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable478[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v4s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v4s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (xor:v4i64 (bitconvert:v4i64 VR256X:v8i32:$src1), (bitconvert:v4i64 VR256X:v8i32:$src2))  =>  (VPXORDZ256rr:v4i64 VR256X:v8i32:$src1, VR256X:v8i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPXORDZ256rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable478\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable478, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable479[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/2, /*MI*/0, /*OpIdx*/2, // MIs[2]
    GIM_CheckNumOperands, /*MI*/2, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[1] src1
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckOpcode, /*MI*/2, TargetOpcode::G_BITCAST,
    // MIs[2] Operand 0
    GIM_CheckType, /*MI*/2, /*Op*/0, /*Type*/GILLT_v2s64, 
    // MIs[2] src2
    GIM_CheckType, /*MI*/2, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/2, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    GIM_CheckIsSafeToFold, /*InsnID*/2,
    // (xor:v2i64 (bitconvert:v2i64 VR128X:v4i32:$src1), (bitconvert:v2i64 VR128X:v4i32:$src2))  =>  (VPXORDZ128rr:v2i64 VR128X:v4i32:$src1, VR128X:v4i32:$src2)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::VPXORDZ128rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src1
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/2, /*OpIdx*/1, // src2
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable479\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable479, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable480[] = {
    GIM_CheckFeatures, GIFBS_HasBMI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR32RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (xor:i32 (add:i32 GR32:i32:$src, -1:i32), GR32:i32:$src)  =>  (BLSMSK32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLSMSK32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable480\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable480, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable481[] = {
    GIM_CheckFeatures, GIFBS_HasBMI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR64RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (xor:i64 (add:i64 GR64:i64:$src, -1:i64), GR64:i64:$src)  =>  (BLSMSK64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLSMSK64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable481\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable481, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable482[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, 1,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR32RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (xor:i32 (add:i32 GR32:i32:$src, 1:i32), GR32:i32:$src)  =>  (BLCMSK32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLCMSK32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable482\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable482, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable483[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, 1,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR64RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (xor:i64 (add:i64 GR64:i64:$src, 1:i64), GR64:i64:$src)  =>  (BLCMSK64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLCMSK64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable483\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable483, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable484[] = {
    GIM_CheckFeatures, GIFBS_HasBMI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/2, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (xor:i32 GR32:i32:$src, (add:i32 GR32:i32:$src, -1:i32))  =>  (BLSMSK32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLSMSK32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable484\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable484, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable485[] = {
    GIM_CheckFeatures, GIFBS_HasBMI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/2, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, -1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (xor:i64 GR64:i64:$src, (add:i64 GR64:i64:$src, -1:i64))  =>  (BLSMSK64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLSMSK64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable485\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable485, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable486[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/2, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s32, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, 1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (xor:i32 GR32:i32:$src, (add:i32 GR32:i32:$src, 1:i32))  =>  (BLCMSK32rr:i32:i32 GR32:i32:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLCMSK32rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable486\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable486, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable487[] = {
    GIM_CheckFeatures, GIFBS_HasTBM,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/2, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_ADD,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s64, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[1] Operand 2
    GIM_CheckType, /*MI*/1, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/1, /*Op*/2, 1,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (xor:i64 GR64:i64:$src, (add:i64 GR64:i64:$src, 1:i64))  =>  (BLCMSK64rr:i64:i32 GR64:i64:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::BLCMSK64rr,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable487\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable487, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable488[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR8RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR8RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s8, 
    GIM_CheckConstantInt, /*MI*/0, /*Op*/2, -1,
    // (xor:i8 GR8:i8:$src1, -1:i8)  =>  (NOT8r:i8 GR8:i8:$src1)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::NOT8r,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src1
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable488\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable488, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable489[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR16RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR16RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s16, 
    GIM_CheckConstantInt, /*MI*/0, /*Op*/2, -1,
    // (xor:i16 GR16:i16:$src1, -1:i16)  =>  (NOT16r:i16 GR16:i16:$src1)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::NOT16r,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src1
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable489\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable489, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable490[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckConstantInt, /*MI*/0, /*Op*/2, -1,
    // (xor:i32 GR32:i32:$src1, -1:i32)  =>  (NOT32r:i32 GR32:i32:$src1)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::NOT32r,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src1
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable490\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable490, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable491[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[0] Operand 2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckConstantInt, /*MI*/0, /*Op*/2, -1,
    // (xor:i64 GR64:i64:$src1, -1:i64)  =>  (NOT64r:i64 GR64:i64:$src1)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::NOT64r,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, // src1
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable491\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable491, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable492[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (xor:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)  =>  (VPXORrr:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPXORrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable492\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable492, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable493[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128RegClassID,
    // (xor:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)  =>  (PXORrr:v2i64 VR128:v2i64:$src1, VR128:v2i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::PXORrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable493\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable493, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable494[] = {
    GIM_CheckFeatures, GIFBS_HasAVX2_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (xor:v4i64 VR256:v4i64:$src1, VR256:v4i64:$src2)  =>  (VPXORYrr:v4i64 VR256:v4i64:$src1, VR256:v4i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPXORYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable494\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable494, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable495[] = {
    GIM_CheckFeatures, GIFBS_HasDQI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VK8RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VK8RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VK8RegClassID,
    // (xor:v8i1 VK8:v8i1:$src1, VK8:v8i1:$src2)  =>  (KXORBrr:v8i1 VK8:v8i1:$src1, VK8:v8i1:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::KXORBrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable495\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable495, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable496[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VK16RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VK16RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v16s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VK16RegClassID,
    // (xor:v16i1 VK16:v16i1:$src1, VK16:v16i1:$src2)  =>  (KXORWrr:v16i1 VK16:v16i1:$src1, VK16:v16i1:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::KXORWrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable496\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable496, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable497[] = {
    GIM_CheckFeatures, GIFBS_HasBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v32s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VK32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v32s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VK32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v32s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VK32RegClassID,
    // (xor:v32i1 VK32:v32i1:$src1, VK32:v32i1:$src2)  =>  (KXORDrr:v32i1 VK32:v32i1:$src1, VK32:v32i1:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::KXORDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable497\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable497, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable498[] = {
    GIM_CheckFeatures, GIFBS_HasBWI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v64s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VK64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v64s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VK64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v64s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VK64RegClassID,
    // (xor:v64i1 VK64:v64i1:$src1, VK64:v64i1:$src2)  =>  (KXORQrr:v64i1 VK64:v64i1:$src1, VK64:v64i1:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::KXORQrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable498\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable498, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable499[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR512RegClassID,
    // (xor:v8i64 VR512:v8i64:$src1, VR512:v8i64:$src2)  =>  (VPXORQZrr:v8i64 VR512:v8i64:$src1, VR512:v8i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPXORQZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable499\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable499, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable500[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256XRegClassID,
    // (xor:v4i64 VR256X:v4i64:$src1, VR256X:v4i64:$src2)  =>  (VPXORQZ256rr:v4i64 VR256X:v4i64:$src1, VR256X:v4i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPXORQZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable500\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable500, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable501[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR128XRegClassID,
    // (xor:v2i64 VR128X:v2i64:$src1, VR128X:v2i64:$src2)  =>  (VPXORQZ128rr:v2i64 VR128X:v2i64:$src1, VR128X:v2i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VPXORQZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable501\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable501, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable502[] = {
    GIM_CheckFeatures, GIFBS_HasAVX1Only,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::VR256RegClassID,
    // (xor:v4i64 VR256:v4i64:$src1, VR256:v4i64:$src2)  =>  (VXORPSYrr:v4i64 VR256:v4i64:$src1, VR256:v4i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VXORPSYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable502\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable502, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable503[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR8RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR8RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR8RegClassID,
    // (xor:i8 GR8:i8:$src1, GR8:i8:$src2)  =>  (XOR8rr:i8:i32 GR8:i8:$src1, GR8:i8:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::XOR8rr,
    GIR_AddImplicitDef, 0, X86::EFLAGS,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable503\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable503, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable504[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR16RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR16RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR16RegClassID,
    // (xor:i16 GR16:i16:$src1, GR16:i16:$src2)  =>  (XOR16rr:i16:i32 GR16:i16:$src1, GR16:i16:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::XOR16rr,
    GIR_AddImplicitDef, 0, X86::EFLAGS,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable504\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable504, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable505[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR32RegClassID,
    // (xor:i32 GR32:i32:$src1, GR32:i32:$src2)  =>  (XOR32rr:i32:i32 GR32:i32:$src1, GR32:i32:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::XOR32rr,
    GIR_AddImplicitDef, 0, X86::EFLAGS,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable505\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable505, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable506[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/3,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_XOR,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // MIs[0] src2
    GIM_CheckType, /*MI*/0, /*Op*/2, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/2, /*RC*/X86::GR64RegClassID,
    // (xor:i64 GR64:i64:$src1, GR64:i64:$src2)  =>  (XOR64rr:i64:i32 GR64:i64:$src1, GR64:i64:$src2)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::XOR64rr,
    GIR_AddImplicitDef, 0, X86::EFLAGS,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable506\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable506, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable507[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ANYEXT,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s16, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s16, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v16s1, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VK16RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (anyext:i32 (bitconvert:i16 VK16:v16i1:$src))  =>  (COPY_TO_REGCLASS:i32 VK16:v16i1:$src, GR32:i32)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/TargetOpcode::COPY,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainOperandRC, /*InsnID*/0, /*Op*/0, /*RC GR32*/ 24,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable507\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable507, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable508[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ANYEXT,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s8, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s8, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v8s1, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VK8RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (anyext:i32 (bitconvert:i8 VK8:v8i1:$src))  =>  (COPY_TO_REGCLASS:i32 VK8:v8i1:$src, GR32:i32)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/TargetOpcode::COPY,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainOperandRC, /*InsnID*/0, /*Op*/0, /*RC GR32*/ 24,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable508\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable508, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable509[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ANYEXT,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR8RegClassID,
    // (anyext:i32 GR8:i8:$src)  =>  (MOVZX32rr8:i32 GR8:i8:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::MOVZX32rr8,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable509\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable509, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable510[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_BITCAST,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // (bitconvert:f64 GR64:i64:$src)  =>  (VMOV64toSDrr:f64 GR64:i64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VMOV64toSDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable510\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable510, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable511[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_BITCAST,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // (bitconvert:f64 GR64:i64:$src)  =>  (MOV64toSDrr:f64 GR64:i64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::MOV64toSDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable511\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable511, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable512[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_BITCAST,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // (bitconvert:f32 GR32:i32:$src)  =>  (VMOVDI2SSrr:f32 GR32:i32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VMOVDI2SSrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable512\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable512, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable513[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_BITCAST,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // (bitconvert:f32 GR32:i32:$src)  =>  (MOVDI2SSrr:f32 GR32:i32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::MOVDI2SSrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable513\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable513, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable514[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_BITCAST,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR64RegClassID,
    // (bitconvert:i64 FR64:f64:$src)  =>  (VMOVSDto64rr:i64 FR64:f64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VMOVSDto64rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable514\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable514, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable515[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_BITCAST,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR64RegClassID,
    // (bitconvert:i64 FR64:f64:$src)  =>  (MOVSDto64rr:i64 FR64:f64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::MOVSDto64rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable515\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable515, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable516[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_BITCAST,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR32RegClassID,
    // (bitconvert:i32 FR32:f32:$src)  =>  (VMOVSS2DIrr:i32 FR32:f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VMOVSS2DIrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable516\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable516, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable517[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_BITCAST,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR32RegClassID,
    // (bitconvert:i32 FR32:f32:$src)  =>  (MOVSS2DIrr:i32 FR32:f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::MOVSS2DIrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable517\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable517, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable518[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_BITCAST,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR64XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // (bitconvert:f64 GR64:i64:$src)  =>  (VMOV64toSDZrr:f64 GR64:i64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VMOV64toSDZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable518\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable518, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable519[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_BITCAST,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR64XRegClassID,
    // (bitconvert:i64 FR64X:f64:$src)  =>  (VMOVSDto64Zrr:i64 FR64X:f64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VMOVSDto64Zrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable519\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable519, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable520[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_BITCAST,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR32XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // (bitconvert:f32 GR32:i32:$src)  =>  (VMOVDI2SSZrr:f32 GR32:i32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VMOVDI2SSZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable520\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable520, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable521[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_BITCAST,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR32XRegClassID,
    // (bitconvert:i32 FR32X:f32:$src)  =>  (VMOVSS2DIZrr:i32 FR32X:f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VMOVSS2DIZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable521\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable521, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable522[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_BITCAST,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v32s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VK32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // (bitconvert:v32i1 GR32:i32:$src)  =>  (COPY_TO_REGCLASS:v32i1 GR32:i32:$src, VK32:i32)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/TargetOpcode::COPY,
    GIR_ConstrainOperandRC, /*InsnID*/0, /*Op*/0, /*RC VK32*/ 31,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable522\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable522, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable523[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_BITCAST,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v32s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VK32RegClassID,
    // (bitconvert:i32 VK32:v32i1:$src)  =>  (COPY_TO_REGCLASS:i32 VK32:v32i1:$src, GR32:i32)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/TargetOpcode::COPY,
    GIR_ConstrainOperandRC, /*InsnID*/0, /*Op*/0, /*RC GR32*/ 24,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable523\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable523, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable524[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_BITCAST,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v64s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VK64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // (bitconvert:v64i1 GR64:i64:$src)  =>  (COPY_TO_REGCLASS:v64i1 GR64:i64:$src, VK64:i32)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/TargetOpcode::COPY,
    GIR_ConstrainOperandRC, /*InsnID*/0, /*Op*/0, /*RC VK64*/ 61,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable524\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable524, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable525[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_BITCAST,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v64s1, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VK64RegClassID,
    // (bitconvert:i64 VK64:v64i1:$src)  =>  (COPY_TO_REGCLASS:i64 VK64:v64i1:$src, GR64:i32)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/TargetOpcode::COPY,
    GIR_ConstrainOperandRC, /*InsnID*/0, /*Op*/0, /*RC GR64*/ 49,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable525\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable525, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable526[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_CONSTANT,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckLiteralInt, /*MI*/0, /*Op*/1, 0,
    // 0:i32  =>  (MOV32r0:i32:i32)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::MOV32r0,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable526\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable526, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable527[] = {
    GIM_CheckFeatures, GIFBS_OptForSize_NotSlowIncDec_Not64BitMode,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_CONSTANT,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckLiteralInt, /*MI*/0, /*Op*/1, 1,
    // 1:i32  =>  (MOV32r1:i32:i32)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::MOV32r1,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable527\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable527, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable528[] = {
    GIM_CheckFeatures, GIFBS_OptForSize_NotSlowIncDec_Not64BitMode,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_CONSTANT,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckLiteralInt, /*MI*/0, /*Op*/1, -1,
    // -1:i32  =>  (MOV32r_1:i32:i32)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::MOV32r_1,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable528\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable528, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable529[] = {
    GIM_CheckFeatures, GIFBS_FPStackf32,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FNEG,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::RFP32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::RFP32RegClassID,
    // (fneg:f32 RFP32:f32:$src)  =>  (CHS_Fp32:f32:i16 RFP32:f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::CHS_Fp32,
    GIR_AddImplicitDef, 0, X86::FPSW,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable529\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable529, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable530[] = {
    GIM_CheckFeatures, GIFBS_FPStackf64,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FNEG,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::RFP64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::RFP64RegClassID,
    // (fneg:f64 RFP64:f64:$src)  =>  (CHS_Fp64:f64:i16 RFP64:f64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::CHS_Fp64,
    GIR_AddImplicitDef, 0, X86::FPSW,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable530\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable530, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable531[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FNEG,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s80, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::RFP80RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s80, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::RFP80RegClassID,
    // (fneg:f80 RFP80:f80:$src)  =>  (CHS_Fp80:f80:i16 RFP80:f80:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::CHS_Fp80,
    GIR_AddImplicitDef, 0, X86::FPSW,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable531\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable531, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable532[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPEXT,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR32RegClassID,
    // (fpextend:f64 FR32:f32:$src)  =>  (CVTSS2SDrr:f64 FR32:f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::CVTSS2SDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable532\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable532, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable533[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPEXT,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // (fpextend:v4f64 VR128:v4f32:$src)  =>  (VCVTPS2PDYrr:v4f64 VR128:v4f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTPS2PDYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable533\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable533, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable534[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPEXT,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // (fpextend:v8f64 VR256X:v8f32:$src)  =>  (VCVTPS2PDZrr:v8f64 VR256X:v8f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTPS2PDZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable534\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable534, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable535[] = {
    GIM_CheckFeatures, GIFBS_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPEXT,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // (fpextend:v4f64 VR128X:v4f32:$src)  =>  (VCVTPS2PDZ256rr:v4f64 VR128X:v4f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTPS2PDZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable535\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable535, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable536[] = {
    GIM_CheckFeatures, GIFBS_FPStackf32,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPEXT,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::RFP64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::RFP32RegClassID,
    // (fpextend:f64 RFP32:f32:$src)  =>  (COPY_TO_REGCLASS:f64 RFP32:f32:$src, RFP64:i32)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/TargetOpcode::COPY,
    GIR_ConstrainOperandRC, /*InsnID*/0, /*Op*/0, /*RC RFP64*/ 47,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable536\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable536, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable537[] = {
    GIM_CheckFeatures, GIFBS_FPStackf32,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPEXT,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s80, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::RFP80RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::RFP32RegClassID,
    // (fpextend:f80 RFP32:f32:$src)  =>  (COPY_TO_REGCLASS:f80 RFP32:f32:$src, RFP80:i32)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/TargetOpcode::COPY,
    GIR_ConstrainOperandRC, /*InsnID*/0, /*Op*/0, /*RC RFP80*/ 87,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable537\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable537, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable538[] = {
    GIM_CheckFeatures, GIFBS_FPStackf64,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPEXT,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s80, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::RFP80RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::RFP64RegClassID,
    // (fpextend:f80 RFP64:f64:$src)  =>  (COPY_TO_REGCLASS:f80 RFP64:f64:$src, RFP80:i32)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/TargetOpcode::COPY,
    GIR_ConstrainOperandRC, /*InsnID*/0, /*Op*/0, /*RC RFP80*/ 87,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable538\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable538, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable539[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR32RegClassID,
    // (fp_to_sint:i32 FR32:f32:$src)  =>  (VCVTTSS2SIrr:i32 FR32:f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTSS2SIrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable539\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable539, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable540[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR32RegClassID,
    // (fp_to_sint:i64 FR32:f32:$src)  =>  (VCVTTSS2SI64rr:i64 FR32:f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTSS2SI64rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable540\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable540, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable541[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR64RegClassID,
    // (fp_to_sint:i32 FR64:f64:$src)  =>  (VCVTTSD2SIrr:i32 FR64:f64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTSD2SIrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable541\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable541, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable542[] = {
    GIM_CheckFeatures, GIFBS_UseAVX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR64RegClassID,
    // (fp_to_sint:i64 FR64:f64:$src)  =>  (VCVTTSD2SI64rr:i64 FR64:f64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTSD2SI64rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable542\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable542, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable543[] = {
    GIM_CheckFeatures, GIFBS_UseSSE1,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR32RegClassID,
    // (fp_to_sint:i32 FR32:f32:$src)  =>  (CVTTSS2SIrr:i32 FR32:f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::CVTTSS2SIrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable543\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable543, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable544[] = {
    GIM_CheckFeatures, GIFBS_UseSSE1,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR32RegClassID,
    // (fp_to_sint:i64 FR32:f32:$src)  =>  (CVTTSS2SI64rr:i64 FR32:f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::CVTTSS2SI64rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable544\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable544, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable545[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR64RegClassID,
    // (fp_to_sint:i32 FR64:f64:$src)  =>  (CVTTSD2SIrr:i32 FR64:f64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::CVTTSD2SIrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable545\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable545, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable546[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR64RegClassID,
    // (fp_to_sint:i64 FR64:f64:$src)  =>  (CVTTSD2SI64rr:i64 FR64:f64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::CVTTSD2SI64rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable546\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable546, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable547[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // (fp_to_sint:v4i32 VR128:v4f32:$src)  =>  (VCVTTPS2DQrr:v4i32 VR128:v4f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTPS2DQrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable547\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable547, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable548[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // (fp_to_sint:v8i32 VR256:v8f32:$src)  =>  (VCVTTPS2DQYrr:v8i32 VR256:v8f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTPS2DQYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable548\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable548, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable549[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // (fp_to_sint:v4i32 VR128:v4f32:$src)  =>  (CVTTPS2DQrr:v4i32 VR128:v4f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::CVTTPS2DQrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable549\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable549, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable550[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // (fp_to_sint:v4i32 VR256:v4f64:$src)  =>  (VCVTTPD2DQYrr:v4i32 VR256:v4f64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTPD2DQYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable550\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable550, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable551[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR32XRegClassID,
    // (fp_to_sint:i32 FR32X:f32:$src)  =>  (VCVTTSS2SIZrr:i32 FR32X:f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTSS2SIZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable551\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable551, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable552[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR32XRegClassID,
    // (fp_to_sint:i64 FR32X:f32:$src)  =>  (VCVTTSS2SI64Zrr:i64 FR32X:f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTSS2SI64Zrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable552\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable552, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable553[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR64XRegClassID,
    // (fp_to_sint:i32 FR64X:f64:$src)  =>  (VCVTTSD2SIZrr:i32 FR64X:f64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTSD2SIZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable553\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable553, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable554[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR64XRegClassID,
    // (fp_to_sint:i64 FR64X:f64:$src)  =>  (VCVTTSD2SI64Zrr:i64 FR64X:f64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTSD2SI64Zrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable554\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable554, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable555[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // (fp_to_sint:v16i32 VR512:v16f32:$src)  =>  (VCVTTPS2DQZrr:v16i32 VR512:v16f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTPS2DQZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable555\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable555, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable556[] = {
    GIM_CheckFeatures, GIFBS_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // (fp_to_sint:v4i32 VR128X:v4f32:$src)  =>  (VCVTTPS2DQZ128rr:v4i32 VR128X:v4f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTPS2DQZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable556\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable556, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable557[] = {
    GIM_CheckFeatures, GIFBS_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // (fp_to_sint:v8i32 VR256X:v8f32:$src)  =>  (VCVTTPS2DQZ256rr:v8i32 VR256X:v8f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTPS2DQZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable557\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable557, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable558[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // (fp_to_sint:v8i32 VR512:v8f64:$src)  =>  (VCVTTPD2DQZrr:v8i32 VR512:v8f64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTPD2DQZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable558\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable558, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable559[] = {
    GIM_CheckFeatures, GIFBS_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // (fp_to_sint:v4i32 VR256X:v4f64:$src)  =>  (VCVTTPD2DQZ256rr:v4i32 VR256X:v4f64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTPD2DQZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable559\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable559, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable560[] = {
    GIM_CheckFeatures, GIFBS_HasDQI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // (fp_to_sint:v8i64 VR512:v8f64:$src)  =>  (VCVTTPD2QQZrr:v8i64 VR512:v8f64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTPD2QQZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable560\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable560, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable561[] = {
    GIM_CheckFeatures, GIFBS_HasDQI_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // (fp_to_sint:v2i64 VR128X:v2f64:$src)  =>  (VCVTTPD2QQZ128rr:v2i64 VR128X:v2f64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTPD2QQZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable561\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable561, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable562[] = {
    GIM_CheckFeatures, GIFBS_HasDQI_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // (fp_to_sint:v4i64 VR256X:v4f64:$src)  =>  (VCVTTPD2QQZ256rr:v4i64 VR256X:v4f64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTPD2QQZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable562\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable562, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable563[] = {
    GIM_CheckFeatures, GIFBS_HasDQI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // (fp_to_sint:v8i64 VR256X:v8f32:$src)  =>  (VCVTTPS2QQZrr:v8i64 VR256X:v8f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTPS2QQZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable563\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable563, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable564[] = {
    GIM_CheckFeatures, GIFBS_HasDQI_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOSI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // (fp_to_sint:v4i64 VR128X:v4f32:$src)  =>  (VCVTTPS2QQZ256rr:v4i64 VR128X:v4f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTPS2QQZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable564\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable564, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable565[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOUI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR32XRegClassID,
    // (fp_to_uint:i32 FR32X:f32:$src)  =>  (VCVTTSS2USIZrr:i32 FR32X:f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTSS2USIZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable565\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable565, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable566[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOUI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR32XRegClassID,
    // (fp_to_uint:i64 FR32X:f32:$src)  =>  (VCVTTSS2USI64Zrr:i64 FR32X:f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTSS2USI64Zrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable566\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable566, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable567[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOUI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR64XRegClassID,
    // (fp_to_uint:i32 FR64X:f64:$src)  =>  (VCVTTSD2USIZrr:i32 FR64X:f64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTSD2USIZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable567\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable567, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable568[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOUI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::FR64XRegClassID,
    // (fp_to_uint:i64 FR64X:f64:$src)  =>  (VCVTTSD2USI64Zrr:i64 FR64X:f64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTSD2USI64Zrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable568\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable568, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable569[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOUI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // (fp_to_uint:v16i32 VR512:v16f32:$src)  =>  (VCVTTPS2UDQZrr:v16i32 VR512:v16f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTPS2UDQZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable569\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable569, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable570[] = {
    GIM_CheckFeatures, GIFBS_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOUI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // (fp_to_uint:v4i32 VR128X:v4f32:$src)  =>  (VCVTTPS2UDQZ128rr:v4i32 VR128X:v4f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTPS2UDQZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable570\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable570, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable571[] = {
    GIM_CheckFeatures, GIFBS_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOUI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // (fp_to_uint:v8i32 VR256X:v8f32:$src)  =>  (VCVTTPS2UDQZ256rr:v8i32 VR256X:v8f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTPS2UDQZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable571\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable571, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable572[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOUI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // (fp_to_uint:v8i32 VR512:v8f64:$src)  =>  (VCVTTPD2UDQZrr:v8i32 VR512:v8f64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTPD2UDQZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable572\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable572, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable573[] = {
    GIM_CheckFeatures, GIFBS_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOUI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // (fp_to_uint:v4i32 VR256X:v4f64:$src)  =>  (VCVTTPD2UDQZ256rr:v4i32 VR256X:v4f64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTPD2UDQZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable573\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable573, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable574[] = {
    GIM_CheckFeatures, GIFBS_HasDQI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOUI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // (fp_to_uint:v8i64 VR512:v8f64:$src)  =>  (VCVTTPD2UQQZrr:v8i64 VR512:v8f64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTPD2UQQZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable574\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable574, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable575[] = {
    GIM_CheckFeatures, GIFBS_HasDQI_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOUI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // (fp_to_uint:v2i64 VR128X:v2f64:$src)  =>  (VCVTTPD2UQQZ128rr:v2i64 VR128X:v2f64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTPD2UQQZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable575\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable575, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable576[] = {
    GIM_CheckFeatures, GIFBS_HasDQI_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOUI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // (fp_to_uint:v4i64 VR256X:v4f64:$src)  =>  (VCVTTPD2UQQZ256rr:v4i64 VR256X:v4f64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTPD2UQQZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable576\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable576, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable577[] = {
    GIM_CheckFeatures, GIFBS_HasDQI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOUI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // (fp_to_uint:v8i64 VR256X:v8f32:$src)  =>  (VCVTTPS2UQQZrr:v8i64 VR256X:v8f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTPS2UQQZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable577\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable577, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable578[] = {
    GIM_CheckFeatures, GIFBS_HasDQI_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_FPTOUI,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // (fp_to_uint:v4i64 VR128X:v4f32:$src)  =>  (VCVTTPS2UQQZ256rr:v4i64 VR128X:v4f32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTTPS2UQQZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable578\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable578, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable579[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SEXT,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR8RegClassID,
    // (sext:i32 GR8:i8:$src)  =>  (MOVSX32rr8:i32 GR8:i8:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::MOVSX32rr8,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable579\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable579, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable580[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SEXT,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR16RegClassID,
    // (sext:i32 GR16:i16:$src)  =>  (MOVSX32rr16:i32 GR16:i16:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::MOVSX32rr16,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable580\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable580, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable581[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SEXT,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR8RegClassID,
    // (sext:i64 GR8:i8:$src)  =>  (MOVSX64rr8:i64 GR8:i8:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::MOVSX64rr8,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable581\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable581, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable582[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SEXT,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR16RegClassID,
    // (sext:i64 GR16:i16:$src)  =>  (MOVSX64rr16:i64 GR16:i16:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::MOVSX64rr16,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable582\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable582, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable583[] = {
    GIM_CheckFeatures, GIFBS_In64BitMode,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SEXT,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // (sext:i64 GR32:i32:$src)  =>  (MOVSX64rr32:i64 GR32:i32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::MOVSX64rr32,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable583\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable583, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable584[] = {
    GIM_CheckFeatures, GIFBS_UseSSE1,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // (sint_to_fp:f32 GR32:i32:$src)  =>  (CVTSI2SSrr:f32 GR32:i32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::CVTSI2SSrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable584\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable584, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable585[] = {
    GIM_CheckFeatures, GIFBS_UseSSE1,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // (sint_to_fp:f32 GR64:i64:$src)  =>  (CVTSI2SS64rr:f32 GR64:i64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::CVTSI2SS64rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable585\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable585, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable586[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // (sint_to_fp:f64 GR32:i32:$src)  =>  (CVTSI2SDrr:f64 GR32:i32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::CVTSI2SDrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable586\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable586, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable587[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::FR64RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR64RegClassID,
    // (sint_to_fp:f64 GR64:i64:$src)  =>  (CVTSI2SD64rr:f64 GR64:i64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::CVTSI2SD64rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable587\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable587, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable588[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // (sint_to_fp:v4f32 VR128:v4i32:$src)  =>  (VCVTDQ2PSrr:v4f32 VR128:v4i32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTDQ2PSrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable588\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable588, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable589[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256RegClassID,
    // (sint_to_fp:v8f32 VR256:v8i32:$src)  =>  (VCVTDQ2PSYrr:v8f32 VR256:v8i32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTDQ2PSYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable589\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable589, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable590[] = {
    GIM_CheckFeatures, GIFBS_UseSSE2,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // (sint_to_fp:v4f32 VR128:v4i32:$src)  =>  (CVTDQ2PSrr:v4f32 VR128:v4i32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::CVTDQ2PSrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable590\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable590, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable591[] = {
    GIM_CheckFeatures, GIFBS_HasAVX_NoVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128RegClassID,
    // (sint_to_fp:v4f64 VR128:v4i32:$src)  =>  (VCVTDQ2PDYrr:v4f64 VR128:v4i32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTDQ2PDYrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable591\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable591, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable592[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // (sint_to_fp:v8f64 VR256X:v8i32:$src)  =>  (VCVTDQ2PDZrr:v8f64 VR256X:v8i32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTDQ2PDZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable592\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable592, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable593[] = {
    GIM_CheckFeatures, GIFBS_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // (sint_to_fp:v4f64 VR128X:v4i32:$src)  =>  (VCVTDQ2PDZ256rr:v4f64 VR128X:v4i32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTDQ2PDZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable593\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable593, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable594[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // (sint_to_fp:v16f32 VR512:v16i32:$src)  =>  (VCVTDQ2PSZrr:v16f32 VR512:v16i32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTDQ2PSZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable594\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable594, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable595[] = {
    GIM_CheckFeatures, GIFBS_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // (sint_to_fp:v4f32 VR128X:v4i32:$src)  =>  (VCVTDQ2PSZ128rr:v4f32 VR128X:v4i32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTDQ2PSZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable595\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable595, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable596[] = {
    GIM_CheckFeatures, GIFBS_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // (sint_to_fp:v8f32 VR256X:v8i32:$src)  =>  (VCVTDQ2PSZ256rr:v8f32 VR256X:v8i32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTDQ2PSZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable596\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable596, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable597[] = {
    GIM_CheckFeatures, GIFBS_HasDQI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // (sint_to_fp:v8f64 VR512:v8i64:$src)  =>  (VCVTQQ2PDZrr:v8f64 VR512:v8i64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTQQ2PDZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable597\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable597, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable598[] = {
    GIM_CheckFeatures, GIFBS_HasDQI_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // (sint_to_fp:v2f64 VR128X:v2i64:$src)  =>  (VCVTQQ2PDZ128rr:v2f64 VR128X:v2i64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTQQ2PDZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable598\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable598, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable599[] = {
    GIM_CheckFeatures, GIFBS_HasDQI_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // (sint_to_fp:v4f64 VR256X:v4i64:$src)  =>  (VCVTQQ2PDZ256rr:v4f64 VR256X:v4i64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTQQ2PDZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable599\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable599, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable600[] = {
    GIM_CheckFeatures, GIFBS_HasDQI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // (sint_to_fp:v8f32 VR512:v8i64:$src)  =>  (VCVTQQ2PSZrr:v8f32 VR512:v8i64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTQQ2PSZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable600\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable600, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable601[] = {
    GIM_CheckFeatures, GIFBS_HasDQI_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_SITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // (sint_to_fp:v4f32 VR256X:v4i64:$src)  =>  (VCVTQQ2PSZ256rr:v4f32 VR256X:v4i64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTQQ2PSZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable601\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable601, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable602[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_TRUNC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // (trunc:i16 GR32:i32:$src)  =>  (EXTRACT_SUBREG:i16 GR32:i32:$src, sub_16bit:i32)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/TargetOpcode::COPY,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_CopySubReg, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, /*SubRegIdx*/3, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainOperandRC, /*InsnID*/0, /*Op*/0, /*RC GR16*/ 4,
    GIR_ConstrainOperandRC, /*InsnID*/0, /*Op*/1, /*RC GR32*/ 24,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable602\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable602, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable603[] = {
    GIM_CheckFeatures, GIFBS_In64BitMode,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_TRUNC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR32RegClassID,
    // (trunc:i8 GR32:i32:$src)  =>  (EXTRACT_SUBREG:i8 GR32:i32:$src, sub_8bit:i32)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/TargetOpcode::COPY,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_CopySubReg, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, /*SubRegIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainOperandRC, /*InsnID*/0, /*Op*/0, /*RC GR8*/ 0,
    GIR_ConstrainOperandRC, /*InsnID*/0, /*Op*/1, /*RC GR32*/ 24,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable603\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable603, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable604[] = {
    GIM_CheckFeatures, GIFBS_In64BitMode,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_TRUNC,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR16RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR16RegClassID,
    // (trunc:i8 GR16:i16:$src)  =>  (EXTRACT_SUBREG:i8 GR16:i16:$src, sub_8bit:i32)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/TargetOpcode::COPY,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_CopySubReg, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/1, /*SubRegIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainOperandRC, /*InsnID*/0, /*Op*/0, /*RC GR8*/ 0,
    GIR_ConstrainOperandRC, /*InsnID*/0, /*Op*/1, /*RC GR16*/ 4,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable604\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable604, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable605[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_UITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // (uint_to_fp:v8f64 VR256X:v8i32:$src)  =>  (VCVTUDQ2PDZrr:v8f64 VR256X:v8i32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTUDQ2PDZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable605\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable605, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable606[] = {
    GIM_CheckFeatures, GIFBS_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_UITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // (uint_to_fp:v4f64 VR128X:v4i32:$src)  =>  (VCVTUDQ2PDZ256rr:v4f64 VR128X:v4i32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTUDQ2PDZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable606\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable606, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable607[] = {
    GIM_CheckFeatures, GIFBS_HasAVX512,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_UITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v16s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // (uint_to_fp:v16f32 VR512:v16i32:$src)  =>  (VCVTUDQ2PSZrr:v16f32 VR512:v16i32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTUDQ2PSZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable607\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable607, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable608[] = {
    GIM_CheckFeatures, GIFBS_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_UITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // (uint_to_fp:v4f32 VR128X:v4i32:$src)  =>  (VCVTUDQ2PSZ128rr:v4f32 VR128X:v4i32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTUDQ2PSZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable608\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable608, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable609[] = {
    GIM_CheckFeatures, GIFBS_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_UITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // (uint_to_fp:v8f32 VR256X:v8i32:$src)  =>  (VCVTUDQ2PSZ256rr:v8f32 VR256X:v8i32:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTUDQ2PSZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable609\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable609, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable610[] = {
    GIM_CheckFeatures, GIFBS_HasDQI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_UITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR512RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // (uint_to_fp:v8f64 VR512:v8i64:$src)  =>  (VCVTUQQ2PDZrr:v8f64 VR512:v8i64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTUQQ2PDZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable610\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable610, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable611[] = {
    GIM_CheckFeatures, GIFBS_HasDQI_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_UITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v2s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR128XRegClassID,
    // (uint_to_fp:v2f64 VR128X:v2i64:$src)  =>  (VCVTUQQ2PDZ128rr:v2f64 VR128X:v2i64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTUQQ2PDZ128rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable611\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable611, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable612[] = {
    GIM_CheckFeatures, GIFBS_HasDQI_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_UITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // (uint_to_fp:v4f64 VR256X:v4i64:$src)  =>  (VCVTUQQ2PDZ256rr:v4f64 VR256X:v4i64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTUQQ2PDZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable612\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable612, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable613[] = {
    GIM_CheckFeatures, GIFBS_HasDQI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_UITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v8s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR256XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v8s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR512RegClassID,
    // (uint_to_fp:v8f32 VR512:v8i64:$src)  =>  (VCVTUQQ2PSZrr:v8f32 VR512:v8i64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTUQQ2PSZrr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable613\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable613, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable614[] = {
    GIM_CheckFeatures, GIFBS_HasDQI_HasVLX,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_UITOFP,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_v4s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::VR128XRegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_v4s64, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::VR256XRegClassID,
    // (uint_to_fp:v4f32 VR256X:v4i64:$src)  =>  (VCVTUQQ2PSZ256rr:v4f32 VR256X:v4i64:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::VCVTUQQ2PSZ256rr,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable614\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable614, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable615[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ZEXT,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s16, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s16, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v16s1, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VK16RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (zext:i32 (bitconvert:i16 VK16:v16i1:$src))  =>  (KMOVWrk:i32 VK16:v16i1:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::KMOVWrk,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable615\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable615, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable616[] = {
    GIM_CheckFeatures, GIFBS_HasDQI,
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_RecordInsn, /*DefineMI*/1, /*MI*/0, /*OpIdx*/1, // MIs[1]
    GIM_CheckNumOperands, /*MI*/1, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ZEXT,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] Operand 1
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s8, 
    GIM_CheckOpcode, /*MI*/1, TargetOpcode::G_BITCAST,
    // MIs[1] Operand 0
    GIM_CheckType, /*MI*/1, /*Op*/0, /*Type*/GILLT_s8, 
    // MIs[1] src
    GIM_CheckType, /*MI*/1, /*Op*/1, /*Type*/GILLT_v8s1, 
    GIM_CheckRegBankForClass, /*MI*/1, /*Op*/1, /*RC*/X86::VK8RegClassID,
    GIM_CheckIsSafeToFold, /*InsnID*/1,
    // (zext:i32 (bitconvert:i8 VK8:v8i1:$src))  =>  (KMOVBrk:i32 VK8:v8i1:$src)
    GIR_BuildMI, /*InsnID*/0, /*Opcode*/X86::KMOVBrk,
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/0, /*OpIdx*/0, // dst
    GIR_Copy, /*NewInsnID*/0, /*OldInsnID*/1, /*OpIdx*/1, // src
    GIR_MergeMemOperands, /*InsnID*/0,
    GIR_EraseFromParent, /*InsnID*/0,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable616\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable616, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable617[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ZEXT,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s8, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR8RegClassID,
    // (zext:i32 GR8:i8:$src)  =>  (MOVZX32rr8:i32 GR8:i8:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::MOVZX32rr8,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable617\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable617, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable618[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/2,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_ZEXT,
    // MIs[0] dst
    GIM_CheckType, /*MI*/0, /*Op*/0, /*Type*/GILLT_s32, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/0, /*RC*/X86::GR32RegClassID,
    // MIs[0] src
    GIM_CheckType, /*MI*/0, /*Op*/1, /*Type*/GILLT_s16, 
    GIM_CheckRegBankForClass, /*MI*/0, /*Op*/1, /*RC*/X86::GR16RegClassID,
    // (zext:i32 GR16:i16:$src)  =>  (MOVZX32rr16:i32 GR16:i16:$src)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::MOVZX32rr16,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable618\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable618, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  const static int64_t MatchTable619[] = {
    GIM_CheckNumOperands, /*MI*/0, /*Expected*/1,
    GIM_CheckOpcode, /*MI*/0, TargetOpcode::G_BR,
    // MIs[0] dst
    GIM_CheckIsMBB, /*MI*/0, /*Op*/0,
    // (br (bb:Other):$dst)  =>  (JMP_1 (bb:Other):$dst)
    GIR_MutateOpcode, /*InsnID*/0, /*RecycleInsnID*/ 0, /*Opcode*/X86::JMP_1,
    GIR_ConstrainSelectedInstOperands, /*InsnID*/0,
    GIR_Done,
  };
  State.MIs.resize(1);
  DEBUG(dbgs() << "Processing MatchTable619\n");
  if (executeMatchTable(*this, OutMIs, State, MatcherInfo, MatchTable619, TII, MRI, TRI, RBI, AvailableFeatures)) {
    return true;
  }

  return false;
}
#endif // ifdef GET_GLOBALISEL_IMPL
#ifdef GET_GLOBALISEL_PREDICATES_DECL
PredicateBitset AvailableModuleFeatures;
mutable PredicateBitset AvailableFunctionFeatures;
PredicateBitset getAvailableFeatures() const {
  return AvailableModuleFeatures | AvailableFunctionFeatures;
}
PredicateBitset
computeAvailableModuleFeatures(const X86Subtarget *Subtarget) const;
PredicateBitset
computeAvailableFunctionFeatures(const X86Subtarget *Subtarget,
                                 const MachineFunction *MF) const;
#endif // ifdef GET_GLOBALISEL_PREDICATES_DECL
#ifdef GET_GLOBALISEL_PREDICATES_INIT
AvailableModuleFeatures(computeAvailableModuleFeatures(&STI)),
AvailableFunctionFeatures()
#endif // ifdef GET_GLOBALISEL_PREDICATES_INIT
