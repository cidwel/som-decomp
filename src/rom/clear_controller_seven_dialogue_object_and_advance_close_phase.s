; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-window-close.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $06DA
clear_controller_seven_dialogue_object_and_advance_close_phase:
    rep #$20
    lda f:$001D14
    tax
    sep #$20
    stz a:$0000,X
    inc a:$A15E
    rts
