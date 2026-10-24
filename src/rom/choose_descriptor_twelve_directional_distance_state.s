; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-twelve.md.
.setcpu "65816"
.smart
.a8
.i16

derive_target_manhattan_distance_in_sixteen_pixel_units = $08D9
select_nearest_living_target_and_four_way_direction = $3A52

.segment "CODE"
.org $540C
choose_descriptor_twelve_directional_distance_state:
    jsr select_nearest_living_target_and_four_way_direction
    lda a:$00A9,X
    jsr derive_target_manhattan_distance_in_sixteen_pixel_units
    .a16
    cmp #$0003
    bcs choose_descriptor_twelve_directional_distance_state_c25424
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE24E,X
    rts
choose_descriptor_twelve_directional_distance_state_c25424:
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE256,X
    rts
