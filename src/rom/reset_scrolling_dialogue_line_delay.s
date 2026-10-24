; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-scroll.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $09E2
reset_scrolling_dialogue_line_delay:
    iny
    stz a:$A171
    clc
    rts
