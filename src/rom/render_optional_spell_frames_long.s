; Recovered Secret of Mana USA routine; behaviour documented in docs/map-oam-spell-frames.md.
.setcpu "65816"
.smart
.a8
.i16

render_optional_spell_frames = $4892

.segment "CODE"
.org $0034
render_optional_spell_frames_long:
    jsr render_optional_spell_frames
    rtl
