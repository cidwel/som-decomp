; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-ten-terminal.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $7AAA
clear_descriptor_ten_actor_and_advance_when_animation_finishes:
    ldx $87
    lda a:$009E,X
    bne clear_descriptor_ten_actor_and_advance_when_animation_finishes_c27abb
    stz a:$0000,X
    stz a:$0096,X
    inc a:$0094,X
    rts
clear_descriptor_ten_actor_and_advance_when_animation_finishes_c27abb:
    clc
    rts
