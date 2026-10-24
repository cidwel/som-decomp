; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3875
boss_state_toggle_horizontal_orientation:
    ldx $87
    .a16
    lda #$0040
    eor a:$0098,X
    sta a:$0098,X
    rts
