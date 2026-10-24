; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $83E2
quantize_component_cube_index:
    phd
    php
    rep #$30
    phx
    tsc
    tcd
    lda a:$0000,X
    .a16
    and #$001E
    lsr
    sta $01
    lda a:$0001,X
    .a16
    and #$001E
    asl
    asl
    asl
    ora $01
    sta $01
    lda a:$0002,X
    .a16
    and #$001E
    xba
    lsr
    ora $01
    tax
    sep #$20
    pla
    pla
    plp
    pld
    rts
