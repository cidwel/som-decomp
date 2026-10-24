; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-personality-page.md.
.setcpu "65816"
.smart
.a8
.i16

clear_native_menu_sprite_tables_long_wrapper = $C02ACF
construct_native_menu_page_long_call_wrapper = $C02ACB
derive_native_personality_selector_cursor_coordinates = $C76C45
dispatch_native_name_page_party_icon_variant = $C75217
native_menu_tile_workspace_upload_long_wrapper = $C02AD7
publish_four_native_name_entry_cursor_corners = $C7503D
publish_native_skill_count_and_selector_rows = $6C58
reset_native_menu_publication_long_wrapper = $C02AC7
upload_native_menu_sprite_tables_long_wrapper = $C02AD3
upload_native_party_page_tiles_and_three_palettes = $5DF9

.segment "CODE"
.org $6BE3
construct_native_hero_personality_page:
    .a8
    lda #$04
    sta a:$A20F
    .a8
    lda #$00
    xba
    lda f:$0019FE
    sta a:$A22B
    tax
    lda a:$A257,X
    sta a:$A136
    jsl f:construct_native_menu_page_long_call_wrapper
    jsr publish_native_skill_count_and_selector_rows
    jsl f:native_menu_tile_workspace_upload_long_wrapper
    jsl f:clear_native_menu_sprite_tables_long_wrapper
    jsr upload_native_party_page_tiles_and_three_palettes
    lda a:$A15A
    sta a:$A175
    .a8
    lda #$00
    xba
    lda a:$A22B
    tax
    lda a:$CC7D,X
    cmp a:$A175
    bcc construct_native_hero_personality_page_c76c23
    lda a:$A175
construct_native_hero_personality_page_c76c23:
    sta a:$A211
    jsl f:derive_native_personality_selector_cursor_coordinates
    jsl f:publish_four_native_name_entry_cursor_corners
    jsl f:dispatch_native_name_page_party_icon_variant
    jsl f:upload_native_menu_sprite_tables_long_wrapper
    jsl f:reset_native_menu_publication_long_wrapper
    .a8
    lda #$0A
    sta a:$A19F
    .a8
    lda #$20
    trb a:$A212
    rtl
