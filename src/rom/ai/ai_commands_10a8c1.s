.setcpu "65816"
.segment "CODE"
.org $A8C1
.include "ai_command_macros.inc"
ai_pc_59ac:
    ai_if_pos_same_9d_short $59AC, $59B4
ai_pc_59ae:
    ai_pos_save_9f
ai_pc_59af:
    ai_move_away_card_bf $000A, $000A
ai_pc_59b2:
    ai_jmp_01_short $59B2, $59B8
ai_pc_59b4:
    ai_pos_save_9f
ai_pc_59b5:
    ai_move_away_alt_fe $000A, $000A
ai_pc_59b8:
    ai_ret_00
ai_pc_59b9:
    ai_if_pos_same_9d_short $59B9, $59C1
ai_pc_59bb:
    ai_pos_save_9f
ai_pc_59bc:
    ai_move_away_card_bf $000A, $0005
ai_pc_59bf:
    ai_jmp_01_short $59BF, $59C5
ai_pc_59c1:
    ai_pos_save_9f
ai_pc_59c2:
    ai_move_away_alt_fe $000A, $0005
ai_pc_59c5:
    ai_ret_00
