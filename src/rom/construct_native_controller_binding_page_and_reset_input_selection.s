; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-controller-page.md.
.setcpu "65816"
.smart
.a8
.i16

clear_native_menu_sprite_tables_long_wrapper = $C02ACF
construct_native_menu_page_long_call_wrapper = $C02ACB
decode_native_controller_layout_and_publish_four_button_labels = $C76DFC
native_menu_tile_workspace_upload_long_wrapper = $C02AD7
reset_native_menu_publication_long_wrapper = $C02AC7
snapshot_controller_binding_words_and_normalize_runtime_mirror_bits = $C76FC2
snapshot_native_controller_permutation_to_two_buffers = $C76F29
swap_and_mirror_native_controller_frame_tiles = $C76F74
upload_native_menu_sprite_tables_long_wrapper = $C02AD3
upload_native_saved_slot_six_byte_palette = $C7595C

.segment "CODE"
.org $6DAB
construct_native_controller_binding_page_and_reset_input_selection:
    .a8
    lda #$07
    sta a:$A20F
    jsl f:snapshot_controller_binding_words_and_normalize_runtime_mirror_bits
    jsl f:construct_native_menu_page_long_call_wrapper
    jsl f:clear_native_menu_sprite_tables_long_wrapper
    jsl f:upload_native_menu_sprite_tables_long_wrapper
    jsl f:upload_native_saved_slot_six_byte_palette
    jsl f:decode_native_controller_layout_and_publish_four_button_labels
    jsl f:snapshot_native_controller_permutation_to_two_buffers
    ldx a:$A220
    lda a:$A22F,X
    .a8
    and #$03
    beq construct_native_controller_binding_page_and_reset_input_selection_c76dda
    jsl f:swap_and_mirror_native_controller_frame_tiles
construct_native_controller_binding_page_and_reset_input_selection_c76dda:
    jsl f:native_menu_tile_workspace_upload_long_wrapper
    stz a:$A211
    stz a:$A180
    jsl f:reset_native_menu_publication_long_wrapper
    .i16
    ldx #$0006
construct_native_controller_binding_page_and_reset_input_selection_c76deb:
    stz a:$A202,X
    dex
    bne construct_native_controller_binding_page_and_reset_input_selection_c76deb
    .a8
    lda #$04
    sta a:$A1D8
    .a8
    lda #$80
    trb a:$A212
    rtl
