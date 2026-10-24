; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-body.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4E4F
advance_body_velocity_by_segment_shape_and_flip_bits:
    lda a:$0000,Y
    .a16
    and #$000F
    asl
    tax
    lda f:$DCE643,X
    sta $95
    lda f:$DCE645,X
    sta $97
    lda a:$0000,Y
    .a16
    bit #$4000
    beq advance_body_velocity_by_segment_shape_and_flip_bits_c24e73
    lda $95
    .a16
    eor #$FFFF
    inc
    sta $95
advance_body_velocity_by_segment_shape_and_flip_bits_c24e73:
    lda a:$0000,Y
    .a16
    bit #$8000
    beq advance_body_velocity_by_segment_shape_and_flip_bits_c24e83
    lda $97
    .a16
    eor #$FFFF
    inc
    sta $97
advance_body_velocity_by_segment_shape_and_flip_bits_c24e83:
    ldx $87
    lda a:$00B4,X
    clc
    adc $95
    sta a:$00B4,X
    lda a:$00B6,X
    clc
    adc $97
    sta a:$00B6,X
    rts
