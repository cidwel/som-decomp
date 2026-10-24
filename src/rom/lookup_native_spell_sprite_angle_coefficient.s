; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-trigonometry.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $48D9
lookup_native_spell_sprite_angle_coefficient:
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
    rep #$20
    stz $01
    .a16
    and #$00FF
    .a16
    bit #$0080
    beq lookup_native_spell_sprite_angle_coefficient_c148ff
    sec
    .a16
    sbc #$0080
    beq lookup_native_spell_sprite_angle_coefficient_c148ff
    dec $01
lookup_native_spell_sprite_angle_coefficient_c148ff:
    .a16
    bit #$0040
    beq lookup_native_spell_sprite_angle_coefficient_c1490c
    sec
    .a16
    sbc #$0080
    .a16
    eor #$FFFF
    inc
lookup_native_spell_sprite_angle_coefficient_c1490c:
    asl
    tax
    lda f:$DCFEA8,X
    asl $01
    bcc lookup_native_spell_sprite_angle_coefficient_c14919
    .a16
    ora #$FF00
lookup_native_spell_sprite_angle_coefficient_c14919:
    plb
    sep #$20
    sta $02,S
    pla
    pla
    plp
    pld
    rts
