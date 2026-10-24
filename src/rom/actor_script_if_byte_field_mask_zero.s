; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

jump_actor_script_after_4_bytes = $02A0
resolve_actor_script_field_reference = $1FEB
skip_actor_script_after_4_bytes = $022E

ACTOR_PROGRAM_PC = $0144
ACTOR_FIELD_BASE = $0180
ACTOR_SCRIPT_FIELD_VALUE = $D04F18

.segment "CODE"
.org $205A
actor_script_if_byte_field_mask_zero:
    jsr resolve_actor_script_field_reference
    lda a:ACTOR_FIELD_BASE,X
    ldx a:ACTOR_PROGRAM_PC,Y
    and f:ACTOR_SCRIPT_FIELD_VALUE,X
    beq actor_script_if_byte_field_mask_zero_c1206e
    jsr skip_actor_script_after_4_bytes
    bra actor_script_if_byte_field_mask_zero_c12071
actor_script_if_byte_field_mask_zero_c1206e:
    jsr jump_actor_script_after_4_bytes
actor_script_if_byte_field_mask_zero_c12071:
    rts
