; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-input-dispatch.md.
.setcpu "65816"
.smart
.a8
.i16

derive_native_menu_button_and_page_callback_table_index = $3275

.segment "CODE"
.org $2B9A
dispatch_pressed_native_menu_button_through_real_callback_table:
    phx
    beq dispatch_pressed_native_menu_button_through_real_callback_table_c02ba3
    jsr derive_native_menu_button_and_page_callback_table_index
    jsr ($3297,X)
dispatch_pressed_native_menu_button_through_real_callback_table_c02ba3:
    plx
    rts
