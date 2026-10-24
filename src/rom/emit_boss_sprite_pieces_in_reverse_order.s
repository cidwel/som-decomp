; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

emit_background_boss_sprite_piece = $2081
emit_normal_boss_sprite_piece = $206D

.segment "CODE"
.org $1FB5
emit_boss_sprite_pieces_in_reverse_order:
    lda a:$0066,X
    lsr
    .a16
    eor #$FFFF
    clc
    adc $91
    sta $91
    lda $85
    dec
    sta $97
    asl
    asl
    clc
    adc $79
    sta $79
    lda a:$0070,X
    .a16
    bit #$0008
    bne emit_boss_sprite_pieces_in_reverse_order_c21fed
emit_boss_sprite_pieces_in_reverse_order_c21fd5:
    jsr emit_normal_boss_sprite_piece
    bcs emit_boss_sprite_pieces_in_reverse_order_c21fde
    inc $95
    inc $66
emit_boss_sprite_pieces_in_reverse_order_c21fde:
    lda $79
    sec
    .a16
    sbc #$0004
    sta $79
    lda $66
    cmp $85
    bcc emit_boss_sprite_pieces_in_reverse_order_c21fd5
    rts
emit_boss_sprite_pieces_in_reverse_order_c21fed:
    jsr emit_background_boss_sprite_piece
    bcs emit_boss_sprite_pieces_in_reverse_order_c21ff6
    inc $95
    inc $66
emit_boss_sprite_pieces_in_reverse_order_c21ff6:
    lda $79
    sec
    .a16
    sbc #$0004
    sta $79
    lda $66
    cmp $85
    bcc emit_boss_sprite_pieces_in_reverse_order_c21fed
    rts
