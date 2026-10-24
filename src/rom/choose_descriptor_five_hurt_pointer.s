; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-five.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6175
choose_descriptor_five_hurt_pointer:
    lda a:$007E,X
    asl
    tax
    lda f:$DCE2A2,X
    rts
