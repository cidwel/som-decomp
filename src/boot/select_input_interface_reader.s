; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A6B7
select_input_interface_reader:
    phd
    php
    rep #$30
    sep #$20
    lda a:$0096
    .a8
    bit #$40
    beq select_input_interface_reader_a6d8
    .i16
    cpx #$0008
    bcs select_input_interface_reader_a6ce
    jsr ($A60D,X)
    bra select_input_interface_reader_a6fc
select_input_interface_reader_a6ce:
    sec
    rep #$20
    txa
    .a16
    sbc #$0006
    tax
    sep #$20
select_input_interface_reader_a6d8:
    .i16
    cpx #$0000
    beq select_input_interface_reader_a6e8
    .a8
    bit #$80
    beq select_input_interface_reader_a6e8
    dex
    dex
    jsr ($A6AF,X)
    bra select_input_interface_reader_a6fc
select_input_interface_reader_a6e8:
    rep #$20
    .i16
    cpx #$0002
    beq select_input_interface_reader_a6f1
    bcs select_input_interface_reader_a6f7
select_input_interface_reader_a6f1:
    lda f:$004218,X
    bra select_input_interface_reader_a6fa
select_input_interface_reader_a6f7:
    .a16
    lda #$0001
select_input_interface_reader_a6fa:
    sep #$20
select_input_interface_reader_a6fc:
    plp
    pld
    rts
