; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-publication.md.
.setcpu "65816"
.smart
.a8
.i16

advance_dialogue_tile_progress_or_complete_line = $13A0
copy_dialogue_font_page_and_publish_transfer = $1479
publish_dialogue_window_rows_and_advance_phase = $11CB
publish_single_dialogue_glyph_tile = $1431
request_dialogue_transfer_and_conditional_window_flags = $0FFA

.segment "CODE"
.org $1175
publish_dialogue_glyph_phase_with_real_tile_progress:
    lda f:$001D05
    .a8
    cmp #$07
    beq publish_dialogue_glyph_phase_with_real_tile_progress_c011b6
    lda a:$A162
    bne publish_dialogue_glyph_phase_with_real_tile_progress_c01197
    jsr publish_single_dialogue_glyph_tile
    jsr advance_dialogue_tile_progress_or_complete_line
    inc a:$A15D
    lda a:$A15D
    .a8
    cmp #$08
    beq publish_dialogue_glyph_phase_with_real_tile_progress_c011aa
    dec a:$A15D
    bra publish_dialogue_glyph_phase_with_real_tile_progress_c011aa
publish_dialogue_glyph_phase_with_real_tile_progress_c01197:
    jsr copy_dialogue_font_page_and_publish_transfer
    inc a:$A15D
publish_dialogue_glyph_phase_with_real_tile_progress_c0119d:
    jsr advance_dialogue_tile_progress_or_complete_line
    lda a:$A15D
    .a8
    cmp #$08
    bne publish_dialogue_glyph_phase_with_real_tile_progress_c0119d
    inc a:$A15D
publish_dialogue_glyph_phase_with_real_tile_progress_c011aa:
    .a8
    lda #$66
    ora f:$001D04
    sta f:$001D04
    bra publish_dialogue_glyph_phase_with_real_tile_progress_c011ca
publish_dialogue_glyph_phase_with_real_tile_progress_c011b6:
    rep #$20
    lda f:$001D14
    tax
    sep #$20
    stz a:$0000,X
    jsr publish_dialogue_window_rows_and_advance_phase
    .a8
    lda #$57
    jsr request_dialogue_transfer_and_conditional_window_flags
publish_dialogue_glyph_phase_with_real_tile_progress_c011ca:
    rts
