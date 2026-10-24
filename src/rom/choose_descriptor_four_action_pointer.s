; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-four.md.
.setcpu "65816"
.smart
.a8
.i16

derive_target_manhattan_distance_in_sixteen_pixel_units = $08D9
draw_boss_frame_random_number = $300B
select_nearest_living_target_and_four_way_direction = $3A52

.segment "CODE"
.org $6B63
choose_descriptor_four_action_pointer:
    jsr select_nearest_living_target_and_four_way_direction
    lda a:$007E,X
    bne choose_descriptor_four_action_pointer_c26b8b
    lda a:$00A9,X
    jsr derive_target_manhattan_distance_in_sixteen_pixel_units
    .a16
    cmp #$0004
    bcs choose_descriptor_four_action_pointer_c26b86
    lda a:$00AB,X
    .a16
    cmp #$0003
    beq choose_descriptor_four_action_pointer_c26b86
    asl
    tax
    lda f:$DCE3E8,X
    clc
    rts
choose_descriptor_four_action_pointer_c26b86:
    .a16
    lda #$E5F0
    clc
    rts
choose_descriptor_four_action_pointer_c26b8b:
    lda a:$0042,X
    bne choose_descriptor_four_action_pointer_c26b9e
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE3EE,X
    clc
    rts
choose_descriptor_four_action_pointer_c26b9e:
    .a16
    lda #$0005
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE3F4,X
    clc
    rts
