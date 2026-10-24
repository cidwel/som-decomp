; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-ten.md.
.setcpu "65816"
.smart
.a8
.i16

derive_four_way_direction_to_low_byte_target = $091D
derive_target_manhattan_distance_in_sixteen_pixel_units = $08D9
draw_boss_frame_random_number = $300B
select_nearest_active_living_party_actor = $3224

.segment "CODE"
.org $7661
choose_descriptor_ten_variant_distance_action:
    jsr select_nearest_active_living_party_actor
    ldx $87
    sta a:$00A9,X
    jsr derive_four_way_direction_to_low_byte_target
    lda $6A
    ldx $87
    sta a:$00AB,X
    lda a:$0042,X
    bne choose_descriptor_ten_variant_distance_action_c276ad
    lda a:$00A9,X
    jsr derive_target_manhattan_distance_in_sixteen_pixel_units
    .a16
    cmp #$0003
    bcs choose_descriptor_ten_variant_distance_action_c2768e
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE585,X
    clc
    rts
choose_descriptor_ten_variant_distance_action_c2768e:
    .a16
    cmp #$0006
    bcc choose_descriptor_ten_variant_distance_action_c276a0
    .a16
    lda #$0007
    jsr draw_boss_frame_random_number
    bne choose_descriptor_ten_variant_distance_action_c276a0
    .a16
    lda #$ED63
    clc
    rts
choose_descriptor_ten_variant_distance_action_c276a0:
    ldx $87
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE577,X
    clc
    rts
choose_descriptor_ten_variant_distance_action_c276ad:
    lda a:$00A9,X
    jsr derive_target_manhattan_distance_in_sixteen_pixel_units
    .a16
    cmp #$0003
    bcs choose_descriptor_ten_variant_distance_action_c276c3
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE58D,X
    clc
    rts
choose_descriptor_ten_variant_distance_action_c276c3:
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    asl
    tax
    lda f:$DCE57F,X
    clc
    rts
