; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-validation.md.
.setcpu "65816"
.smart
.a8
.i16

test_native_save_signature_pair_and_rotate_invalid_mask = $5C04

.segment "CODE"
.org $5BDA
scan_native_save_slot_primary_and_backup_signatures:
    .a8
    lda #$04
    sta a:$A175
    .i16
    ldx #$0000
scan_native_save_slot_primary_and_backup_signatures_c75be2:
    phx
    phx
    jsr test_native_save_signature_pair_and_rotate_invalid_mask
    rep #$20
    pla
    clc
    .a16
    adc #$1000
    tax
    sep #$20
    jsr test_native_save_signature_pair_and_rotate_invalid_mask
    rep #$20
    pla
    clc
    .a16
    adc #$0400
    tax
    sep #$20
    dec a:$A175
    bne scan_native_save_slot_primary_and_backup_signatures_c75be2
    rts
