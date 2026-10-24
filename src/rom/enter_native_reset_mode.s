; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8004
enter_native_reset_mode:
    clc
    xce
    sep #$30
    jml f:$C10010
