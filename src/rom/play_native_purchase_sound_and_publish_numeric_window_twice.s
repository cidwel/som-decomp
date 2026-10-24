; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-purchase.md.
.setcpu "65816"
.smart
.a8
.i16

request_native_menu_audio_2c = $D0CF28
select_native_numeric_menu_window_script = $D0D599

.segment "CODE"
.org $7B00
play_native_purchase_sound_and_publish_numeric_window_twice:
    jsl f:request_native_menu_audio_2c
    jsl f:select_native_numeric_menu_window_script
    jsl f:select_native_numeric_menu_window_script
    rts
