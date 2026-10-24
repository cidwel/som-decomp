; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-fourteen.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $526A
choose_descriptor_fourteen_low_byte_hurt_pointer:
    lda a:$007E,X
    .a16
    and #$00FF
    asl
    tax
    lda f:$C2DAE6,X
    rts
