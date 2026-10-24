; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-detail.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_saved_slot_format_pair = $59E0
append_native_saved_slot_text_line_token = $538D
initialize_six_native_blank_detail_rows = $6BCF
read_native_spell_class_availability_field = $6661
render_six_native_detail_rows_and_rebuild_selection_frame = $6512
select_bank_CA_for_native_terminated_token_copy = $6AB7

.segment "CODE"
.org $649E
compose_native_selected_spell_class_detail_tokens:
    jsr initialize_six_native_blank_detail_rows
    lda a:$A211
    sta a:$A175
    jsr read_native_spell_class_availability_field
    .a8
    and #$3F
    beq compose_native_selected_spell_class_detail_tokens_c7650e
    pha
    rep #$20
    lda a:$A211
    .a16
    and #$00FF
    asl
    sta a:$A173
    asl
    clc
    adc a:$A173
    sep #$20
    .i16
    ldy #$0006
    .i16
    ldx #$0000
    sta a:$A1D0
    pla
compose_native_selected_spell_class_detail_tokens_c764cc:
    lsr
    bcc compose_native_selected_spell_class_detail_tokens_c76508
    pha
    .a8
    lda #$56
    sta a:$9C00,X
    inx
    lda a:$A1D0
    .a8
    cmp #$2A
    bcc compose_native_selected_spell_class_detail_tokens_c764e0
    sec
    .a8
    sbc #$06
compose_native_selected_spell_class_detail_tokens_c764e0:
    sta a:$9C00,X
    pha
    inx
    .a8
    lda #$08
    jsr append_native_saved_slot_format_pair
    .a8
    lda #$C5
    sta a:$9C00,X
    inx
    .a8
    lda #$00
    xba
    pla
    rep #$20
    asl
    phx
    tax
    lda f:$CA0B2E,X
    tay
    sep #$20
    plx
    jsr select_bank_CA_for_native_terminated_token_copy
    jsr append_native_saved_slot_text_line_token
    pla
compose_native_selected_spell_class_detail_tokens_c76508:
    inc a:$A1D0
    dey
    bne compose_native_selected_spell_class_detail_tokens_c764cc
compose_native_selected_spell_class_detail_tokens_c7650e:
    jsr render_six_native_detail_rows_and_rebuild_selection_frame
    rts
