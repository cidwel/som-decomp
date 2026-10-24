; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $7A02
read_native_item_usability_and_category_bits:
    php
    rep #$30
    .a16
    and #$003F
    asl
    pha
    asl
    asl
    clc
    adc $01,S
    tax
    pla
    sep #$20
    lda f:$D03ED0,X
    .a8
    and #$80
    pha
    lda f:$D03ED5,X
    .a8
    and #$E0
    lsr
    ora $01,S
    tax
    pla
    txa
    plp
    rtl
