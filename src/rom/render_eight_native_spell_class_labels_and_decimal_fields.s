; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-page.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_packed_spell_skill_glyph_prefix = $6670
append_native_saved_slot_text_line_token = $538D
append_native_spell_field_decimal_pair = $664E
append_two_native_saved_slot_text_space_tokens = $5386
read_native_spell_class_availability_field = $6661
render_native_saved_slot_text_rows_with_real_vblank = $5D9A

.segment "CODE"
.org $6549
render_eight_native_spell_class_labels_and_decimal_fields:
    .i16
    ldx #$0000
    .i16
    ldy #$0000
    .a8
    lda #$00
    sta a:$A175
render_eight_native_spell_class_labels_and_decimal_fields_c76554:
    stx a:$A178
    jsr append_two_native_saved_slot_text_space_tokens
    jsr append_two_native_saved_slot_text_space_tokens
    jsr read_native_spell_class_availability_field
    .a8
    and #$3F
    beq render_eight_native_spell_class_labels_and_decimal_fields_c76582
    phy
    jsr append_native_packed_spell_skill_glyph_prefix
    .a8
    lda #$C5
    sta a:$9C00,X
    inx
    jsr append_native_spell_field_decimal_pair
    ply
    lda a:$A175
    clc
    .a8
    adc #$2A
    sta a:$9C01,X
    .a8
    lda #$56
    sta a:$9C00,X
    inx
    inx
render_eight_native_spell_class_labels_and_decimal_fields_c76582:
    jsr append_native_saved_slot_text_line_token
    stx a:$A178
    ldx a:$A178
    iny
    lda a:$A175
    inc
    sta a:$A175
    .a8
    cmp #$08
    bne render_eight_native_spell_class_labels_and_decimal_fields_c76554
    phx
    .i16
    ldx #$7040
    stx a:$A18C
    .i16
    ldx #$0380
    stx a:$A191
    .i16
    ldx #$01C0
    stx a:$A199
    .a8
    lda #$08
    sta a:$A171
    plx
    jsr render_native_saved_slot_text_rows_with_real_vblank
    rts
