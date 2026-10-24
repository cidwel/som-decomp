; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eleven-motion.md.
.setcpu "65816"
.smart
.a8
.i16

advance_descriptor_eleven_sine_height_with_fractional_carry = $8CFB
move_boss_fractional_axes_with_terrain_party_rejection_and_sliding = $36FF

.segment "CODE"
.org $8D82
update_descriptor_eleven_height_and_rejected_axis_motion:
    jsr advance_descriptor_eleven_sine_height_with_fractional_carry
    jsr move_boss_fractional_axes_with_terrain_party_rejection_and_sliding
    rts
