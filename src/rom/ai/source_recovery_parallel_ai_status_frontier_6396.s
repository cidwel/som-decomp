.setcpu "65816"
.segment "CODE"
.org $B2AB
.include "source_recovery_parallel_ai_status_frontier_macros.inc"
ai_pc_6396:
    ai_if_word_and_z_bb_short $0080, $0010, $0020, $0000, $6396, $63B0
ai_pc_639c:
    ai_if_word_and_z_bb_short $0080, $0010, $0020, $0000, $639C, $63A7
ai_pc_63a2:
    ai_turn_facing_e3 $0000, $0000
ai_pc_63a5:
    ai_jmp_01_short $63A5, $639C
ai_pc_63a7:
    ai_turn_facing_e3 $0001, $000A
ai_pc_63aa:
    ai_jmp_01_long $63AA, $648D
