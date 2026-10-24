; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-core.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_dialogue_window_tile_orientation = $04D0

.segment "CODE"
.org $044C
draw_dialogue_window_fill_tile_pairs:
draw_dialogue_window_fill_tile_pairs_c0044c:
    rep #$20
    .a16
    lda #$0400
    clc
    adc a:$A178
    tax
    sep #$20
    jsr dispatch_dialogue_window_tile_orientation
    .a8
    lda #$00
    xba
    dec a:$A164
    beq draw_dialogue_window_fill_tile_pairs_c00477
    rep #$20
    .a16
    lda #$0400
    clc
    adc a:$A178
    tax
    sep #$20
    jsr dispatch_dialogue_window_tile_orientation
    dec a:$A164
    bne draw_dialogue_window_fill_tile_pairs_c0044c
draw_dialogue_window_fill_tile_pairs_c00477:
    rts
