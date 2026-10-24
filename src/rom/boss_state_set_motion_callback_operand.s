; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $382F
boss_state_set_motion_callback_operand:
    ldx $87
    lda [$30],Y
    sta a:$0090,X
    iny
    iny
    rts
