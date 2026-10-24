.setcpu "65816"
.segment "CODE"
.org $B2E9
.include "source_recovery_parallel_ai_status_frontier_macros.inc"
ai_pc_63d4:
    ai_if_word_and_z_bb_short $0080, $0010, $0000, $0001, $63D4, $63EB
ai_pc_63da:
    ai_if_word_and_z_bb_short $0080, $0010, $0000, $0001, $63DA, $63E5
ai_pc_63e0:
    ai_turn_facing_e3 $0000, $0000
ai_pc_63e3:
    ai_jmp_01_short $63E3, $63DA
ai_pc_63e5:
    ai_jmp_01_long $63E5, $648D
