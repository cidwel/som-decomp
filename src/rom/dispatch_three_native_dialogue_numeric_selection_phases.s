; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-numeric-selection.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1A46
dispatch_three_native_dialogue_numeric_selection_phases:
    .a8
    lda #$00
    xba
    lda a:$A160
    asl
    tax
    jsr ($1BB7,X)
    rts
