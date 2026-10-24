; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-four-child-motion.md.
.setcpu "65816"
.smart
.a8
.i16

move_boss_axes_with_rejected_axis_sliding = $36BC

.segment "CODE"
.org $6CCB
advance_descriptor_four_child_height_and_real_axis_motion:
    lda a:$00C6,X
    clc
    adc a:$0066,X
    sta a:$0066,X
    jsr move_boss_axes_with_rejected_axis_sliding
    rts
