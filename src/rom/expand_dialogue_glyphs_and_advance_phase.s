; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-glyph-tiles.md.
.setcpu "65816"
.smart
.a8
.i16

expand_dialogue_glyph_bitmaps_and_merge_tile_borders = $15B9

.segment "CODE"
.org $115E
expand_dialogue_glyphs_and_advance_phase:
    jsr expand_dialogue_glyph_bitmaps_and_merge_tile_borders
    inc a:$A15D
    rts
