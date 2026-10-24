; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-scroll.md.
.setcpu "65816"
.smart
.a8
.i16

advance_scrolling_dialogue_ring_cursor = $0B37

.segment "CODE"
.org $09F4
advance_scrolling_dialogue_line:
    iny
    jsr advance_scrolling_dialogue_ring_cursor
    sec
    rts
