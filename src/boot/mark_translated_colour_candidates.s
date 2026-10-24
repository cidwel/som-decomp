; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

quantize_component_cube_index = $83E2

.segment "CODE"
.org $8444
mark_translated_colour_candidates:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0009
    tcd
    tcs
    stx $06
    lda a:$0018
    sta $04
    lda a:$001A
    sta $08
    stz $02
    sep #$20
    .a8
    lda #$E8
    sta $01
mark_translated_colour_candidates_8463:
    .i16
    ldy #$0000
    .i16
    ldx #$0003
mark_translated_colour_candidates_8469:
    lda ($08),Y
    clc
    adc ($06),Y
    .a8
    bit #$E0
    bne mark_translated_colour_candidates_848e
    sta ($04),Y
    iny
    dex
    bne mark_translated_colour_candidates_8469
    ldx $04
    jsr quantize_component_cube_index
    lda f:$7F8000,X
    bne mark_translated_colour_candidates_848e
    .a8
    lda #$F7
    sec
    sbc $01
    sta f:$7F8000,X
    inc $02
mark_translated_colour_candidates_848e:
    rep #$20
    lda $08
    clc
    .a16
    adc #$0004
    sta $08
    sep #$20
    dec $01
    bne mark_translated_colour_candidates_8463
    rep #$20
    lda $02
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
