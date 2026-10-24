; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-font-layout.md.
.setcpu "65816"
.smart
.a8
.i16

assemble_thirty_two_native_menu_text_rows = $2366
decode_dialogue_font_stream_and_all_insertion_commands = $16B8
dialogue_glyph_phase_no_operation = $1663
load_dialogue_glyph_rows_or_advance_empty_line = $1664

.segment "CODE"
.org $2354
decode_native_menu_font_stream_and_expand_double_rows:
    .a8
    lda #$20
    sta a:$A16A
    jsr decode_dialogue_font_stream_and_all_insertion_commands
    jsr load_dialogue_glyph_rows_or_advance_empty_line
    jsr dialogue_glyph_phase_no_operation
    jsr assemble_thirty_two_native_menu_text_rows
    rts
