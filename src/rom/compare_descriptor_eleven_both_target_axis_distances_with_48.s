; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eleven-motion.md.
.setcpu "65816"
.smart
.a8
.i16

compare_descriptor_eleven_horizontal_target_distance_with_48 = $8D89
compare_descriptor_eleven_vertical_target_distance_with_48 = $8DA5

.segment "CODE"
.org $8DC1
compare_descriptor_eleven_both_target_axis_distances_with_48:
    jsr compare_descriptor_eleven_horizontal_target_distance_with_48
    bcs compare_descriptor_eleven_both_target_axis_distances_with_48_c28dc9
    jsr compare_descriptor_eleven_vertical_target_distance_with_48
compare_descriptor_eleven_both_target_axis_distances_with_48_c28dc9:
    rts
