; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-page.md.
.setcpu "65816"
.smart
.a8
.i16

construct_native_spell_or_item_page_from_selected_description = $C76304

.segment "CODE"
.org $2A95
near_call_native_item_page_constructor:
    jsl f:construct_native_spell_or_item_page_from_selected_description
    rts
