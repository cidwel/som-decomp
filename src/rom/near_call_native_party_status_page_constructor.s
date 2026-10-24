; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16

construct_native_party_status_page_with_text_bars_portrait_and_flags = $C7633C

.segment "CODE"
.org $2A9A
near_call_native_party_status_page_constructor:
    jsl f:construct_native_party_status_page_with_text_bars_portrait_and_flags
    rts
