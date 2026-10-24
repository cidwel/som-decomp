; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $AAD7
free_task_id_and_record:
    phd
    php
    rep #$30
    txy
    lda a:$0006,X
    sec
    .a16
    sbc #$0200
    .a16
    and #$FF00
    xba
    clc
    .a16
    adc #$00AA
    tax
    sep #$20
    stz a:$0000,X
    rep #$20
    lda a:$00A6
    sta a:$0000,Y
    sty a:$00A6
    plp
    pld
    rts
