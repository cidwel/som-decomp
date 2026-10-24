; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0018
jump_to_warm_boot:
    jml f:$C14CFA
