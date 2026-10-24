; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-write.md.
.setcpu "65816"
.smart
.a8
.i16

derive_primary_sram_slot_offset_from_selected_index = $57C6
find_first_valid_save_slot_and_read_native_serial_counter = $5682
propagate_native_save_serial_to_each_valid_slot_and_resign = $5653

.segment "CODE"
.org $5618
advance_native_save_serial_and_propagate_counter_to_valid_slots:
    lda a:$A211
    sta a:$A178
    jsr find_first_valid_save_slot_and_read_native_serial_counter
    lda a:$A175
    inc
    .a8
    cmp #$64
    bcc advance_native_save_serial_and_propagate_counter_to_valid_slots_c7562b
    .a8
    lda #$01
advance_native_save_serial_and_propagate_counter_to_valid_slots_c7562b:
    sta a:$A175
    pha
    lda a:$A178
    sta a:$A211
    jsr derive_primary_sram_slot_offset_from_selected_index
    pla
    sta f:$3062B7,X
    sta f:$3072B7,X
    sta f:$3062B8,X
    sta f:$3072B8,X
    jsr propagate_native_save_serial_to_each_valid_slot_and_resign
    lda a:$A178
    sta a:$A211
    rts
