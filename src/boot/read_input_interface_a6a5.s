; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A6A5
read_input_interface_a6a5:
    phd
    php
    rep #$30
    lda a:$0094
    plp
    pld
    rts
