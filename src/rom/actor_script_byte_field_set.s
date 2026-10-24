; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_script_4_bytes = $014B
resolve_actor_script_field_reference = $1FEB

ACTOR_PROGRAM_PC = $0144
ACTOR_FIELD_BASE = $0180
ACTOR_SCRIPT_FIELD_VALUE = $D04F18

.segment "CODE"
.org $213A
actor_script_byte_field_set:
    jsr resolve_actor_script_field_reference
    phx
    ldx a:ACTOR_PROGRAM_PC,Y
    lda f:ACTOR_SCRIPT_FIELD_VALUE,X
    plx
    sta a:ACTOR_FIELD_BASE,X
    jmp advance_actor_script_4_bytes
