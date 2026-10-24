; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-blend.md.
.setcpu "65816"
.smart
.a8
.i16

advance_dialogue_primary_window_phase = $040F
compose_first_dialogue_tile_bitplane_rows = $151A
compose_second_dialogue_tile_bitplane_rows = $1521
publish_dialogue_style_palette_banks = $0968
select_dialogue_background_mask_from_style_list = $159E

.segment "CODE"
.org $14EB
compose_dialogue_glyph_planes_and_publish_active_palette:
    lda f:$001D05
    .a8
    cmp #$07
    bne compose_dialogue_glyph_planes_and_publish_active_palette_c014f9
    jsr advance_dialogue_primary_window_phase
    dec a:$A15C
compose_dialogue_glyph_planes_and_publish_active_palette_c014f9:
    jsr select_dialogue_background_mask_from_style_list
    jsr compose_first_dialogue_tile_bitplane_rows
    jsr compose_second_dialogue_tile_bitplane_rows
    inc a:$A15D
    lda a:$A162
    .a8
    cmp #$01
    bne compose_dialogue_glyph_planes_and_publish_active_palette_c01519
    jsr publish_dialogue_style_palette_banks
    lda f:$001D04
    .a8
    ora #$20
    sta f:$001D04
compose_dialogue_glyph_planes_and_publish_active_palette_c01519:
    rts
