; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-glyph-tiles.md.
.setcpu "65816"
.smart
.a8
.i16

dialogue_glyph_phase_no_operation = $1663

.segment "CODE"
.org $1157
advance_dialogue_glyph_phase_after_no_operation:
    jsr dialogue_glyph_phase_no_operation
    inc a:$A15D
    rts
