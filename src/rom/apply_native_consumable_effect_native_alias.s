; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-consumable-effects.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_native_consumable_effect_actor_context_and_dispatch = $54E7

.segment "CODE"
.org $3812
apply_native_consumable_effect_native_alias:
    jmp prepare_native_consumable_effect_actor_context_and_dispatch
