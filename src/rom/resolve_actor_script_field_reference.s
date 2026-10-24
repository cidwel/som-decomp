; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


ACTOR_PROGRAM_PC = $0144
ACTOR_CURRENT_TARGET = $01AC
ACTOR_SECOND_TARGET = $01AD
ACTOR_SCRIPT_FIRST_ARGUMENT = $D04F16
ACTOR_SCRIPT_FIELD_OFFSET = $D04F17

.segment "CODE"
.org $1FEB
resolve_actor_script_field_reference:
    phd
    php
    rep #$20
    phx
    tsc
    tcd
    ldx a:ACTOR_PROGRAM_PC,Y
    lda f:ACTOR_SCRIPT_FIELD_OFFSET,X
    .a16
    and #$00FF
    sta $01
    sep #$20
    lda f:ACTOR_SCRIPT_FIRST_ARGUMENT,X
    .a8
    cmp #$80
    bcc resolve_actor_script_field_reference_c12026
    beq resolve_actor_script_field_reference_c12032
    .a8
    cmp #$82
    bcc resolve_actor_script_field_reference_c12023
    beq resolve_actor_script_field_reference_c1201e
    rep #$20
    tya
    .a16
    and #$0600
    lsr
    xba
    clc
    .a16
    adc #$CA80
    bra resolve_actor_script_field_reference_c12035
resolve_actor_script_field_reference_c1201e:
    lda a:ACTOR_SECOND_TARGET,Y
    bra resolve_actor_script_field_reference_c12026
resolve_actor_script_field_reference_c12023:
    lda a:ACTOR_CURRENT_TARGET,Y
resolve_actor_script_field_reference_c12026:
    asl
    xba
    .a8
    lda #$00
    rep #$20
    clc
    .a16
    adc #$E000
    bra resolve_actor_script_field_reference_c12035
resolve_actor_script_field_reference_c12032:
    rep #$20
    tya
resolve_actor_script_field_reference_c12035:
    clc
    adc $01
    tax
    sep #$20
    sta $02,S
    pla
    pla
    plp
    pld
    rts
