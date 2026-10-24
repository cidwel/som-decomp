; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-scroll.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0B37
advance_scrolling_dialogue_ring_cursor:
    rep #$20
    lda a:$A18F
    clc
    .a16
    adc #$0080
    .a16
    cmp #$0800
    bcc advance_scrolling_dialogue_ring_cursor_cc0b48
    .a16
    lda #$0002
advance_scrolling_dialogue_ring_cursor_cc0b48:
    sta a:$A18F
    sep #$20
    rts
