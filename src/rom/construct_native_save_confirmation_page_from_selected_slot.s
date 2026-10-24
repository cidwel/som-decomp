; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-saved-game-menu-request.md.
.setcpu "65816"
.smart
.a8
.i16

append_three_native_saved_hero_confirmation_rows = $530C
append_three_present_native_saved_hero_portraits = $5E95
clear_native_menu_sprite_tables_long_wrapper = $C02ACF
construct_native_menu_page_long_call_wrapper = $C02ACB
construct_nine_native_save_confirmation_tile_rows = $553F
render_four_native_selected_save_confirmation_summary_fields = $541E
render_nine_native_save_confirmation_description_rows = $5369
reset_native_menu_publication_long_wrapper = $C02AC7
select_first_active_native_menu_party_hero = $5DDC
upload_native_menu_sprite_tables_long_wrapper = $C02AD3
upload_native_party_page_tiles_and_three_palettes = $5DF9

.segment "CODE"
.org $52AF
construct_native_save_confirmation_page_from_selected_slot:
    jsr select_first_active_native_menu_party_hero
    .a8
    lda #$01
    sta a:$A20F
    jsl f:construct_native_menu_page_long_call_wrapper
    jsr construct_nine_native_save_confirmation_tile_rows
    jsr upload_native_party_page_tiles_and_three_palettes
    lda a:$A215
    sta a:$A216
    lda a:$A211
    sta a:$A162
    beq construct_native_save_confirmation_page_from_selected_slot_c752d8
construct_native_save_confirmation_page_from_selected_slot_c752cf:
    lsr a:$A216
    lsr a:$A216
    dec
    bne construct_native_save_confirmation_page_from_selected_slot_c752cf
construct_native_save_confirmation_page_from_selected_slot_c752d8:
    .a8
    lda #$00
    sta a:$A177
    .i16
    ldx #$0000
construct_native_save_confirmation_page_from_selected_slot_c752e0:
    jsr append_three_native_saved_hero_confirmation_rows
    inc a:$A177
    .a8
    lda #$03
    cmp a:$A177
    bne construct_native_save_confirmation_page_from_selected_slot_c752e0
    jsr render_nine_native_save_confirmation_description_rows
    lda a:$A216
    .a8
    and #$03
    .a8
    cmp #$03
    beq construct_native_save_confirmation_page_from_selected_slot_c752fc
    jsr render_four_native_selected_save_confirmation_summary_fields
construct_native_save_confirmation_page_from_selected_slot_c752fc:
    jsl f:clear_native_menu_sprite_tables_long_wrapper
    jsr append_three_present_native_saved_hero_portraits
    jsl f:upload_native_menu_sprite_tables_long_wrapper
    jsl f:reset_native_menu_publication_long_wrapper
    rtl
