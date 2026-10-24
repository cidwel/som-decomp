; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

refresh_actor_appearance_public_jump_mirror = $3824

.segment "CODE"
.org $003C
refresh_actor_appearance_public_jump:
    jmp refresh_actor_appearance_public_jump_mirror
