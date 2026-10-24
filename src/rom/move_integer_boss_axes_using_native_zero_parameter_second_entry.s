; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-unused-native-leaves.md.
.setcpu "65816"
.smart
.a8
.i16

move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding = $0A47

.segment "CODE"
.org $65E7
move_integer_boss_axes_using_native_zero_parameter_second_entry:
    lda $C5
    jsr move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding
    rts
