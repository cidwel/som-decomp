; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-single-icon.md.
.setcpu "65816"
.smart
.a8
.i16

convert_one_original_three_plane_menu_tile_to_output_with_saved_context = $D0CA10

.segment "CODE"
.org $642E
call_native_one_tile_menu_icon_conversion_long:
    jsl f:convert_one_original_three_plane_menu_tile_to_output_with_saved_context
    rtl
