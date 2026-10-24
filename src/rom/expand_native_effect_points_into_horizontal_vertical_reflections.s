; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-effect-point-layout.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $924C
expand_native_effect_points_into_horizontal_vertical_reflections:
    rep #$20
    txa
    lsr
    tax
    lda a:$C026,X
    sta a:$C062,X
    sta a:$C066,X
    sta a:$C06A,X
    lda a:$C024,X
    sta a:$C06C,X
    lda a:$C000,X
    clc
    .a16
    adc #$0F00
    .a16
    eor #$FF00
    sta a:$C024,X
    lda a:$C002,X
    .a16
    eor #$8000
    sta a:$C026,X
    lda a:$C004,X
    clc
    .a16
    adc #$0F00
    .a16
    eor #$FF00
    sta a:$C028,X
    lda a:$C006,X
    .a16
    eor #$8000
    sta a:$C02A,X
    lda a:$C008,X
    clc
    .a16
    adc #$0F00
    .a16
    eor #$FF00
    sta a:$C02C,X
    lda a:$C00A,X
    .a16
    eor #$8000
    sta a:$C02E,X
    lda a:$C00C,X
    pha
    clc
    .a16
    adc #$0F00
    .a16
    eor #$FF00
    sta a:$C048,X
    pla
    sep #$20
    clc
    .a8
    adc #$0F
    .a8
    eor #$FF
    rep #$20
    sta a:$C030,X
    clc
    .a16
    adc #$0F00
    .a16
    eor #$FF00
    sta a:$C054,X
    lda a:$C00E,X
    .a16
    eor #$4000
    sta a:$C032,X
    .a16
    eor #$C000
    sta a:$C04A,X
    .a16
    eor #$4000
    sta a:$C056,X
    lda a:$C010,X
    pha
    clc
    .a16
    adc #$0F00
    .a16
    eor #$FF00
    sta a:$C04C,X
    pla
    sep #$20
    clc
    .a8
    adc #$0F
    .a8
    eor #$FF
    rep #$20
    sta a:$C034,X
    clc
    .a16
    adc #$0F00
    .a16
    eor #$FF00
    sta a:$C058,X
    lda a:$C012,X
    .a16
    eor #$4000
    sta a:$C036,X
    .a16
    eor #$C000
    sta a:$C04E,X
    .a16
    eor #$4000
    sta a:$C05A,X
    lda a:$C014,X
    pha
    clc
    .a16
    adc #$0F00
    .a16
    eor #$FF00
    sta a:$C050,X
    pla
    sep #$20
    clc
    .a8
    adc #$0F
    .a8
    eor #$FF
    rep #$20
    sta a:$C038,X
    clc
    .a16
    adc #$0F00
    .a16
    eor #$FF00
    sta a:$C05C,X
    lda a:$C016,X
    .a16
    eor #$4000
    sta a:$C03A,X
    .a16
    eor #$C000
    sta a:$C052,X
    .a16
    eor #$4000
    sta a:$C05E,X
    lda a:$C018,X
    sep #$20
    clc
    .a8
    adc #$0F
    .a8
    eor #$FF
    rep #$20
    sta a:$C03C,X
    lda a:$C01A,X
    .a16
    eor #$4000
    sta a:$C03E,X
    lda a:$C01C,X
    sep #$20
    clc
    .a8
    adc #$0F
    .a8
    eor #$FF
    rep #$20
    sta a:$C040,X
    lda a:$C01E,X
    .a16
    eor #$4000
    sta a:$C042,X
    lda a:$C020,X
    sep #$20
    clc
    .a8
    adc #$0F
    .a8
    eor #$FF
    rep #$20
    sta a:$C044,X
    lda a:$C022,X
    .a16
    eor #$4000
    sta a:$C046,X
    rtl
