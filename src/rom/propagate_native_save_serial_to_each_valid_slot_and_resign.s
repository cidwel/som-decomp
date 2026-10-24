; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-write.md.
.setcpu "65816"
.smart
.a8
.i16

derive_primary_sram_slot_offset_from_selected_index = $57C6
select_save_slot_copy_and_reject_invalid_pair = $583C
write_two_save_signatures_and_checksum_primary_payload = $56A9

.segment "CODE"
.org $5653
propagate_native_save_serial_to_each_valid_slot_and_resign:
    phx
    .i16
    ldy #$0004
    stz a:$A211
propagate_native_save_serial_to_each_valid_slot_and_resign_c7565a:
    jsr select_save_slot_copy_and_reject_invalid_pair
    .a8
    lda #$04
    bit a:$A212
    bne propagate_native_save_serial_to_each_valid_slot_and_resign_c75675
    jsr derive_primary_sram_slot_offset_from_selected_index
    lda a:$A175
    sta f:$3062B8,X
    sta f:$3072B8,X
    jsr write_two_save_signatures_and_checksum_primary_payload
propagate_native_save_serial_to_each_valid_slot_and_resign_c75675:
    .a8
    lda #$04
    trb a:$A212
    inc a:$A211
    dey
    bne propagate_native_save_serial_to_each_valid_slot_and_resign_c7565a
    plx
    rts
