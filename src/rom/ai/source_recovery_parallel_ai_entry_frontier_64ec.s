.setcpu "65816"
.segment "CODE"
.org $B401
.include "source_recovery_parallel_ai_entry_frontier_macros.inc"
ai_pc_64ec:
    ai_if_word_and_z_bb_short $0080, $0010, $0000, $0001, $64EC, $6502
ai_pc_64f2:
    ai_if_word_and_z_bb_short $0080, $0010, $0000, $0001, $64F2, $64FD
ai_pc_64f8:
    ai_turn_facing_e3 $0000, $0000
ai_pc_64fb:
    ai_jmp_01_short $64FB, $64F2
ai_pc_64fd:
    ai_jmp_01_long $64FD, $6515
