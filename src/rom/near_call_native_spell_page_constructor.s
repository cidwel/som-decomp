; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-page.md.
.setcpu "65816"
.smart
.a8
.i16

select_native_spell_page_description_and_enter_common_constructor = $C762FD

.segment "CODE"
.org $2A90
near_call_native_spell_page_constructor:
    jsl f:select_native_spell_page_description_and_enter_common_constructor
    rts
