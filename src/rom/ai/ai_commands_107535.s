.setcpu "65816"
.segment "CODE"
.org $7535
.include "ai_command_macros.inc"
ai_pc_2620:
    ai_pose_e2 $0007
ai_pc_2622:
    ai_call_ff $6AE1
ai_pc_2625:
    ai_pose_e2 $0007
ai_pc_2627:
    ai_if_tgt_not_within_64_56_short $2627, $2622
ai_pc_2629:
    ai_pose_e2 $0007
ai_pc_262b:
    ai_call_ff $6AE1
ai_pc_262e:
    ai_pose_e2 $0007
ai_pc_2630:
    ai_if_tgt_not_beyond_64_5a_short $2630, $2637
ai_pc_2632:
    ai_jmp_01_long $2632, $2642
