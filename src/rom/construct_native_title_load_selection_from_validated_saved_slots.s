; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-title-page.md.
.setcpu "65816"
.smart
.a8
.i16

clear_native_menu_sprite_tables_long_wrapper = $C02ACF
construct_native_menu_page_long_call_wrapper = $C02ACB
highlight_native_saved_slot_rectangle_and_request_publication = $C757DC
request_local_audio_preset_long = $C02B02
reset_native_menu_publication_long_wrapper = $C02AC7
upload_native_menu_sprite_tables_long_wrapper = $C02AD3
upload_native_saved_slot_six_byte_palette = $C7595C
validate_four_native_save_slot_signatures_copies_and_checksums = $5BCA

.segment "CODE"
.org $5229
construct_native_title_load_selection_from_validated_saved_slots:
    .a8
    lda #$08
    jsl f:request_local_audio_preset_long
    stz a:$A220
    .a8
    lda #$00
    sta a:$A20F
    jsl f:construct_native_menu_page_long_call_wrapper
    jsl f:clear_native_menu_sprite_tables_long_wrapper
    jsl f:upload_native_menu_sprite_tables_long_wrapper
    jsl f:upload_native_saved_slot_six_byte_palette
    .a8
    lda #$00
    sta a:$A211
    jsr validate_four_native_save_slot_signatures_copies_and_checksums
    lda a:$A215
    inc
    beq construct_native_title_load_selection_from_validated_saved_slots_c7525a
    inc a:$A211
    bra construct_native_title_load_selection_from_validated_saved_slots_c75260
construct_native_title_load_selection_from_validated_saved_slots_c7525a:
    .a8
    lda #$00
    sta f:$307FFF
construct_native_title_load_selection_from_validated_saved_slots_c75260:
    .a8
    lda #$06
    sta a:$A202
    jsl f:highlight_native_saved_slot_rectangle_and_request_publication
    .a8
    lda #$00
    sta a:$A202
    jsl f:reset_native_menu_publication_long_wrapper
    rtl
