; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-grandchildren.md.
.setcpu "65816"
.smart
.a8
.i16

boss_attack_row_public_jump = $C0006C
create_boss_projectile_with_graphics_and_palette = $33BE

.segment "CODE"
.org $82C0
prepare_attack_row_then_create_parent_projectile:
    sta $46
    ldx $87
    sep #$20
    stz a:$005A,X
    rep #$20
    lda a:$00B0,X
    tax
    lda $46
    jsl f:boss_attack_row_public_jump
    ldx $87
    ldy a:$00A9,X
    lda a:$00B0,X
    tax
    lda $46
    jsr create_boss_projectile_with_graphics_and_palette
    rts
