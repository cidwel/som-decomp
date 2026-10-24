; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-nine.md.
.setcpu "65816"
.smart
.a8
.i16

derive_target_manhattan_distance_in_sixteen_pixel_units = $08D9
select_nearest_living_target_and_eight_way_direction = $3A41

.segment "CODE"
.org $6520
choose_descriptor_nine_state_by_eightway_direction_and_distance:
    jsr select_nearest_living_target_and_eight_way_direction
    lda a:$00A9,X
    jsr derive_target_manhattan_distance_in_sixteen_pixel_units
    .a16
    cmp #$0006
    bcs choose_descriptor_nine_state_by_eightway_direction_and_distance_c26538
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE314,X
    rts
choose_descriptor_nine_state_by_eightway_direction_and_distance_c26538:
    .a16
    cmp #$0008
    bcc choose_descriptor_nine_state_by_eightway_direction_and_distance_c26547
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE31C,X
    rts
choose_descriptor_nine_state_by_eightway_direction_and_distance_c26547:
    .a16
    lda #$E146
    rts
