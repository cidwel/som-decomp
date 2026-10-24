.setcpu "65816"
.segment "CODE"
.org $B3DE
.include "source_recovery_parallel_ai_entry_frontier_macros.inc"
ai_pc_64c9:
    ai_if_word_and_z_bb_short $0080, $0010, $0000, $0040, $64C9, $64EC
ai_pc_64cf:
    ai_if_word_and_z_bb_short $0080, $0010, $0000, $0040, $64CF, $64E7
ai_pc_64d5:
    ai_hop_e0 $0008, $0000, $0005
ai_pc_64d9:
    ai_hop_e0 $0001, $0000, $0005
ai_pc_64dd:
    ai_hop_e0 $0004, $0000, $0005
ai_pc_64e1:
    ai_hop_e0 $0002, $0000, $0005
ai_pc_64e5:
    ai_jmp_01_short $64E5, $64CF
ai_pc_64e7:
    ai_jmp_01_long $64E7, $6515
