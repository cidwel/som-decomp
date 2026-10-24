; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C915
allocate_copy_queue_record:
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
    ldx a:$02F8
    beq allocate_copy_queue_record_c936
    php
    sei
    lda a:$0000,X
    sta a:$02F8
    .a16
    lda #$007F
    sta a:$0003,X
    plp
allocate_copy_queue_record_c936:
    plb
    plp
    pld
    rts
