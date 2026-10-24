; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-body.md.
.setcpu "65816"
.smart
.a8
.i16

derive_eight_way_direction_from_coordinate_pairs = $2E50
turn_body_heading_one_step_toward_target_with_opposite_rng_tie = $4F22

.segment "CODE"
.org $4E98
derive_body_segment_direction_shape_and_coordinates:
    lda a:$002B,X
    clc
    adc a:$00B4,X
    sta $56
    lda a:$0032,X
    clc
    adc a:$00B6,X
    sta $5E
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tax
    lda a:$0002,X
    sta $46
    lda a:$0004,X
    sta $4E
    jsr derive_eight_way_direction_from_coordinate_pairs
    jsr turn_body_heading_one_step_toward_target_with_opposite_rng_tie
    sta a:$00BA,X
    tax
    sep #$20
    lda f:$DCE62B,X
    sta $95
    lda f:$DCE63B,X
    sta $96
    lda $95
    .a8
    and #$0F
    asl
    tax
    rep #$20
    lda f:$DCE653,X
    sta $97
    lda f:$DCE655,X
    sta $99
    lda $95
    .a16
    bit #$4000
    beq derive_body_segment_direction_shape_and_coordinates_c24ef9
    .a16
    lda #$FFF0
    sec
    sbc $97
    sta $97
derive_body_segment_direction_shape_and_coordinates_c24ef9:
    lda $95
    .a16
    bit #$8000
    beq derive_body_segment_direction_shape_and_coordinates_c24f08
    .a16
    lda #$FFF0
    sec
    sbc $99
    sta $99
derive_body_segment_direction_shape_and_coordinates_c24f08:
    lda $95
    .a16
    ora #$1C00
    sta $95
    ldx $87
    lda $97
    clc
    adc a:$00B4,X
    sta $97
    lda $99
    clc
    adc a:$00B6,X
    sta $99
    rts
