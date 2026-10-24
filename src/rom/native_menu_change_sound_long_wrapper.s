; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-actions.md.
.setcpu "65816"
.smart
.a8
.i16

request_native_menu_change_or_confirm_preset_preserving_low_accumulator = $1BAA

.segment "CODE"
.org $2AF2
native_menu_change_sound_long_wrapper:
    jsr request_native_menu_change_or_confirm_preset_preserving_low_accumulator
    rtl
