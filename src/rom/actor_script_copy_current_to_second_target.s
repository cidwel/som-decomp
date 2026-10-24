; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_1_bytes = $0121

ACTOR_CURRENT_TARGET = $01AC
ACTOR_SECOND_TARGET = $01AD

.segment "CODE"
.org $1646
actor_script_copy_current_to_second_target:
    lda a:ACTOR_CURRENT_TARGET,Y
    sta a:ACTOR_SECOND_TARGET,Y
    jmp advance_actor_script_1_bytes
