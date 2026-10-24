; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-numeric-selection.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1A7A
finish_numeric_choice_and_begin_window_close:
    phb
    .a8
    lda #$00
    pha
    plb
    .a8
    lda #$80
    tsb a:$1D04
    plb
    .a8
    lda #$02
    trb a:$A187
    stz a:$A160
    stz a:$A170
    .a8
    lda #$51
    sta a:$A170
    rts
