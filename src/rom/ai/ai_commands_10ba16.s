.setcpu "65816"
.segment "CODE"
.org $BA16
.include "ai_command_macros.inc"
ai_pc_6b01:
    ai_if_no_hero_onscreen_58_short $6B01, $6B09
ai_pc_6b03:
    ai_tgt_far_5d
ai_pc_6b04:
    ai_jmp_01_long $6B04, $6B0E
