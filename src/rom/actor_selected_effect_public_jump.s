; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

actor_selected_effect_public_jump_mirror = $380C

.segment "CODE"
.org $0024
actor_selected_effect_public_jump:
    jmp actor_selected_effect_public_jump_mirror
