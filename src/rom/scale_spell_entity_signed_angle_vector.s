; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-signed-vectors.md.
.setcpu "65816"
.smart
.a8
.i16

lookup_native_spell_sprite_angle_coefficient = $48D9

.segment "CODE"
.org $49EC
scale_spell_entity_signed_angle_vector:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0007
    tcd
    tcs
    lda $08,S
    sep #$20
    phb
    pha
    .a8
    lda #$7E
    pha
    plb
    pla
    rep #$20
    sta $01
    stz $02
    txa
    bpl scale_spell_entity_signed_angle_vector_c14a12
    .a16
    eor #$FFFF
    inc
    dec $02
scale_spell_entity_signed_angle_vector_c14a12:
    sta $04
    sep #$20
    lda $01
    jsr lookup_native_spell_sprite_angle_coefficient
    .a8
    cmp #$00
    beq scale_spell_entity_signed_angle_vector_c14a7c
    xba
    eor $02
    sta $02
    xba
    sta $09
    xba
    lda $04
    xba
    rep #$20
    sta f:$004202
    pha
    pla
    lda f:$004216
    sep #$20
    asl $02
    rep #$20
    bcc scale_spell_entity_signed_angle_vector_c14a43
    .a16
    eor #$FFFF
    inc
scale_spell_entity_signed_angle_vector_c14a43:
    sta $06
    sep #$20
    stz $08
    xba
    .a8
    and #$80
    beq scale_spell_entity_signed_angle_vector_c14a50
    dec $08
scale_spell_entity_signed_angle_vector_c14a50:
    ldx $07
    lda $05
    beq scale_spell_entity_signed_angle_vector_c14a78
    xba
    lda $09
    xba
    rep #$20
    sta f:$004202
    pha
    pla
    lda f:$004216
    sep #$20
    asl $02
    rep #$20
    bcc scale_spell_entity_signed_angle_vector_c14a72
    .a16
    eor #$FFFF
    inc
scale_spell_entity_signed_angle_vector_c14a72:
    clc
    adc $07
    tax
    sep #$20
scale_spell_entity_signed_angle_vector_c14a78:
    lda $06
    bra scale_spell_entity_signed_angle_vector_c14a99
scale_spell_entity_signed_angle_vector_c14a7c:
    xba
    bmi scale_spell_entity_signed_angle_vector_c14a87
    beq scale_spell_entity_signed_angle_vector_c14a96
    ldx $04
    .a8
    lda #$00
    bra scale_spell_entity_signed_angle_vector_c14a99
scale_spell_entity_signed_angle_vector_c14a87:
    rep #$20
    lda $04
    .a16
    eor #$FFFF
    inc
    tax
    sep #$20
    .a8
    lda #$00
    bra scale_spell_entity_signed_angle_vector_c14a99
scale_spell_entity_signed_angle_vector_c14a96:
    .i16
    ldx #$0000
scale_spell_entity_signed_angle_vector_c14a99:
    plb
    rep #$20
    sta $08,S
    tsc
    clc
    .a16
    adc #$0007
    tcs
    pla
    plp
    pld
    rts
