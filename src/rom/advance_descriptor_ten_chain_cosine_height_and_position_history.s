; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-ten-children.md.
.setcpu "65816"
.smart
.a8
.i16

derive_cosine_by_adding_quarter_turn = $2A59
multiply_signed_words_to_double_word = $2B94

.segment "CODE"
.org $7938
advance_descriptor_ten_chain_cosine_height_and_position_history:
    lda a:$00B6,X
    sta a:$002B,X
    lda a:$00B8,X
    sta a:$0032,X
    lda a:$00B2,X
    clc
    .a16
    adc #$0010
    sta a:$00B2,X
    jsr derive_cosine_by_adding_quarter_turn
    sta $46
    ldx $87
    lda a:$00B4,X
    sta $4E
    jsr multiply_signed_words_to_double_word
    ldx $87
    lda $57
    clc
    adc a:$00B4,X
    sta a:$0066,X
    ldy a:$00B0,X
    lda a:$002B,Y
    cmp a:$007C,X
    bne advance_descriptor_ten_chain_cosine_height_and_position_history_c2797b
    lda a:$0032,Y
    cmp a:$007E,X
    beq advance_descriptor_ten_chain_cosine_height_and_position_history_c279b7
advance_descriptor_ten_chain_cosine_height_and_position_history_c2797b:
    lda a:$00BA,X
    sta a:$00B6,X
    lda a:$00BC,X
    sta a:$00B8,X
    lda a:$00BE,X
    sta a:$00BA,X
    lda a:$0076,X
    sta a:$00BC,X
    lda a:$0078,X
    sta a:$00BE,X
    lda a:$007A,X
    sta a:$0076,X
    lda a:$007C,X
    sta a:$0078,X
    lda a:$007E,X
    sta a:$007A,X
    lda a:$002B,Y
    sta a:$007C,X
    lda a:$0032,Y
    sta a:$007E,X
advance_descriptor_ten_chain_cosine_height_and_position_history_c279b7:
    rts
