; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-validation.md.
.setcpu "65816"
.smart
.a8
.i16

test_two_native_save_checksums_and_rotate_invalid_mask = $5C3B

.segment "CODE"
.org $5C1F
scan_native_save_slot_primary_and_backup_checksums:
    .i16
    ldx #$0000
    .a8
    lda #$04
    sta a:$A175
scan_native_save_slot_primary_and_backup_checksums_c75c27:
    phx
    jsr test_two_native_save_checksums_and_rotate_invalid_mask
    rep #$20
    pla
    clc
    .a16
    adc #$0400
    tax
    sep #$20
    dec a:$A175
    bne scan_native_save_slot_primary_and_backup_checksums_c75c27
    rts
