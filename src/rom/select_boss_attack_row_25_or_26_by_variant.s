; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

boss_attack_row_public_jump = $C0006C

.segment "CODE"
.org $6183
select_boss_attack_row_25_or_26_by_variant:
    ldx $87
    lda a:$0042,X
    bne select_boss_attack_row_25_or_26_by_variant_c26192
    .a16
    lda #$0025
    jsl f:boss_attack_row_public_jump
    rts
select_boss_attack_row_25_or_26_by_variant_c26192:
    .a16
    lda #$0026
    jsl f:boss_attack_row_public_jump
    rts
