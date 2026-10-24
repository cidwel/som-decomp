; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A646
read_input_interface_a646:
    phd
    php
    rep #$30
    lda f:$00421E
    ora a:$0094
    plp
    pld
    rts
