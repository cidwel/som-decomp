; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-motion.md.
.setcpu "65816"
.smart
.a8
.i16

advance_linked_child_strip_ring_and_parent_coordinates = $5E44
derive_linked_child_random_wave_velocity_toward_variant_origin = $5DEF
relax_linked_child_velocity_by_signed_one_thirty_second = $5D2D
select_target_and_heading_from_linked_child_fractional_tip = $5D87

.segment "CODE"
.org $5CD9
advance_linked_child_random_idle_motion:
    dec a:$0015,X
    lda a:$0015,X
    .a16
    bit #$001F
    bne advance_linked_child_random_idle_motion_c25ce7
    jsr derive_linked_child_random_wave_velocity_toward_variant_origin
advance_linked_child_random_idle_motion_c25ce7:
    jsr select_target_and_heading_from_linked_child_fractional_tip
    jsr advance_linked_child_strip_ring_and_parent_coordinates
    jsr relax_linked_child_velocity_by_signed_one_thirty_second
    rts
