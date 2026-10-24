; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-numeric-selection.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c01baf = $1BAF

.segment "CODE"
.org $1AF1
cancel_numeric_choice_when_script_cancellation_is_available:
    bne cancel_numeric_choice_when_script_cancellation_is_available_c01b1f
    pha
    ldx a:$A1D5
    phb
    lda a:$1D03
    pha
    plb
    lda a:$0000,X
    ora a:$0001,X
    beq cancel_numeric_choice_when_script_cancellation_is_available_c01b1d
    rep #$20
    lda f:$7EA1D5
    sta f:$001D01
    sep #$20
    lda f:$7EA160
    inc
    sta f:$7EA160
    jsr routine_c01baf
cancel_numeric_choice_when_script_cancellation_is_available_c01b1d:
    plb
    pla
cancel_numeric_choice_when_script_cancellation_is_available_c01b1f:
    rts
