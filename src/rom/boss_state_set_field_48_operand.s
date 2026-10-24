; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3839
boss_state_set_field_48_operand:
    ldx $87
    lda [$30],Y
    sta a:$0048,X
    iny
    iny
    rts
