; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-ten.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $76D1
choose_descriptor_ten_hurt_pointer_by_current_heading:
    lda a:$00AB,X
    asl
    tax
    lda f:$C276DB,X
    rts
