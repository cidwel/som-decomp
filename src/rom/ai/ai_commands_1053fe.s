.setcpu "65816"
.segment "CODE"
.org $53FE
.include "ai_command_macros.inc"
ai_pc_04e9:
    ai_pose_e2 $0004
ai_pc_04eb:
    ai_call_ff $6AE1
ai_pc_04ee:
    ai_pose_e2 $0004
ai_pc_04f0:
    ai_if_word_gt_bd_short $0080, $0002, $003F, $0000, $04F0, $04F9
ai_pc_04f6:
    ai_jmp_01_long $04F6, $04FB
ai_pc_04f9:
    ai_if_tgt_not_within_48_51_short $04F9, $04EB
ai_pc_04fb:
    ai_pose_e2 $0005
ai_pc_04fd:
    ai_ret_00
