; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-scroll.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0A2B
tick_scrolling_dialogue_line_delay:
    lda a:$A20C
    dec
    .a8
    and #$01
    sta a:$A20C
    bne tick_scrolling_dialogue_line_delay_cc0a4c
    lda f:$000040
    inc
    sta f:$000040
    inc a:$A171
    lda a:$A171
    .a8
    and #$0F
    bne tick_scrolling_dialogue_line_delay_cc0a4c
    dec a:$A161
tick_scrolling_dialogue_line_delay_cc0a4c:
    rts
