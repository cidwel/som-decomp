.setcpu "65816"
.segment "CODE"
.org $5F9E
.include "ai_command_macros.inc"
ai_pc_1089:
    ai_if_tgt_not_lane_h_73_short $1089, $1090
ai_pc_108b:
    ai_jmp_01_long $108B, $109B
