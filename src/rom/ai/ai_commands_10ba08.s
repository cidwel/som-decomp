.setcpu "65816"
.segment "CODE"
.org $BA08
.include "ai_command_macros.inc"
ai_pc_6af3:
    ai_tgt_within_48_b4
ai_pc_6af4:
    ai_jmp_01_long $6AF4, $6B0E
