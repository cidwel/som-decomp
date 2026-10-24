; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-axis-motion.md.
.setcpu "65816"
.smart
.a8
.i16

move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding = $0A47

.segment "CODE"
.org $73A7
advance_descriptor_seven_integer_terrain_axes:
    lda $C5
    jsr move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding
    rts
