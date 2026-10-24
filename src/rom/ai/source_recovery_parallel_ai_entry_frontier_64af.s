.setcpu "65816"
.segment "CODE"
.org $B3C4
.include "source_recovery_parallel_ai_entry_frontier_macros.inc"
ai_pc_64af:
    ai_if_word_and_z_bb_short $0080, $0010, $0020, $0000, $64AF, $64C9
ai_pc_64b5:
    ai_if_word_and_z_bb_short $0080, $0010, $0020, $0000, $64B5, $64C0
ai_pc_64bb:
    ai_turn_facing_e3 $0000, $0000
ai_pc_64be:
    ai_jmp_01_short $64BE, $64B5
ai_pc_64c0:
    ai_turn_facing_e3 $0001, $000A
ai_pc_64c3:
    ai_jmp_01_long $64C3, $6515
