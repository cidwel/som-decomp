; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-target-steering.md.
.setcpu "65816"
.smart
.a8
.i16

derive_target_manhattan_distance_in_sixteen_pixel_units = $08D9
select_nearest_living_target_and_four_way_direction = $3A52

.segment "CODE"
.org $619A
test_native_boss_variant_or_nearest_target_within_four_distance_units:
    lda a:$0042,X
    bne test_native_boss_variant_or_nearest_target_within_four_distance_units_c261af
    jsr select_nearest_living_target_and_four_way_direction
    lda a:$00A9,X
    jsr derive_target_manhattan_distance_in_sixteen_pixel_units
    .a16
    cmp #$0004
    bcc test_native_boss_variant_or_nearest_target_within_four_distance_units_c261af
    clc
    rts
test_native_boss_variant_or_nearest_target_within_four_distance_units_c261af:
    sec
    rts
