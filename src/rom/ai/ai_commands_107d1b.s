.setcpu "65816"
.segment "CODE"
.org $7D1B
.include "ai_command_macros.inc"
ai_pc_2e06:
    ai_call_ff $6AE1
ai_pc_2e09:
    ai_if_tgt_not_within_32_4c_short $2E09, $2E10
ai_pc_2e0b:
    ai_call_ff $2E38
ai_pc_2e0e:
    ai_jmp_01_short $2E0E, $2E21
ai_pc_2e10:
    ai_if_tgt_not_within_48_51_short $2E10, $2E17
ai_pc_2e12:
    ai_call_ff $2E53
ai_pc_2e15:
    ai_jmp_01_short $2E15, $2E21
ai_pc_2e17:
    ai_if_tgt_not_within_64_56_short $2E17, $2E1E
ai_pc_2e19:
    ai_call_ff $2E67
ai_pc_2e1c:
    ai_jmp_01_short $2E1C, $2E21
ai_pc_2e1e:
    ai_call_ff $2EB2
ai_pc_2e21:
    ai_ret_00
ai_pc_2e22:
    ai_pose_e2 $0007
ai_pc_2e24:
    ai_call_ff $6AE1
ai_pc_2e27:
    ai_pose_e2 $0007
ai_pc_2e29:
    ai_if_field_gt_30_long $0080, $0002, $0035, $2E29, $2FB2
ai_pc_2e2f:
    ai_jmp_01_long $2E2F, $2E34
