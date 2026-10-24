.setcpu "65816"
.segment "CODE"
.org $B28D
.include "source_recovery_parallel_ai_status_frontier_macros.inc"
ai_pc_6378:
    ai_if_word_and_z_bb_long $0080, $0010, $0060, $0057, $6378, $648D
ai_pc_637f:
    ai_if_word_and_z_bb_short $0080, $0010, $0040, $0000, $637F, $6396
ai_pc_6385:
    ai_if_word_and_z_bb_short $0080, $0010, $0040, $0000, $6385, $6390
ai_pc_638b:
    ai_turn_facing_e3 $0000, $0000
ai_pc_638e:
    ai_jmp_01_short $638E, $6385
ai_pc_6390:
    ai_jmp_01_long $6390, $648D
