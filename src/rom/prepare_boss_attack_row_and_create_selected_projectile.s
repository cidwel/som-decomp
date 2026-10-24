; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-attack-selection.md.
.setcpu "65816"
.smart
.a8
.i16

boss_attack_row_public_jump = $C0006C
create_boss_projectile_with_graphics_and_palette = $33BE

.segment "CODE"
.org $58EF
prepare_boss_attack_row_and_create_selected_projectile:
    sta $00
    ldx $87
    jsl f:boss_attack_row_public_jump
    ldx $87
    ldy a:$00A9,X
    stz $95
    stz $97
    lda $00
    jsr create_boss_projectile_with_graphics_and_palette
    rts
