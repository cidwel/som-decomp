; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-saved-game-menu-request.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_saved_slot_text_space_token = $5389
format_and_append_native_saved_slot_decimal_pair = $5AFC
read_first_native_saved_hero_confirmation_statistic = $5B86
read_second_native_saved_hero_confirmation_statistic = $5BA8

.segment "CODE"
.org $5408
append_native_confirmation_hero_extra_statistics:
    jsr read_first_native_saved_hero_confirmation_statistic
    jsr format_and_append_native_saved_slot_decimal_pair
    .a8
    lda #$C1
    sta a:$9C00,X
    inx
    jsr append_native_saved_slot_text_space_token
    jsr read_second_native_saved_hero_confirmation_statistic
    jsr format_and_append_native_saved_slot_decimal_pair
    rts
