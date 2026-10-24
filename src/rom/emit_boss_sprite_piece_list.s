; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

emit_boss_sprite_pieces_in_reverse_order = $1FB5
prepare_boss_sprite_screen_position = $2005

.segment "CODE"
.org $1F80
emit_boss_sprite_piece_list:
    ldx $87
    jsr prepare_boss_sprite_screen_position
    lda $87
    sec
    .a16
    sbc #$E600
    lsr
    lsr
    clc
    .a16
    adc #$F800
    sta $79
    lda ($79)
    .a16
    and #$00FF
    beq emit_boss_sprite_piece_list_c21fb4
    sta $85
    inc $79
    stz $66
    lda a:$0098,X
    sta $8D
    lda $7F
    sta $95
    jsr emit_boss_sprite_pieces_in_reverse_order
    lda $7F
    clc
    adc $85
    sta $7F
    rts
emit_boss_sprite_piece_list_c21fb4:
    rts
