; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_saved_slot_text_line_token = $538D
append_native_saved_slot_text_space_token = $5389
append_three_native_saved_slot_decimal_digits = $5A1E
collect_native_party_status_word_prefix = $67CC
collect_zero_extended_native_party_status_byte = $67BF
derive_selected_native_party_status_record_offset = $6A95
format_five_native_saved_slot_decimal_digits_via_hardware_division = $5D17
render_native_saved_slot_text_rows_with_real_vblank = $5D9A
select_native_status_bar_conversion_for_first_ten_fields = $67D8
swap_two_native_party_status_statistic_pairs = $67A6

.segment "CODE"
.org $66E1
collect_and_render_fifteen_native_party_status_statistics:
    .i16
    ldx #$5898
    stx a:$A1C7
    .i16
    ldx #$0000
    jsr derive_selected_native_party_status_record_offset
    rep #$20
    tya
    clc
    .a16
    adc #$0008
    tay
    sep #$20
    .a8
    lda #$05
    sta a:$A177
collect_and_render_fifteen_native_party_status_statistics_c766fc:
    jsr collect_zero_extended_native_party_status_byte
    dec a:$A177
    bne collect_and_render_fifteen_native_party_status_statistics_c766fc
    rep #$20
    tya
    clc
    .a16
    adc #$000A
    tay
    sep #$20
    jsr collect_zero_extended_native_party_status_byte
    jsr collect_zero_extended_native_party_status_byte
    tya
    clc
    .a8
    adc #$0B
    tay
    sep #$20
    jsr collect_zero_extended_native_party_status_byte
    jsr collect_native_party_status_word_prefix
    iny
    jsr collect_native_party_status_word_prefix
    jsr swap_two_native_party_status_statistic_pairs
    .i16
    ldx #$0000
    .i16
    ldy #$0000
    .a8
    lda #$03
    sta a:$A178
    stz a:$A175
collect_and_render_fifteen_native_party_status_statistics_c76736:
    .a8
    lda #$05
    sta a:$A177
collect_and_render_fifteen_native_party_status_statistics_c7673b:
    lda a:$A1E1,Y
    xba
    lda a:$A1E0,Y
    iny
    iny
    phy
    tay
    phy
    phx
    jsr select_native_status_bar_conversion_for_first_ten_fields
    plx
    ply
    jsr format_five_native_saved_slot_decimal_digits_via_hardware_division
    jsr append_native_saved_slot_text_space_token
    jsr append_three_native_saved_slot_decimal_digits
    rep #$20
    lda a:$A175
    .a16
    and #$00FF
    .a16
    cmp #$0002
    bne collect_and_render_fifteen_native_party_status_statistics_c7676b
    .a16
    lda #$A8A9
    sta a:$9BFC,X
    bra collect_and_render_fifteen_native_party_status_statistics_c76776
collect_and_render_fifteen_native_party_status_statistics_c7676b:
    .a16
    cmp #$0003
    bne collect_and_render_fifteen_native_party_status_statistics_c76776
    .a16
    lda #$9F9D
    sta a:$9BFC,X
collect_and_render_fifteen_native_party_status_statistics_c76776:
    sep #$20
    ply
    inc a:$A175
    dec a:$A177
    bne collect_and_render_fifteen_native_party_status_statistics_c7673b
    jsr append_native_saved_slot_text_line_token
    dec a:$A178
    bne collect_and_render_fifteen_native_party_status_statistics_c76736
    phx
    .i16
    ldx #$68C0
    stx a:$A18C
    .i16
    ldx #$0280
    stx a:$A191
    .i16
    ldx #$0140
    stx a:$A199
    plx
    .a8
    lda #$03
    sta a:$A171
    jsr render_native_saved_slot_text_rows_with_real_vblank
    rts
