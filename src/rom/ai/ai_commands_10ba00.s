.setcpu "65816"
.segment "CODE"
.org $BA00
.include "ai_command_macros.inc"
ai_pc_6aeb:
    ai_if_no_hero_32_49_short $6AEB, $6AF3
ai_pc_6aed:
    ai_tgt_within_32_b1
ai_pc_6aee:
    ai_jmp_01_long $6AEE, $6B0E
