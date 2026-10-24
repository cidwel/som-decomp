; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $AA42
prepare_initial_task_stack:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$00
    pha
    plb
    rep #$20
    .a16
    lda #$AA21
    sta a:$00FA,X
    lda a:$0000,Y
    dec
    sta a:$00F7,X
    lda a:$0004,Y
    dec
    sta a:$00FD,X
    sep #$20
    .a8
    lda #$7E
    sta a:$00FC,X
    lda a:$0002,Y
    sta a:$00F9,X
    sta a:$00FF,X
    plb
    plp
    pld
    rts
