; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-rebound-landing.md.
.setcpu "65816"
.smart
.a8
.i16

derive_eight_way_direction_from_coordinate_pairs = $2E50
move_boss_axes_with_rejected_axis_sliding = $36BC

.segment "CODE"
.org $5663
choose_eight_way_target_velocity_and_attempt_sliding_motion:
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    lda a:$0002,Y
    sta $46
    lda a:$0004,Y
    sta $4E
    lda a:$002B,X
    sta $56
    lda a:$0032,X
    sta $5E
    jsr derive_eight_way_direction_from_coordinate_pairs
    asl
    asl
    tax
    lda f:$C256A3,X
    sta $95
    lda f:$C256A5,X
    sta $97
    ldx $87
    lda $95
    sta a:$003C,X
    lda $97
    sta a:$0040,X
    jsr move_boss_axes_with_rejected_axis_sliding
    rts
