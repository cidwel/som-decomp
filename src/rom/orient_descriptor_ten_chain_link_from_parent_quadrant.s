; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-ten-children.md.
.setcpu "65816"
.smart
.a8
.i16

derive_four_way_direction_from_coordinate_pairs = $2E2A

.segment "CODE"
.org $78AA
orient_descriptor_ten_chain_link_from_parent_quadrant:
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
    asl
    tax
    lda f:$DCE595,X
    sta $95
    ldx $87
    lda a:$0098,X
    .a16
    and #$FF3F
    ora $95
    sta a:$0098,X
    rts
