; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $38AF
boss_state_set_field_a7_operand:
    ldx $87
    lda [$30],Y
    sta a:$00A7,X
    iny
    iny
    rts
