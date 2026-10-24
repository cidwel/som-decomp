; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121

ACTOR_SECOND_TARGET = $01AD

.segment "CODE"
.org $164F
actor_script_clear_second_target:
    .a8
    lda #$FF
    sta a:ACTOR_SECOND_TARGET,Y
    jmp advance_actor_script_1_bytes
