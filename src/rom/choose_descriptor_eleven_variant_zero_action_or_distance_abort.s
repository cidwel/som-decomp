; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eleven.md.
.setcpu "65816"
.smart
.a8
.i16

derive_target_manhattan_distance_in_sixteen_pixel_units = $08D9
draw_boss_frame_random_number = $300B
select_nearest_living_target_and_eight_way_direction = $3A41

.segment "CODE"
.org $8C2E
choose_descriptor_eleven_variant_zero_action_or_distance_abort:
    ldx $87
    jsr select_nearest_living_target_and_eight_way_direction
    lda a:$00A9,X
    jsr derive_target_manhattan_distance_in_sixteen_pixel_units
    .a16
    cmp #$0006
    bcs choose_descriptor_eleven_variant_zero_action_or_distance_abort_c28c67
    lda a:$00AB,X
    .a16
    cmp #$0001
    bcc choose_descriptor_eleven_variant_zero_action_or_distance_abort_c28c59
    .a16
    cmp #$0004
    bcs choose_descriptor_eleven_variant_zero_action_or_distance_abort_c28c59
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE5D7,X
    clc
    rts
choose_descriptor_eleven_variant_zero_action_or_distance_abort_c28c59:
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE5C5,X
    clc
    rts
choose_descriptor_eleven_variant_zero_action_or_distance_abort_c28c67:
    sec
    rts
