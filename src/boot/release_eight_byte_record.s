; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B1DD
release_eight_byte_record:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    .i16
    cpx #$0000
    beq release_eight_byte_record_b207
    .i16
    cpx #$FFFF
    beq release_eight_byte_record_b207
    php
    sei
    lda a:$02C6
    sta a:$0000,X
    sep #$20
    stz a:$0002,X
    rep #$20
    stx a:$02C6
    plp
release_eight_byte_record_b207:
    plb
    plp
    pld
    rts
