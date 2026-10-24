; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-detail.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_saved_slot_format_pair = $59E0
append_native_saved_slot_text_line_token = $538D
append_native_saved_slot_text_space_token = $5389
append_two_native_saved_slot_text_space_tokens = $5386
format_and_append_native_saved_slot_decimal_pair = $5AFC
initialize_six_native_blank_detail_rows = $6BCF
jump_native_item_slot_description_index_api = $C06426
render_six_native_detail_rows_and_rebuild_selection_frame = $6512
select_bank_C7_and_copy_native_terminated_tokens = $6ABE
select_bank_CA_for_native_terminated_token_copy = $6AB7

.segment "CODE"
.org $6411
compose_native_selected_item_detail_tokens:
    jsr initialize_six_native_blank_detail_rows
    .a8
    lda #$00
    xba
    lda a:$A211
    tax
    lda a:$CC54,X
    .a8
    cmp #$FF
    beq compose_native_selected_item_detail_tokens_c7649a
    .i16
    ldx #$0000
    jsr append_native_saved_slot_text_space_token
    .i16
    ldy #$7BA5
    jsr select_bank_C7_and_copy_native_terminated_tokens
    .a8
    lda #$04
    jsr append_native_saved_slot_format_pair
    phx
    rep #$20
    lda a:$A211
    .a16
    and #$00FF
    asl
    tax
    lda f:$C77BB7,X
    tay
    sep #$20
    plx
    jsr select_bank_C7_and_copy_native_terminated_tokens
    jsr append_native_saved_slot_text_line_token
    .a8
    lda #$04
    jsr append_native_saved_slot_format_pair
    .i16
    ldy #$7BAA
    jsr select_bank_C7_and_copy_native_terminated_tokens
    jsr append_two_native_saved_slot_text_space_tokens
    .a8
    lda #$00
    xba
    lda a:$A211
    tay
    lda a:$CFB0,Y
    phy
    inc
    tay
    jsr format_and_append_native_saved_slot_decimal_pair
    .i16
    ldy #$7BB5
    jsr select_bank_C7_and_copy_native_terminated_tokens
    ply
    .a8
    lda #$00
    xba
    lda a:$CFB8,Y
    inc
    tay
    jsr format_and_append_native_saved_slot_decimal_pair
    jsr append_native_saved_slot_text_line_token
    rep #$20
    phx
    lda a:$A211
    .a16
    and #$00FF
    tay
    jsl f:jump_native_item_slot_description_index_api
    asl
    tax
    lda f:$CA0A9E,X
    tay
    plx
    sep #$20
    jsr select_bank_CA_for_native_terminated_token_copy
compose_native_selected_item_detail_tokens_c7649a:
    jsr render_six_native_detail_rows_and_rebuild_selection_frame
    rts
