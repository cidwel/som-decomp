; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-ten-children.md.
.setcpu "65816"
.smart
.a8
.i16

derive_four_way_direction_from_coordinate_pairs = $2E2A
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $78DC
orient_and_reseed_descriptor_ten_chain_end_from_parent_quadrant:
    ldy a:$00B0,X
    lda a:$002B,X
    sta $46
    lda a:$0032,X
    sta $4E
    lda a:$002B,Y
    sta $56
    lda a:$0032,Y
    sta $5E
    jsr derive_four_way_direction_from_coordinate_pairs
    lda $6A
    ldx $87
    sta a:$00AB,X
    lda a:$0042,X
    bne orient_and_reseed_descriptor_ten_chain_end_from_parent_quadrant_c27918
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE59D,X
    sta $95
    lda f:$DCE5A5,X
    ldx $87
    jsr select_boss_animation_and_reset_frame_cursor
    bra orient_and_reseed_descriptor_ten_chain_end_from_parent_quadrant_c2792c
orient_and_reseed_descriptor_ten_chain_end_from_parent_quadrant_c27918:
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE59D,X
    sta $95
    lda f:$DCE5AD,X
    ldx $87
    jsr select_boss_animation_and_reset_frame_cursor
orient_and_reseed_descriptor_ten_chain_end_from_parent_quadrant_c2792c:
    lda a:$0098,X
    .a16
    and #$FF3F
    ora $95
    sta a:$0098,X
    rts
