; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-blend.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $040F
advance_dialogue_primary_window_phase:
    inc a:$A15C
    rts
