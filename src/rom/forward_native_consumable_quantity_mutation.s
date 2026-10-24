; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-state-api.md.
.setcpu "65816"
.smart
.a8
.i16

change_native_consumable_quantity_and_compact_depleted_inventory = $78C3

.segment "CODE"
.org $6406
forward_native_consumable_quantity_mutation:
    jmp change_native_consumable_quantity_and_compact_depleted_inventory
