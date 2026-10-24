; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-axis-motion.md.
.setcpu "65816"
.smart
.a8
.i16

advance_descriptor_ten_global_axis_origins_by_velocity = $773E
derive_descriptor_ten_positive_y_sine_offset_from_phase = $776F
derive_descriptor_ten_x_sine_offset_from_phase = $7753

.segment "CODE"
.org $7716
advance_descriptor_ten_positive_diagonal_sine_motion:
    jsr advance_descriptor_ten_global_axis_origins_by_velocity
    lda a:$007E,X
    clc
    .a16
    adc #$0020
    sta a:$007E,X
    jsr derive_descriptor_ten_x_sine_offset_from_phase
    jsr derive_descriptor_ten_positive_y_sine_offset_from_phase
    rts
