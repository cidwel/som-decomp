; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A5A4
read_input_interface_a5a4:
    phd
    php
    rep #$30
    lda f:$00421C
    ora a:$0094
    plp
    pld
    rts
