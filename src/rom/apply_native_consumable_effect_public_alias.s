; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-consumable-effects.md.
.setcpu "65816"
.smart
.a8
.i16

apply_native_consumable_effect_native_alias = $3812

.segment "CODE"
.org $002A
apply_native_consumable_effect_public_alias:
    jmp apply_native_consumable_effect_native_alias
