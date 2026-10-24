; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A615
read_input_interface_a615:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    sep #$20
    phb
    .a8
    lda #$00
    pha
    plb
    rep #$20
    stz $02
    stz $04
    lda f:$00421A
    sta $02
    lda $04
    sta a:$0094
    lda $02
    plb
    sep #$20
    sta $04,S
    pla
    pla
    pla
    pla
    plp
    pld
    rts
