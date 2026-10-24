; Recovered Secret of Mana USA routine; behaviour documented in docs/map-graphics-offset-sequencer.md.
.setcpu "65816"
.smart
.a8
.i16

advance_native_graphics_offset_pattern_and_publish_source = $B052

.segment "CODE"
.org $B033
advance_selected_graphics_offset_pattern_with_saved_data_bank:
    sep #$30
    bit $90
    bvs advance_selected_graphics_offset_pattern_with_saved_data_bank_c1b03a
    rtl
advance_selected_graphics_offset_pattern_with_saved_data_bank_c1b03a:
    lda $F4
    .a8
    and #$07
    asl
    asl
    asl
    tax
    phb
    .a8
    lda #$7F
    pha
    plb
    jsr advance_native_graphics_offset_pattern_and_publish_source
    sep #$20
    plb
    .a8
    lda #$C0
    sta $90
    rtl
