; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_object_terrain = $15B7
slide_boss_horizontal_two_pixels_after_vertical_rejection = $1571
slide_boss_vertical_two_pixels_after_horizontal_rejection = $152B
test_animation_movement_against_three_active_party_actors = $1723

.segment "CODE"
.org $14AA
move_boss_from_animation_signed_offsets_with_collision_sliding:
    sep #$20
    stz $69
    stz $6B
    ldx $87
    lda [$76],Y
    sta $68
    lda a:$0098,X
    .a8
    bit #$40
    beq move_boss_from_animation_signed_offsets_with_collision_sliding_c214c4
    lda $68
    .a8
    eor #$FF
    inc
    sta $68
move_boss_from_animation_signed_offsets_with_collision_sliding_c214c4:
    iny
    lda [$76],Y
    sta $6A
    lda a:$0098,X
    .a8
    bit #$80
    beq move_boss_from_animation_signed_offsets_with_collision_sliding_c214d7
    lda $6A
    .a8
    eor #$FF
    inc
    sta $6A
move_boss_from_animation_signed_offsets_with_collision_sliding_c214d7:
    lda $68
    bpl move_boss_from_animation_signed_offsets_with_collision_sliding_c214df
    .a8
    lda #$FF
    sta $69
move_boss_from_animation_signed_offsets_with_collision_sliding_c214df:
    lda $6A
    bpl move_boss_from_animation_signed_offsets_with_collision_sliding_c214e7
    .a8
    lda #$FF
    sta $6B
move_boss_from_animation_signed_offsets_with_collision_sliding_c214e7:
    iny
    phy
    rep #$20
    lda $68
    clc
    adc a:$002B,X
    sta a:$002B,X
    jsr prepare_boss_object_terrain
    bcs move_boss_from_animation_signed_offsets_with_collision_sliding_c214fe
    jsr test_animation_movement_against_three_active_party_actors
    bcc move_boss_from_animation_signed_offsets_with_collision_sliding_c2150a
move_boss_from_animation_signed_offsets_with_collision_sliding_c214fe:
    lda a:$002B,X
    sec
    sbc $68
    sta a:$002B,X
    jsr slide_boss_vertical_two_pixels_after_horizontal_rejection
move_boss_from_animation_signed_offsets_with_collision_sliding_c2150a:
    lda $6A
    clc
    adc a:$0032,X
    sta a:$0032,X
    jsr prepare_boss_object_terrain
    bcs move_boss_from_animation_signed_offsets_with_collision_sliding_c2151d
    jsr test_animation_movement_against_three_active_party_actors
    bcc move_boss_from_animation_signed_offsets_with_collision_sliding_c21529
move_boss_from_animation_signed_offsets_with_collision_sliding_c2151d:
    lda a:$0032,X
    sec
    sbc $6A
    sta a:$0032,X
    jsr slide_boss_horizontal_two_pixels_after_vertical_rejection
move_boss_from_animation_signed_offsets_with_collision_sliding_c21529:
    ply
    rts
