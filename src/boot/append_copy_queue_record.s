; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C95A
append_copy_queue_record:
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
    txa
    beq append_copy_queue_record_c981
    php
    sei
    sec
    sbc a:$02F6
    sep #$20
    ldy a:$0300
    sta a:$0000,Y
    stz a:$0000,X
    rep #$20
    stx a:$0300
    plp
append_copy_queue_record_c981:
    plb
    plp
    pld
    rts
