.setcpu "65816"
.segment "CODE"
.org $B31F
.include "source_recovery_parallel_ai_status_frontier_macros.inc"
ai_pc_640a:
    ai_if_word_and_z_bb_short $0080, $0010, $0000, $0004, $640A, $6422
ai_pc_6410:
    ai_follow_e1
ai_pc_6411:
    ai_tgt_none_a0
ai_pc_6412:
    ai_tgt2_none_c0
ai_pc_6413:
    ai_if_word_and_nz_ba_short $0080, $0010, $0000, $0004, $6413, $6410
ai_pc_6419:
    ai_call_ff $5913
ai_pc_641c:
    ai_jmp_01_long $641C, $648D
