; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $395C
boss_state_jump_to_operand_pointer:
    lda [$30],Y
    sta $30
    ldy $C5
    rts
