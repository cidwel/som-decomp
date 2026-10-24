; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $384D
boss_state_set_duration_operand:
    ldx $87
    lda [$30],Y
    sta a:$0014,X
    iny
    iny
    rts
