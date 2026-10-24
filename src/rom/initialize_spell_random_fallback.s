; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-mode-two.md.
.setcpu "65816"
.smart
.a8
.i16

construct_spell_graphics_audio_resources_long = $C12E90
construct_spell_random_fallback_object = $FDBD

.segment "CODE"
.org $FD43
initialize_spell_random_fallback:
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
    .a16
    lda #$0001
    sta a:$8434
    sty $02
    .i16
    ldx #$FE72
    jsl f:construct_spell_graphics_audio_resources_long
    stx $07
    txa
    ldx $02
    sta a:$001A,X
    .a16
    lda #$0000
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
initialize_spell_random_fallback_d3fd87:
    stx $04
    lda a:$0000,X
    ldx $07
    jsr construct_spell_random_fallback_object
    rep #$20
    txa
    ldx $04
    sta a:$0002,X
    .a16
    lda #$481A
    sta a:$0004,X
    .a16
    lda #$4815
    sta a:$0006,X
    clc
    txa
    .a16
    adc #$0008
    tax
    sep #$20
    dec $01
    bne initialize_spell_random_fallback_d3fd87
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
