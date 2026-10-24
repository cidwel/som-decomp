; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-core.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0638
begin_dialogue_window_erasure_at_current_cursor:
    lda a:$A17D
    sta a:$A157
    lda a:$A17C
    sta a:$A156
