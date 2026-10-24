; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-publication.md.
.setcpu "65816"
.smart
.a8
.i16

advance_empty_dialogue_line_and_reset_render_origin = $13CD
publish_dialogue_tile_pair_and_advance_cursor = $13FD
routine_c013fc = $13FC

.segment "CODE"
.org $13A0
advance_dialogue_tile_progress_or_complete_line:
    jsr publish_dialogue_tile_pair_and_advance_cursor
    inc a:$A181
    inc a:$A1D0
    lda a:$A16A
    cmp a:$A181
    beq advance_empty_dialogue_line_and_reset_render_origin
    lda a:$A1CE
    .a8
    bit #$80
    beq advance_dialogue_tile_progress_or_complete_line_c013c1
    .a8
    and #$7F
    cmp a:$A1D0
    beq advance_empty_dialogue_line_and_reset_render_origin
    bra routine_c013fc
advance_dialogue_tile_progress_or_complete_line_c013c1:
    .a8
    and #$7F
    cmp a:$A1D0
    bne routine_c013fc
    inc a:$A15D
    bra routine_c013fc
