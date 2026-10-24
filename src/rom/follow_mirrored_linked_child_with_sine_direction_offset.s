; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-action-helpers.md.
.setcpu "65816"
.smart
.a8
.i16

derive_cosine_by_adding_quarter_turn = $2A59
divide_signed_word_by_word_with_remainder = $2D69

.segment "CODE"
.org $8322
follow_mirrored_linked_child_with_sine_direction_offset:
    ldy a:$00B0,X
    lda a:$0098,Y
    .a16
    bit #$0040
    bne follow_mirrored_linked_child_with_sine_direction_offset_c28339
    lda a:$002B,Y
    clc
    .a16
    adc #$0018
    sta a:$002B,X
    bra follow_mirrored_linked_child_with_sine_direction_offset_c28343
follow_mirrored_linked_child_with_sine_direction_offset_c28339:
    lda a:$002B,Y
    sec
    .a16
    sbc #$0018
    sta a:$002B,X
follow_mirrored_linked_child_with_sine_direction_offset_c28343:
    lda a:$0032,Y
    clc
    .a16
    adc #$0012
    sta a:$0032,X
    lda a:$00A9,Y
    sta a:$00A9,X
    lda a:$00AB,Y
    sta a:$00AB,X
    asl
    asl
    jsr derive_cosine_by_adding_quarter_turn
    sta $46
    .a16
    lda #$0020
    sta $4E
    jsr divide_signed_word_by_word_with_remainder
    ldx $87
    lda a:$002B,X
    clc
    adc $56
    sta a:$002B,X
    rts
