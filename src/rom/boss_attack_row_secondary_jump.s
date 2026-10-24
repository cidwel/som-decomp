; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_attack_row_and_appearance_context = $45D6

.segment "CODE"
.org $3854
boss_attack_row_secondary_jump:
    jmp prepare_boss_attack_row_and_appearance_context
