; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

refresh_actor_appearance_native = $457C

.segment "CODE"
.org $3824
refresh_actor_appearance_public_jump_mirror:
    jmp refresh_actor_appearance_native
