.setcpu "65816"
.segment "CODE"
.org $BA1E
.include "ai_command_macros.inc"
ai_pc_6b09:
    ai_call_ff $67DF
ai_pc_6b0c:
    ai_jmp_01_short $6B0C, $6AE1
ai_pc_6b0e:
    ai_ret_00
ai_pc_6b0f:
    ai_if_field_gt_30_short $0081, $0001, $0019, $6B0F, $6B17
ai_pc_6b14:
    ai_swing_e8
ai_pc_6b15:
    ai_jmp_01_short $6B15, $6B18
ai_pc_6b17:
    ai_swing_e8
ai_pc_6b18:
    ai_ret_00
ai_pc_6b19:
    ai_if_field_gt_30_short $0081, $0001, $0032, $6B19, $6B21
ai_pc_6b1e:
    ai_swing_e8
ai_pc_6b1f:
    ai_jmp_01_short $6B1F, $6B22
ai_pc_6b21:
    ai_swing_e8
ai_pc_6b22:
    ai_ret_00
ai_pc_6b23:
    ai_if_field_gt_30_short $0081, $0001, $004B, $6B23, $6B2B
ai_pc_6b28:
    ai_swing_e8
ai_pc_6b29:
    ai_jmp_01_short $6B29, $6B2C
ai_pc_6b2b:
    ai_swing_e8
ai_pc_6b2c:
    ai_ret_00
ai_pc_6b2d:
    ai_if_field_gt_30_short $0081, $0001, $0062, $6B2D, $6B35
ai_pc_6b32:
    ai_swing_e8
ai_pc_6b33:
    ai_jmp_01_short $6B33, $6B36
ai_pc_6b35:
    ai_swing_e8
ai_pc_6b36:
    ai_ret_00
