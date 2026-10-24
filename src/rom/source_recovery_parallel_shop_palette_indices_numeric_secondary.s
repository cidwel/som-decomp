; Eight selected settings/shop palette-record indices; no RGB payload.
.setcpu "65816"
.segment "CODE"
.org $7161
.macro native_palette_record_index index
    .assert index >= 0 .and index < 8, error, "palette record domain"
    .byte index
.endmacro
secondary_palette_for_cursor_0:
    native_palette_record_index 0
secondary_palette_for_cursor_1:
    native_palette_record_index 0
secondary_palette_for_cursor_2:
    native_palette_record_index 0
secondary_palette_for_cursor_3:
    native_palette_record_index 0
secondary_palette_for_cursor_4:
    native_palette_record_index 0
secondary_palette_for_cursor_5:
    native_palette_record_index 0
secondary_palette_for_cursor_6:
    native_palette_record_index 0
secondary_palette_for_cursor_7:
    native_palette_record_index 0
