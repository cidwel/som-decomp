; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-descriptions.md.
.setcpu "65816"
.smart
.a8
.i16

decode_native_menu_font_stream_and_expand_double_rows = $2354

.segment "CODE"
.org $2ADB
decode_native_saved_slot_font_rows_wrapper:
    jsr decode_native_menu_font_stream_and_expand_double_rows
    rtl
