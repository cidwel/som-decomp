; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-ten-children.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $789C
terminate_descriptor_ten_chain_when_animation_completes:
    ldx $87
    lda a:$009E,X
    bne terminate_descriptor_ten_chain_when_animation_completes_c278a8
    stz a:$0000,X
    sec
    rts
terminate_descriptor_ten_chain_when_animation_completes_c278a8:
    clc
    rts
