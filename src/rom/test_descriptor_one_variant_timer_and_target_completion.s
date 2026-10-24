; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-mutable-descriptor-dispatch.md.
.setcpu "65816"
.smart
.a8
.i16

derive_target_manhattan_distance_in_sixteen_pixel_units = $08D9
select_nearest_living_target_and_four_way_direction = $3A52

.segment "CODE"
.org $4413
test_descriptor_one_variant_timer_and_target_completion:
    lda a:$0042,X
    beq test_descriptor_one_variant_timer_and_target_completion_c24433
    lda a:$0096,X
    .a16
    cmp #$0018
    bcc test_descriptor_one_variant_timer_and_target_completion_c24435
    .a16
    cmp #$003C
    bcs test_descriptor_one_variant_timer_and_target_completion_c24433
    jsr select_nearest_living_target_and_four_way_direction
    lda a:$00A9,X
    jsr derive_target_manhattan_distance_in_sixteen_pixel_units
    .a16
    cmp #$0005
    bcs test_descriptor_one_variant_timer_and_target_completion_c24435
test_descriptor_one_variant_timer_and_target_completion_c24433:
    sec
    rts
test_descriptor_one_variant_timer_and_target_completion_c24435:
    clc
    rts
