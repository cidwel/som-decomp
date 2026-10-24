.setcpu "65816"
.segment "CODE"
.org $B2C5
.include "source_recovery_parallel_ai_status_frontier_macros.inc"
ai_pc_63b0:
    ai_if_word_and_z_bb_short $0080, $0010, $0000, $0040, $63B0, $63D4
ai_pc_63b6:
    ai_if_word_and_z_bb_short $0080, $0010, $0000, $0040, $63B6, $63CE
ai_pc_63bc:
    ai_hop_e0 $0004, $0000, $0005
ai_pc_63c0:
    ai_hop_e0 $0001, $0000, $0005
ai_pc_63c4:
    ai_hop_e0 $0004, $0000, $0005
ai_pc_63c8:
    ai_hop_e0 $0002, $0000, $0005
ai_pc_63cc:
    ai_jmp_01_short $63CC, $63B6
ai_pc_63ce:
    ai_jmp_01_long $63CE, $648D
