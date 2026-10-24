; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-descriptions.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_saved_slot_level_label = $5AED

.segment "CODE"
.org $59EC
append_valid_native_saved_slot_level:
    .i16
    ldx #$0000
    lda a:$A216
    .a8
    and #$03
    .a8
    cmp #$03
    beq append_valid_native_saved_slot_level_c759fb
    jsr append_native_saved_slot_level_label
append_valid_native_saved_slot_level_c759fb:
    rts
