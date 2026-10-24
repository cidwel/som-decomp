; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

boss_attack_row_secondary_jump = $3854

.segment "CODE"
.org $006C
boss_attack_row_public_jump:
    jmp boss_attack_row_secondary_jump
