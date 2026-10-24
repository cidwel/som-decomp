; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-descriptions.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5AFF
append_native_saved_slot_decimal_pair:
    lda a:$A238
    bne append_native_saved_slot_decimal_pair_c75b0b
    .a8
    lda #$80
    sta a:$9C00,X
    bra append_native_saved_slot_decimal_pair_c75b0e
append_native_saved_slot_decimal_pair_c75b0b:
    sta a:$9C00,X
append_native_saved_slot_decimal_pair_c75b0e:
    inx
    lda a:$A239
    sta a:$9C00,X
    inx
    rts
