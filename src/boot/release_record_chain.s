; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

release_eight_byte_record = $B1DD
take_record_link = $B20B

.segment "CODE"
.org $B23A
release_record_chain:
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
    php
    sei
release_record_chain_b249:
    jsr take_record_link
    pha
    jsr release_eight_byte_record
    plx
    bne release_record_chain_b249
    plp
    plb
    plp
    pld
    rts
