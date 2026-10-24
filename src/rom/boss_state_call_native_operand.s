; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

boss_state_jump_to_native_pointer = $391D

.segment "CODE"
.org $390F
boss_state_call_native_operand:
    ldx $87
    lda [$30],Y
    iny
    iny
    phy
    jsr boss_state_jump_to_native_pointer
    ply
    ldx $87
    rts
