; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_party_status_count_glyph_and_newline = $6986
count_active_native_menu_live_slot_bytes = $C029FC
select_bank_C7_and_copy_native_terminated_tokens = $6ABE

.segment "CODE"
.org $6978
append_native_party_status_active_slot_count_label:
    .i16
    ldy #$7B53
    jsr select_bank_C7_and_copy_native_terminated_tokens
    jsl f:count_active_native_menu_live_slot_bytes
    jsr append_native_party_status_count_glyph_and_newline
    rts
