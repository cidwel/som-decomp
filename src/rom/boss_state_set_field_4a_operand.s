; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3843
boss_state_set_field_4a_operand:
    ldx $87
    lda [$30],Y
    sta a:$004A,X
    iny
    iny
    rts
