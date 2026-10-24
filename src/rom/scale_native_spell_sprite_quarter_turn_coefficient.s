; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trigonometry.md.
.setcpu "65816"
.smart
.a8
.i16

lookup_native_spell_sprite_quarter_turn_coefficient = $4923

.segment "CODE"
.org $4993
scale_native_spell_sprite_quarter_turn_coefficient:
    phd
    php
    rep #$30
    pha
    tsc
    tcd
    pla
    phx
    sep #$20
    phb
    pha
    .a8
    lda #$7E
    pha
    plb
    pla
    xba
    sta $02
    xba
    jsr lookup_native_spell_sprite_quarter_turn_coefficient
    .a8
    cmp #$00
    beq scale_native_spell_sprite_quarter_turn_coefficient_c149d4
    xba
    sta $01
    xba
    xba
    lda $02
    xba
    rep #$20
    sta f:$004202
    pha
    pla
    lda f:$004216
    sep #$20
    asl $01
    bcc scale_native_spell_sprite_quarter_turn_coefficient_c149e4
    rep #$20
    .a16
    eor #$FFFF
    inc
    sep #$20
    bra scale_native_spell_sprite_quarter_turn_coefficient_c149e4
scale_native_spell_sprite_quarter_turn_coefficient_c149d4:
    xba
    bmi scale_native_spell_sprite_quarter_turn_coefficient_c149de
    beq scale_native_spell_sprite_quarter_turn_coefficient_c149e4
    lda $02
    xba
    bra scale_native_spell_sprite_quarter_turn_coefficient_c149e4
scale_native_spell_sprite_quarter_turn_coefficient_c149de:
    lda $02
    .a8
    eor #$FF
    inc
    xba
scale_native_spell_sprite_quarter_turn_coefficient_c149e4:
    plb
    sta $02,S
    pla
    pla
    plp
    pld
    rts
