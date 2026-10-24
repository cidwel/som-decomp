; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CBDC
clear_registrations_by_task:
    phd
    php
    rep #$30
    pha
    tsc
    inc
    tcd
    pla
    phb
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    sta $01
    .i16
    ldy #$0020
    ldx a:$0302
    php
    sei
clear_registrations_by_task_cbf9:
    lda $01
    cmp a:$0001,X
    bne clear_registrations_by_task_cc03
    stz a:$0000,X
clear_registrations_by_task_cc03:
    clc
    rep #$20
    txa
    .a16
    adc #$0004
    tax
    sep #$20
    dey
    bne clear_registrations_by_task_cbf9
    plp
    plb
    pla
    plp
    pld
    rts
