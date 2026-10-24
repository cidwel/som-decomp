; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-core.md.
.setcpu "65816"
.smart
.a8
.i16

reverse_dialogue_bitmap_byte_preserving_counter_byte = $0E2A

.segment "CODE"
.org $054D
expand_dialogue_window_tile_forward_with_reversed_bits:
    tax
    .a8
    lda #$08
expand_dialogue_window_tile_forward_with_reversed_bits_c00550:
    xba
    lda f:$D2D080,X
    jsr reverse_dialogue_bitmap_byte_preserving_counter_byte
    sta a:$9400,Y
    lda f:$D2D081,X
    jsr reverse_dialogue_bitmap_byte_preserving_counter_byte
    sta a:$9401,Y
    ora a:$9400,Y
    sta a:$9410,Y
    .a8
    lda #$00
    sta a:$9411,Y
    inx
    inx
    iny
    iny
    xba
    dec
    bne expand_dialogue_window_tile_forward_with_reversed_bits_c00550
    clc
    rep #$20
    tya
    .a16
    adc #$0010
    tay
    sep #$20
    rts
