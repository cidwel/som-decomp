.setcpu "65816"
.segment "CODE"
.org $B3A3
.include "source_recovery_parallel_ai_entry_frontier_macros.inc"
ai_pc_648e:
    ai_if_word_and_z_bb_long $0080, $0010, $0060, $0041, $648E, $6515
ai_pc_6495:
    ai_if_word_and_z_bb_short $0080, $0010, $0040, $0000, $6495, $64AF
ai_pc_649b:
    ai_if_word_and_z_bb_short $0080, $0010, $0040, $0000, $649B, $64A6
ai_pc_64a1:
    ai_turn_facing_e3 $0013, $0000
ai_pc_64a4:
    ai_jmp_01_short $64A4, $649B
ai_pc_64a6:
    ai_turn_facing_e3 $0014, $0000
ai_pc_64a9:
    ai_jmp_01_long $64A9, $6515
