; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-font-rows.md.
.setcpu "65816"
.smart
.a8
.i16

load_dialogue_glyph_rows_or_advance_empty_line = $1664

.segment "CODE"
.org $1150
load_dialogue_glyph_rows_and_advance_phase:
    jsr load_dialogue_glyph_rows_or_advance_empty_line
    inc a:$A15D
    rts
