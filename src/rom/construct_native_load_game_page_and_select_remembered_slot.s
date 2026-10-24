; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-load-page.md.
.setcpu "65816"
.smart
.a8
.i16

clear_native_menu_sprite_tables_long_wrapper = $C02ACF
construct_native_menu_page_long_call_wrapper = $C02ACB
highlight_native_saved_slot_rectangle_and_request_publication = $C757DC
reset_native_menu_publication_long_wrapper = $C02AC7
upload_native_menu_sprite_tables_long_wrapper = $C02AD3
upload_native_saved_slot_six_byte_palette = $C7595C

.segment "CODE"
.org $5278
construct_native_load_game_page_and_select_remembered_slot:
    stz a:$A220
    .a8
    lda #$FF
    sta a:$A20F
    .a8
    lda #$02
    tsb a:$A212
    jsl f:construct_native_menu_page_long_call_wrapper
    jsl f:clear_native_menu_sprite_tables_long_wrapper
    jsl f:upload_native_menu_sprite_tables_long_wrapper
    jsl f:upload_native_saved_slot_six_byte_palette
    lda f:$307FFF
    .a8
    cmp #$04
    bcc construct_native_load_game_page_and_select_remembered_slot_c7529f
    .a8
    lda #$00
construct_native_load_game_page_and_select_remembered_slot_c7529f:
    sta f:$307FFF
    sta a:$A211
    jsl f:highlight_native_saved_slot_rectangle_and_request_publication
    jsl f:reset_native_menu_publication_long_wrapper
    rtl
