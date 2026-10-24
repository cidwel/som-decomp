.setcpu "65816"
.segment "CODE"
.org $B417
.include "source_recovery_parallel_ai_entry_frontier_macros.inc"
ai_pc_6502:
    ai_hop_e0 $0008, $0000, $0005
ai_pc_6506:
    ai_hop_e0 $0001, $0000, $0005
ai_pc_650a:
    ai_hop_e0 $0004, $0000, $0005
ai_pc_650e:
    ai_hop_e0 $0002, $0000, $0005
ai_pc_6512:
    ai_jmp_01_long $6512, $648E
ai_pc_6515:
    ai_ret_00
