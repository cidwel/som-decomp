.setcpu "65816"
.segment "CODE"
.org $B39B
.include "source_recovery_parallel_ai_status_frontier_macros.inc"
ai_pc_6486:
    ai_hop_e0 $0004, $0027, $0000
ai_pc_648a:
    ai_jmp_01_long $648A, $6378
ai_pc_648d:
    ai_ret_00
