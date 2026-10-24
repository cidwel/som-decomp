.setcpu "65816"
.segment "CODE"
.org $A3EB
.include "source_recovery_parallel_ai_entry_frontier_macros.inc"
ai_pc_54d6:
    ai_call_ff $54EC
ai_pc_54d9:
    ai_hop_e0 $0004, $0000, $000A
ai_pc_54dd:
    ai_hop_e0 $0001, $0000, $000A
ai_pc_54e1:
    ai_hop_e0 $0008, $0000, $000A
ai_pc_54e5:
    ai_hop_e0 $0002, $0000, $000A
ai_pc_54e9:
    ai_jmp_01_short $54E9, $54D9
