; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-saved-game-menu-request.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_confirmation_hero_extra_statistics = $5408
append_native_saved_slot_format_pair = $59E0
append_native_saved_slot_text_space_token = $5389

.segment "CODE"
.org $53EB
append_optional_second_and_third_hero_confirmation_row:
    lda a:$A177
    beq append_optional_second_and_third_hero_confirmation_row_c75407
    .a8
    lda #$A7
    sta a:$9C00,X
    inx
    .a8
    lda #$AA
    sta a:$9C00,X
    inx
    .a8
    lda #$06
    jsr append_native_saved_slot_format_pair
    jsr append_native_saved_slot_text_space_token
    jsr append_native_confirmation_hero_extra_statistics
append_optional_second_and_third_hero_confirmation_row_c75407:
    rts
