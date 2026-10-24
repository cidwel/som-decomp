; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-glyph-tiles.md.
.setcpu "65816"
.smart
.a8
.i16

merge_shifted_dialogue_glyph_bitmaps = $162C

.segment "CODE"
.org $1165
merge_shifted_dialogue_glyphs_clear_upload_cursors_and_advance_phase:
    jsr merge_shifted_dialogue_glyph_bitmaps
    .i16
    ldx #$0000
    stx a:$A191
    stx a:$A173
    inc a:$A15D
    rts
