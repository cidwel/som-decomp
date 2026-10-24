.setcpu "65816"
.segment "CODE"
.org $BA0E
.include "ai_command_macros.inc"
ai_pc_6af9:
    ai_if_no_hero_64_53_short $6AF9, $6B01
ai_pc_6afb:
    ai_tgt_within_64_b7
ai_pc_6afc:
    ai_jmp_01_long $6AFC, $6B0E
