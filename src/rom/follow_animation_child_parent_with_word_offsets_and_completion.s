; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-animation-linked-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $31F7
follow_animation_child_parent_with_word_offsets_and_completion:
    ldx $87
    lda a:$00B0,X
    tax
    lda a:$002B,X
    sta $95
    lda a:$0032,X
    sta $97
    ldx $87
    lda $95
    clc
    adc a:$00B2,X
    sta a:$002B,X
    lda $97
    clc
    adc a:$00B4,X
    sta a:$0032,X
    lda a:$009E,X
    bne follow_animation_child_parent_with_word_offsets_and_completion_c23222
    sec
    rts
follow_animation_child_parent_with_word_offsets_and_completion_c23222:
    clc
    rts
