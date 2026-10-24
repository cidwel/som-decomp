; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-api.md.
.setcpu "65816"
.smart
.a8
.i16

call_native_context_preserving_spell_item_icon_strip_publication = $6429

.segment "CODE"
.org $6409
jump_native_spell_item_icon_strip_api:
    jmp call_native_context_preserving_spell_item_icon_strip_publication
