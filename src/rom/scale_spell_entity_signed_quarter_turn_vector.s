; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-signed-vectors.md.
.setcpu "65816"
.smart
.a8
.i16

lookup_native_spell_sprite_quarter_turn_coefficient = $4923

.segment "CODE"
.org $4AA8
scale_spell_entity_signed_quarter_turn_vector:
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
    bpl scale_spell_entity_signed_quarter_turn_vector_c14ace
    .a16
    eor #$FFFF
    inc
    dec $02
scale_spell_entity_signed_quarter_turn_vector_c14ace:
    sta $04
    sep #$20
    lda $01
    jsr lookup_native_spell_sprite_quarter_turn_coefficient
    .a8
    cmp #$00
    beq scale_spell_entity_signed_quarter_turn_vector_c14b38
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
    bcc scale_spell_entity_signed_quarter_turn_vector_c14aff
    .a16
    eor #$FFFF
    inc
scale_spell_entity_signed_quarter_turn_vector_c14aff:
    sta $06
    sep #$20
    stz $08
    xba
    .a8
    and #$80
    beq scale_spell_entity_signed_quarter_turn_vector_c14b0c
    dec $08
scale_spell_entity_signed_quarter_turn_vector_c14b0c:
    ldx $07
    lda $05
    beq scale_spell_entity_signed_quarter_turn_vector_c14b34
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
    bcc scale_spell_entity_signed_quarter_turn_vector_c14b2e
    .a16
    eor #$FFFF
    inc
scale_spell_entity_signed_quarter_turn_vector_c14b2e:
    clc
    adc $07
    tax
    sep #$20
scale_spell_entity_signed_quarter_turn_vector_c14b34:
    lda $06
    bra scale_spell_entity_signed_quarter_turn_vector_c14b55
scale_spell_entity_signed_quarter_turn_vector_c14b38:
    xba
    bmi scale_spell_entity_signed_quarter_turn_vector_c14b43
    beq scale_spell_entity_signed_quarter_turn_vector_c14b52
    ldx $04
    .a8
    lda #$00
    bra scale_spell_entity_signed_quarter_turn_vector_c14b55
scale_spell_entity_signed_quarter_turn_vector_c14b43:
    rep #$20
    lda $04
    .a16
    eor #$FFFF
    inc
    tax
    sep #$20
    .a8
    lda #$00
    bra scale_spell_entity_signed_quarter_turn_vector_c14b55
scale_spell_entity_signed_quarter_turn_vector_c14b52:
    .i16
    ldx #$0000
scale_spell_entity_signed_quarter_turn_vector_c14b55:
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
