; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $38A5
boss_state_set_field_1e3_operand:
    ldx $87
    lda [$30],Y
    sta a:$01E3,X
    iny
    iny
    rts
