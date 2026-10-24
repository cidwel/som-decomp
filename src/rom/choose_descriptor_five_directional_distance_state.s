; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-five.md.
.setcpu "65816"
.smart
.a8
.i16

derive_target_manhattan_distance_in_sixteen_pixel_units = $08D9
select_nearest_living_target_and_four_way_direction = $3A52

.segment "CODE"
.org $6073
choose_descriptor_five_directional_distance_state:
    ldx $87
    jsr select_nearest_living_target_and_four_way_direction
    lda a:$00A9,X
    jsr derive_target_manhattan_distance_in_sixteen_pixel_units
    .a16
    cmp #$0003
    bcs choose_descriptor_five_directional_distance_state_c26094
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE27A,X
    ldx $87
    cmp a:$00B0,X
    beq choose_descriptor_five_directional_distance_state_c26099
    rts
choose_descriptor_five_directional_distance_state_c26094:
    .a16
    cmp #$0004
    bcs choose_descriptor_five_directional_distance_state_c260a3
choose_descriptor_five_directional_distance_state_c26099:
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE282,X
    rts
choose_descriptor_five_directional_distance_state_c260a3:
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE28A,X
    rts
