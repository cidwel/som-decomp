; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-name-page.md.
.setcpu "65816"
.smart
.a8
.i16

clear_native_menu_sprite_tables_long_wrapper = $C02ACF
construct_native_menu_page_long_call_wrapper = $C02ACB
dispatch_native_name_page_party_icon_variant = $C75217
publish_four_native_name_entry_cursor_corners = $C7503D
reset_native_menu_publication_long_wrapper = $C02AC7
select_first_active_native_menu_party_hero = $5DDC
upload_native_menu_sprite_tables_long_wrapper = $C02AD3
upload_native_party_page_tiles_and_three_palettes = $5DF9

.segment "CODE"
.org $5000
construct_native_hero_name_screen_with_party_graphics_and_cursor:
    jsr select_first_active_native_menu_party_hero
    .a8
    lda #$03
    sta a:$A20F
    jsl f:construct_native_menu_page_long_call_wrapper
    jsr upload_native_party_page_tiles_and_three_palettes
    jsl f:clear_native_menu_sprite_tables_long_wrapper
    jsl f:dispatch_native_name_page_party_icon_variant
    .i16
    ldx #$6013
    stx a:$A159
    jsl f:publish_four_native_name_entry_cursor_corners
    jsl f:upload_native_menu_sprite_tables_long_wrapper
    jsl f:reset_native_menu_publication_long_wrapper
    .a8
    lda #$12
    sta a:$A157
    stz a:$A158
    .a8
    lda #$03
    sta a:$A156
    stz a:$A162
    stz a:$A1CC
    rtl
