; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_spell_targets = $396D

.segment "CODE"
.org $38B9
boss_state_prepare_spell_operand:
    ldx $87
    lda [$30],Y
    iny
    iny
    phy
    jsr prepare_boss_spell_targets
    .a16
    lda #$0001
    sta a:$0080,X
    ply
    rts
