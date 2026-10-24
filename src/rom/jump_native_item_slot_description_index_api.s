; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-api.md.
.setcpu "65816"
.smart
.a8
.i16

query_native_item_slot_description_index_with_saved_context = $6481

.segment "CODE"
.org $6426
jump_native_item_slot_description_index_api:
    jmp query_native_item_slot_description_index_with_saved_context
