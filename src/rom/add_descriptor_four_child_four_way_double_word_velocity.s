; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-four-child-motion.md.
.setcpu "65816"
.smart
.a8
.i16

derive_four_way_direction_to_low_byte_target = $091D
move_boss_axes_with_rejected_axis_sliding = $36BC

.segment "CODE"
.org $6CE0
add_descriptor_four_child_four_way_double_word_velocity:
    lda a:$00A9,X
    jsr derive_four_way_direction_to_low_byte_target
    ldx $87
    sta a:$00AB,X
    asl
    asl
    asl
    tax
    lda f:$DCE400,X
    sta $95
    lda f:$DCE402,X
    sta $97
    lda f:$DCE404,X
    sta $99
    lda f:$DCE406,X
    sta $9B
    ldx $87
    lda a:$003A,X
    clc
    adc $95
    sta a:$003A,X
    lda a:$003C,X
    adc $97
    sta a:$003C,X
    lda a:$003E,X
    clc
    adc $99
    sta a:$003E,X
    lda a:$0040,X
    adc $9B
    sta a:$0040,X
    jsr move_boss_axes_with_rejected_axis_sliding
    rts
