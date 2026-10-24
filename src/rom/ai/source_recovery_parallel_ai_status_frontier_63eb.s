.setcpu "65816"
.segment "CODE"
.org $B300
.include "source_recovery_parallel_ai_status_frontier_macros.inc"
ai_pc_63eb:
    ai_if_word_and_z_bb_short $0080, $0010, $0000, $0010, $63EB, $640A
ai_pc_63f1:
    ai_call_ff $5913
ai_pc_63f4:
    ai_if_tgt_not_within_64_56_short $63F4, $63FB
ai_pc_63f6:
    ai_call_ff $5A0D
ai_pc_63f9:
    ai_jmp_01_short $63F9, $63FE
ai_pc_63fb:
    ai_move_toward_e4 $0000, $0005
ai_pc_63fe:
    ai_if_word_and_nz_ba_short $0080, $0010, $0000, $0010, $63FE, $63F1
ai_pc_6404:
    ai_jmp_01_long $6404, $648D
