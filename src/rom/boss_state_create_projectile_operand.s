; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

create_boss_projectile_with_graphics_and_palette = $33BE

.segment "CODE"
.org $38CB
boss_state_create_projectile_operand:
    ldx $87
    sep #$20
    stz $96
    stz $98
    stz $9A
    lda [$30],Y
    sta $99
    iny
    lda [$30],Y
    sta $95
    bpl boss_state_create_projectile_operand_c238e4
    .a8
    lda #$FF
    sta $96
boss_state_create_projectile_operand_c238e4:
    iny
    lda [$30],Y
    sta $97
    bpl boss_state_create_projectile_operand_c238ef
    .a8
    lda #$FF
    sta $98
boss_state_create_projectile_operand_c238ef:
    iny
    rep #$20
    phy
    ldy a:$00A9,X
    lda a:$0098,X
    .a16
    bit #$0040
    beq boss_state_create_projectile_operand_c23906
    lda $95
    .a16
    eor #$FFFF
    inc
    sta $95
boss_state_create_projectile_operand_c23906:
    lda $99
    jsr create_boss_projectile_with_graphics_and_palette
    ply
    ldx $87
    rts
