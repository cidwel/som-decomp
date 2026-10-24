; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-scroll.md.
.setcpu "65816"
.smart
.a8
.i16

advance_scrolling_dialogue_ring_cursor = $0B37
clear_scrolling_dialogue_ring_line = $0B4E
routine_cc0a4c = $0A4C

.segment "CODE"
.org $0A4D
tick_scrolling_dialogue_final_ring_clear:
    lda a:$A20C
    dec
    .a8
    and #$01
    sta a:$A20C
    bne tick_scrolling_dialogue_final_ring_clear_cc0a84
    lda f:$000040
    inc
    sta f:$000040
    inc a:$A171
    lda a:$A171
    pha
    .a8
    and #$0F
    bne tick_scrolling_dialogue_final_ring_clear_cc0a7c
    jsr clear_scrolling_dialogue_ring_line
    jsr advance_scrolling_dialogue_ring_cursor
    lda f:$001D04
    .a8
    ora #$44
    sta f:$001D04
tick_scrolling_dialogue_final_ring_clear_cc0a7c:
    pla
    .a8
    cmp #$00
    bne routine_cc0a4c
    inc a:$A161
tick_scrolling_dialogue_final_ring_clear_cc0a84:
    rts
