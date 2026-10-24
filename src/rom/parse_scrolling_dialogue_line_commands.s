; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-scroll.md.
.setcpu "65816"
.smart
.a8
.i16

clear_scrolling_dialogue_ring_line = $0B4E

.segment "CODE"
.org $0997
parse_scrolling_dialogue_line_commands:
    jsr clear_scrolling_dialogue_ring_line
    ldx a:$A18F
    stx a:$A19B
    ldy a:$A173
parse_scrolling_dialogue_line_commands_cc09a3:
    .a8
    lda #$00
    xba
    lda a:$9000,Y
    sec
    .a8
    sbc #$7C
    bcs parse_scrolling_dialogue_line_commands_cc09b0
    .a8
    lda #$04
parse_scrolling_dialogue_line_commands_cc09b0:
    asl
    tax
    jsr ($0B6F,X)
    bcc parse_scrolling_dialogue_line_commands_cc09a3
    sty a:$A173
    .a8
    lda #$03
    sta a:$A20C
    lda f:$001D04
    .a8
    ora #$44
    sta f:$001D04
    inc a:$A161
    rts
