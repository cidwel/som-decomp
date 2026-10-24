; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-thirteen-trajectory.md.
.setcpu "65816"
.smart
.a8
.i16

move_boss_fractional_axes_with_terrain_party_rejection_and_sliding = $36FF

.segment "CODE"
.org $69B9
integrate_descriptor_thirteen_height_acceleration_and_rejected_axis_motion:
    lda a:$00C4,X
    clc
    adc a:$0064,X
    sta a:$0064,X
    lda a:$00C6,X
    adc a:$0066,X
    sta a:$0066,X
    .a16
    cmp #$0080
    bcs integrate_descriptor_thirteen_height_acceleration_and_rejected_axis_motion_c269e0
    stz a:$0064,X
    .a16
    lda #$0080
    sta a:$0066,X
    stz a:$00C4,X
    stz a:$00C6,X
integrate_descriptor_thirteen_height_acceleration_and_rejected_axis_motion_c269e0:
    lda a:$00C4,X
    clc
    adc a:$0FC0
    sta a:$00C4,X
    lda a:$00C6,X
    adc a:$0FC2
    sta a:$00C6,X
    jsr move_boss_fractional_axes_with_terrain_party_rejection_and_sliding
    rts
