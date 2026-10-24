; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-descriptions.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_saved_slot_format_pair = $59E0
append_native_saved_slot_location_name = $5A32
append_native_saved_slot_name_or_empty_label = $5AAB
append_native_saved_slot_seven_bit_value = $5A8A
append_native_saved_slot_text_line_token = $538D
append_native_saved_slot_text_space_token = $5389
append_two_native_saved_slot_text_space_tokens = $5386
append_two_valid_native_saved_slot_statistics = $59FC
append_valid_native_saved_slot_level = $59EC
configure_and_render_two_native_saved_slot_text_rows = $5D68
validate_four_native_save_slot_signatures_copies_and_checksums = $5BCA

.segment "CODE"
.org $5979
render_four_native_saved_slot_descriptions:
    .a8
    lda #$00
    sta a:$A162
    jsr validate_four_native_save_slot_signatures_copies_and_checksums
    lda a:$A215
    sta a:$A216
render_four_native_saved_slot_descriptions_c75987:
    stz a:$A1D4
    jsr append_valid_native_saved_slot_level
    jsr append_native_saved_slot_name_or_empty_label
    jsr append_native_saved_slot_text_line_token
    jsr append_two_native_saved_slot_text_space_tokens
    jsr append_native_saved_slot_text_space_token
    stz a:$A177
    jsr append_two_valid_native_saved_slot_statistics
    .i16
    ldy #$0000
    sty a:$A199
    jsr configure_and_render_two_native_saved_slot_text_rows
    .i16
    ldx #$0000
    .a8
    lda #$05
    jsr append_native_saved_slot_format_pair
    jsr append_native_saved_slot_location_name
    jsr append_native_saved_slot_text_line_token
    .a8
    lda #$03
    jsr append_native_saved_slot_format_pair
    jsr append_native_saved_slot_text_space_token
    jsr append_native_saved_slot_seven_bit_value
    .i16
    ldy #$02A0
    sty a:$A199
    jsr configure_and_render_two_native_saved_slot_text_rows
    lsr a:$A216
    lsr a:$A216
    inc a:$A162
    .a8
    lda #$04
    cmp a:$A162
    bne render_four_native_saved_slot_descriptions_c75987
    .a8
    lda #$02
    trb a:$A20A
    rtl
