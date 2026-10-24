; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-settings-page.md.
.setcpu "65816"
.smart
.a8
.i16

construct_native_settings_page_and_snapshot_its_selectors = $C75FFD

.segment "CODE"
.org $2ABD
near_call_native_settings_page_constructor:
    jsl f:construct_native_settings_page_and_snapshot_its_selectors
    rts
