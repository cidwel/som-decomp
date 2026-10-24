; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-write.md.
.setcpu "65816"
.smart
.a8
.i16

select_save_slot_copy_and_reject_invalid_pair = $583C

.segment "CODE"
.org $5682
find_first_valid_save_slot_and_read_native_serial_counter:
    stz a:$A211
find_first_valid_save_slot_and_read_native_serial_counter_c75685:
    jsr select_save_slot_copy_and_reject_invalid_pair
    .a8
    lda #$04
    bit a:$A212
    beq find_first_valid_save_slot_and_read_native_serial_counter_c756a1
    trb a:$A212
    lda a:$A211
    inc
    sta a:$A211
    .a8
    cmp #$04
    bne find_first_valid_save_slot_and_read_native_serial_counter_c75685
    .a8
    lda #$00
    bra find_first_valid_save_slot_and_read_native_serial_counter_c756a5
find_first_valid_save_slot_and_read_native_serial_counter_c756a1:
    lda f:$3062B8,X
find_first_valid_save_slot_and_read_native_serial_counter_c756a5:
    sta a:$A175
    rts
