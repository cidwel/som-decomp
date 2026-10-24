; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-region-gate.md.
.setcpu "65816"
.smart
.a8
.i16

expand_title_text_row = $8820

.segment "CODE"
.org $8EA6
render_three_native_region_error_rows:
    phd
    php
    rep #$30
    phx
    tsc
    tcd
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    txa
    sta $01
    clc
    .a16
    adc #$03C0
    tay
    .i16
    ldx #$0215
    jsr expand_title_text_row
    lda $01
    clc
    .a16
    adc #$0440
    tay
    jsr expand_title_text_row
    lda $01
    clc
    .a16
    adc #$04C0
    tay
    jsr expand_title_text_row
    plb
    sep #$20
    pla
    pla
    plp
    pld
    rts
