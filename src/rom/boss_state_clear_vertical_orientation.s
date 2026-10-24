; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3899
boss_state_clear_vertical_orientation:
    ldx $87
    lda a:$0098,X
    .a16
    and #$FF7F
    sta a:$0098,X
    rts
