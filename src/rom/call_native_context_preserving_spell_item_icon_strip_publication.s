; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-api.md.
.setcpu "65816"
.smart
.a8
.i16

publish_native_icon_strip_with_saved_menu_context = $D0C856

.segment "CODE"
.org $6429
call_native_context_preserving_spell_item_icon_strip_publication:
    jsl f:publish_native_icon_strip_with_saved_menu_context
    rtl
