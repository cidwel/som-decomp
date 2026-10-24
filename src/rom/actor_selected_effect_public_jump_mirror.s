; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

actor_selected_effect_native_long_jump = $386E

.segment "CODE"
.org $380C
actor_selected_effect_public_jump_mirror:
    jmp actor_selected_effect_native_long_jump
