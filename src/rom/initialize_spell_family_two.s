; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-mode-two.md.
.setcpu "65816"
.smart
.a8
.i16

construct_spell_family_two_object = $F9B1
construct_spell_graphics_audio_resources_long = $C12E90
draw_spell_entity_bounded_random_long = $C12ED1
initialize_spell_random_fallback_long = $D3FD3F

.segment "CODE"
.org $F92B
initialize_spell_family_two:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0008
    tcd
    tcs
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$20
    sty $02
    .a16
    lda #$0040
    jsl f:draw_spell_entity_bounded_random_long
    ldy $02
    tax
    bne initialize_spell_family_two_dcf953
    jsl f:initialize_spell_random_fallback_long
    bra initialize_spell_family_two_dcf9a5
initialize_spell_family_two_dcf953:
    .i16
    ldx #$F8D7
    jsl f:construct_spell_graphics_audio_resources_long
    stx $07
    txa
    ldx $02
    sta a:$001A,X
    .a16
    lda #$010E
    sta a:$002A,X
    .a16
    lda #$3711
    sta a:$001C,X
    .a16
    lda #$345A
    sta a:$001E,X
    sep #$20
    lda a:$0027,X
    sta $01
initialize_spell_family_two_dcf97b:
    stx $04
    lda a:$0000,X
    ldx $07
    jsr construct_spell_family_two_object
    rep #$20
    txa
    ldx $04
    sta a:$0002,X
    .a16
    lda #$2C01
    sta a:$0004,X
    .a16
    lda #$2BFC
    sta a:$0006,X
    clc
    txa
    .a16
    adc #$0008
    tax
    sep #$20
    dec $01
    bne initialize_spell_family_two_dcf97b
initialize_spell_family_two_dcf9a5:
    plb
    rep #$20
    tsc
    clc
    .a16
    adc #$0008
    tcs
    plp
    pld
    rts
