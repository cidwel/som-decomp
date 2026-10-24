; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-zero-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3E7D
descriptor_zero_child_return_without_termination:
    clc
    rts
