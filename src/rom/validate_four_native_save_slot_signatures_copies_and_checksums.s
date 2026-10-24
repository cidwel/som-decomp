; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-validation.md.
.setcpu "65816"
.smart
.a8
.i16

compare_native_save_primary_and_backup_payloads = $5C74
scan_native_save_slot_primary_and_backup_checksums = $5C1F
scan_native_save_slot_primary_and_backup_signatures = $5BDA

.segment "CODE"
.org $5BCA
validate_four_native_save_slot_signatures_copies_and_checksums:
    stz a:$A215
    stz a:$A216
    jsr scan_native_save_slot_primary_and_backup_signatures
    jsr compare_native_save_primary_and_backup_payloads
    jsr scan_native_save_slot_primary_and_backup_checksums
    rts
