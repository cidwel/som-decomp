; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-saved-game-menu-request.md.
.setcpu "65816"
.smart
.a8
.i16

count_active_native_menu_saved_slot_nibbles = $C02A14
derive_selected_save_slot_primary_or_backup_offset = $5D00

.segment "CODE"
.org $5B17
count_active_hero_nibbles_in_selected_native_save_copy:
    rep #$20
    phx
    jsr derive_selected_save_slot_primary_or_backup_offset
    sep #$20
    jsl f:count_active_native_menu_saved_slot_nibbles
    plx
    rts
