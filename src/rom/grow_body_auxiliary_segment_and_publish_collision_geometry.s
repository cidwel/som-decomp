; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-body.md.
.setcpu "65816"
.smart
.a8
.i16

advance_body_velocity_by_segment_shape_and_flip_bits = $4E4F
derive_body_segment_direction_shape_and_coordinates = $4E98
replace_previous_body_segment_shape = $4E35

.segment "CODE"
.org $4DDE
grow_body_auxiliary_segment_and_publish_collision_geometry:
    ldy a:$00B8,X
    jsr replace_previous_body_segment_shape
    jsr advance_body_velocity_by_segment_shape_and_flip_bits
    phy
    jsr derive_body_segment_direction_shape_and_coordinates
    ply
    lda $8B
    xba
    lsr
    tax
    inc a:$F800,X
    sep #$20
    lda a:$F804,X
    .a8
    eor #$40
    sta a:$F804,X
    lda $97
    sta a:$0002,Y
    lda $99
    sta a:$0003,Y
    ldx $87
    lda $97
    clc
    .a8
    adc #$08
    sta a:$00C0,X
    lda $99
    clc
    .a8
    adc #$08
    sta a:$00C1,X
    .a8
    lda #$02
    sta a:$00C2,X
    sta a:$00C3,X
    rep #$20
    lda $95
    sta a:$0004,Y
    tya
    clc
    .a16
    adc #$0004
    sta a:$00B8,X
    inc a:$00B2,X
    rts
