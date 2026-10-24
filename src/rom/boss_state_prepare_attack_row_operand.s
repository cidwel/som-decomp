; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

boss_attack_row_public_jump = $C0006C

.segment "CODE"
.org $3940
boss_state_prepare_attack_row_operand:
    lda [$30],Y
    iny
    iny
    phy
    ldx $87
    jsl f:boss_attack_row_public_jump
    ply
    ldx $87
    rts
