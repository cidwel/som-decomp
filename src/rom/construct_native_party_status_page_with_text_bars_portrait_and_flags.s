; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16

build_and_upload_sixteen_rotating_native_status_bar_patterns = $6B55
build_native_party_status_background_and_conditional_panels = $6ADF
clear_native_menu_sprite_tables_long_wrapper = $C02ACF
collect_and_render_fifteen_native_party_status_statistics = $66E1
compose_and_render_native_party_status_summary_rows = $6890
construct_native_menu_page_long_call_wrapper = $C02ACB
dispatch_selected_native_party_status_portrait = $6AD2
publish_eight_native_party_status_flag_icons_when_unrestricted = $6367
reset_native_menu_publication_long_wrapper = $C02AC7
upload_native_menu_sprite_tables_long_wrapper = $C02AD3
upload_native_party_page_tiles_and_three_palettes = $5DF9

.segment "CODE"
.org $633C
construct_native_party_status_page_with_text_bars_portrait_and_flags:
    .a8
    lda #$08
    sta a:$A20F
    jsr build_and_upload_sixteen_rotating_native_status_bar_patterns
    jsl f:construct_native_menu_page_long_call_wrapper
    jsr upload_native_party_page_tiles_and_three_palettes
    jsr build_native_party_status_background_and_conditional_panels
    jsr collect_and_render_fifteen_native_party_status_statistics
    jsr compose_and_render_native_party_status_summary_rows
    jsl f:clear_native_menu_sprite_tables_long_wrapper
    jsr dispatch_selected_native_party_status_portrait
    jsr publish_eight_native_party_status_flag_icons_when_unrestricted
    jsl f:upload_native_menu_sprite_tables_long_wrapper
    jsl f:reset_native_menu_publication_long_wrapper
    rtl
