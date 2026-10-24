; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16

collect_native_party_status_byte_shared_tail = $67CF

.segment "CODE"
.org $67CC
collect_native_party_status_word_prefix:
    jsr collect_native_party_status_byte_shared_tail
