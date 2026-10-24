; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-saved-game-menu-request.md.
.setcpu "65816"
.smart
.a8
.i16

count_active_hero_nibbles_in_selected_native_save_copy = $5B17

.segment "CODE"
.org $5464
append_native_save_confirmation_active_hero_count:
    .i16
    ldx #$0000
    jsr count_active_hero_nibbles_in_selected_native_save_copy
    tya
    clc
    .a8
    adc #$B5
    sta a:$9C00,X
    inx
    rts
