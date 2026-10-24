; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

jump_actor_script_after_5_bytes = $02AB
resolve_actor_script_field_reference = $1FEB
skip_actor_script_after_5_bytes = $0239

ACTOR_PROGRAM_PC = $0144
ACTOR_FIELD_BASE = $0180
ACTOR_SCRIPT_FIELD_VALUE = $D04F18

.segment "CODE"
.org $20F2
actor_script_if_word_field_greater:
    rep #$20
    jsr resolve_actor_script_field_reference
    lda a:ACTOR_FIELD_BASE,X
    ldx a:ACTOR_PROGRAM_PC,Y
    cmp f:ACTOR_SCRIPT_FIELD_VALUE,X
    beq actor_script_if_word_field_greater_c12105
    bcs actor_script_if_word_field_greater_c1210a
actor_script_if_word_field_greater_c12105:
    jsr skip_actor_script_after_5_bytes
    bra actor_script_if_word_field_greater_c1210d
actor_script_if_word_field_greater_c1210a:
    jsr jump_actor_script_after_5_bytes
actor_script_if_word_field_greater_c1210d:
    rts
