; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C93A
release_copy_queue_record:
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
    beq release_copy_queue_record_c956
    php
    sei
    lda a:$02F8
    sta a:$0000,X
    stx a:$02F8
    plp
release_copy_queue_record_c956:
    plb
    plp
    pld
    rts
