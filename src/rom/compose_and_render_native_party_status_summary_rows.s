; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16

append_first_four_native_party_status_restriction_labels = $68E7
append_native_party_status_active_slot_count_label = $6978
append_native_party_status_current_and_maximum_hit_points = $69C2
append_native_party_status_experience_quantity = $6933
append_native_party_status_gold_quantity_and_suffix = $6997
append_native_party_status_level_label_and_decimal = $6A2F
append_native_party_status_magic_points_when_not_boy = $69F8
append_native_party_status_remaining_experience_unless_level99 = $695B
append_native_saved_slot_text_line_token = $538D
append_selected_native_party_status_twelve_byte_name = $6A4F
read_selected_native_party_status_excluding_low_two_bits = $6AA4
render_native_saved_slot_text_rows_with_real_vblank = $5D9A

.segment "CODE"
.org $6890
compose_and_render_native_party_status_summary_rows:
    .i16
    ldx #$0000
    jsr append_selected_native_party_status_twelve_byte_name
    jsr append_native_party_status_level_label_and_decimal
    jsr append_native_party_status_current_and_maximum_hit_points
    jsr append_native_party_status_magic_points_when_not_boy
    jsr append_native_party_status_experience_quantity
    jsr append_native_party_status_remaining_experience_unless_level99
    rep #$20
    jsr read_selected_native_party_status_excluding_low_two_bits
    sep #$20
    bne compose_and_render_native_party_status_summary_rows_c768b9
    jsr append_native_party_status_active_slot_count_label
    jsr append_native_saved_slot_text_line_token
    jsr append_native_party_status_gold_quantity_and_suffix
    bra compose_and_render_native_party_status_summary_rows_c768bc
compose_and_render_native_party_status_summary_rows_c768b9:
    jsr append_first_four_native_party_status_restriction_labels
compose_and_render_native_party_status_summary_rows_c768bc:
    phx
    .i16
    ldx #$6C20
    stx a:$A18C
    .i16
    ldx #$0380
    stx a:$A191
    .i16
    ldx #$01C0
    stx a:$A199
    plx
    .a8
    lda #$09
    sta a:$A171
    rep #$20
    jsr read_selected_native_party_status_excluding_low_two_bits
    sep #$20
    beq compose_and_render_native_party_status_summary_rows_c768e3
    .a8
    lda #$0A
    sta a:$A171
compose_and_render_native_party_status_summary_rows_c768e3:
    jsr render_native_saved_slot_text_rows_with_real_vblank
    rts
