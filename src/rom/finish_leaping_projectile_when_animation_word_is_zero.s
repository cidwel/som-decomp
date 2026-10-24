; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $74EE
finish_leaping_projectile_when_animation_word_is_zero:
    ldx $87
    lda a:$009E,X
    bne finish_leaping_projectile_when_animation_word_is_zero_c274f7
    sec
    rts
finish_leaping_projectile_when_animation_word_is_zero_c274f7:
    clc
    rts
