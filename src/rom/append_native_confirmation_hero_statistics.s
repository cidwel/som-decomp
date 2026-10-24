; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-saved-game-menu-request.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_saved_slot_format_pair = $59E0
append_two_valid_native_saved_slot_statistics = $59FC

.segment "CODE"
.org $53D6
append_native_confirmation_hero_statistics:
    .a8
    lda #$A2
    sta a:$9C00,X
    inx
    .a8
    lda #$AA
    sta a:$9C00,X
    inx
    .a8
    lda #$06
    jsr append_native_saved_slot_format_pair
    jsr append_two_valid_native_saved_slot_statistics
    rts
