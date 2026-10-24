; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-scroll.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0B4E
clear_scrolling_dialogue_ring_line:
    ldx a:$A18F
    .a8
    lda #$40
clear_scrolling_dialogue_ring_line_cc0b53:
    stz a:$9400,X
    inx
    dec
    bne clear_scrolling_dialogue_ring_line_cc0b53
    rts
