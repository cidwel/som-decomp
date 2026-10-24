; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-core.md.
.setcpu "65816"
.smart
.a8
.i16

erase_native_dialogue_window_tile_pairs = $0644

.segment "CODE"
.org $062A
begin_dialogue_window_erasure_at_saved_origin:
    lda a:$A197
    sta a:$A157
    lda a:$A196
    sta a:$A156
    bra erase_native_dialogue_window_tile_pairs
