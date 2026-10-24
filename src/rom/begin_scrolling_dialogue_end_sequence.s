; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-scroll.md.
.setcpu "65816"
.smart
.a8
.i16

advance_scrolling_dialogue_ring_cursor = $0B37

.segment "CODE"
.org $09E8
begin_scrolling_dialogue_end_sequence:
    iny
    inc a:$A161
    stz a:$A171
    jsr advance_scrolling_dialogue_ring_cursor
    sec
    rts
