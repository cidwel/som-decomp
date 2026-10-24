.setcpu "65816"
.segment "CODE"
.org $7E1B
.include "ai_command_macros.inc"
ai_pc_2f06:
    ai_if_tgt_not_lane_h64_6f_short $2F06, $2F13
ai_pc_2f08:
    ai_move_toward_card_be $0000, $0000
ai_pc_2f0b:
    ai_call_ff $6B19
ai_pc_2f0e:
    ai_jmp_01_long $2F0E, $2F18
