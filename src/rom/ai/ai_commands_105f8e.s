.setcpu "65816"
.segment "CODE"
.org $5F8E
.include "ai_command_macros.inc"
ai_pc_1079:
    ai_turn_facing_e3 $0000, $0005
ai_pc_107c:
    ai_call_ff $6AE1
ai_pc_107f:
    ai_turn_facing_e3 $0000, $0005
ai_pc_1082:
    ai_if_tgt_not_lane_v_6a_short $1082, $1089
ai_pc_1084:
    ai_jmp_01_long $1084, $109B
