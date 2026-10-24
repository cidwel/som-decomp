; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-dialogue.md.
.setcpu "65816"
.smart
.a8
.i16

display_native_shop_message_wait_release_and_new_button_then_refresh = $7E95
request_native_menu_audio_0d = $D0CF00

.segment "CODE"
.org $7B7D
play_native_shop_error_then_display_selected_notice:
    jsl f:request_native_menu_audio_0d
    jmp display_native_shop_message_wait_release_and_new_button_then_refresh
