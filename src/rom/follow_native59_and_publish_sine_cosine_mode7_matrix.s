; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-children.md.
.setcpu "65816"
.smart
.a8
.i16

derive_cosine_by_adding_quarter_turn = $2A59
dispatch_native59_child_radius_convergence = $8999
divide_signed_word_by_word_with_remainder = $2D69
mask_angle_and_derive_native_sine = $2A60
multiply_signed_words_to_double_word = $2B94
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $88D0
follow_native59_and_publish_sine_cosine_mode7_matrix:
    ldx $87
    ldy a:$00B6,X
    lda a:$002B,Y
    sta a:$002B,X
    lda a:$0032,Y
    sec
    .a16
    sbc #$0010
    sta a:$0032,X
    jsr dispatch_native59_child_radius_convergence
    ldx $87
    lda a:$00B0,X
    jsr mask_angle_and_derive_native_sine
    sta $46
    ldx $87
    ldy a:$00B6,X
    lda a:$00B2,Y
    bne follow_native59_and_publish_sine_cosine_mode7_matrix_c2890b
    lda a:$00B0,X
    clc
    .a16
    adc #$0040
    sta a:$00B0,X
    .a16
    lda #$001E
    bra follow_native59_and_publish_sine_cosine_mode7_matrix_c28918
follow_native59_and_publish_sine_cosine_mode7_matrix_c2890b:
    lda a:$00B0,X
    clc
    .a16
    adc #$0100
    sta a:$00B0,X
    .a16
    lda #$000F
follow_native59_and_publish_sine_cosine_mode7_matrix_c28918:
    sta $4E
    jsr divide_signed_word_by_word_with_remainder
    ldx $87
    lda $56
    clc
    adc a:$00B4,X
    sta $95
    ldx $87
    lda a:$00B2,X
    jsr mask_angle_and_derive_native_sine
    sta $97
    ldx $87
    lda a:$00B2,X
    jsr derive_cosine_by_adding_quarter_turn
    sta $99
    lda $99
    sta $46
    lda $95
    sta $4E
    jsr multiply_signed_words_to_double_word
    lda $57
    sta $9B
    lda $97
    sta $46
    lda $95
    sta $4E
    jsr multiply_signed_words_to_double_word
    lda $57
    sta $9D
    lda $97
    eor $C7
    inc
    sta $46
    lda $95
    sta $4E
    jsr multiply_signed_words_to_double_word
    lda $57
    sta $9F
    lda $9B
    sta a:$02CD
    lda $9D
    sta a:$02CF
    lda $9F
    sta a:$02D1
    lda $9B
    sta a:$02D3
    ldx $87
    ldy a:$00B6,X
    lda a:$0094,Y
    .a16
    cmp #$0006
    bne follow_native59_and_publish_sine_cosine_mode7_matrix_c28995
    inc a:$0094,X
    .a16
    lda #$017B
    jsr select_boss_animation_and_reset_frame_cursor
follow_native59_and_publish_sine_cosine_mode7_matrix_c28995:
    clc
    rts
