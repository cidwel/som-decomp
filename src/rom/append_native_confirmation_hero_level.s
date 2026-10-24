; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-saved-game-menu-request.md.
.setcpu "65816"
.smart
.a8
.i16

append_two_native_saved_slot_text_space_tokens = $5386
reserve_level_digit_and_enter_native_saved_level_formatter = $5AF8

.segment "CODE"
.org $53C8
append_native_confirmation_hero_level:
    .a8
    lda #$A6
    sta a:$9C00,X
    inx
    jsr append_two_native_saved_slot_text_space_tokens
    dex
    jsr reserve_level_digit_and_enter_native_saved_level_formatter
    rts
