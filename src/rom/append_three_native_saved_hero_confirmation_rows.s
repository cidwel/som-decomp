; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-saved-game-menu-request.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_confirmation_hero_level = $53C8
append_native_confirmation_hero_statistics = $53D6
append_native_saved_slot_format_pair = $59E0
append_native_saved_slot_text_line_token = $538D
append_optional_second_and_third_hero_confirmation_row = $53EB
append_terminated_native_saved_hero_confirmation_name = $5394
append_two_native_saved_slot_text_space_tokens = $5386
derive_selected_save_slot_primary_or_backup_offset = $5D00

.segment "CODE"
.org $530C
append_three_native_saved_hero_confirmation_rows:
    phx
    rep #$20
    jsr derive_selected_save_slot_primary_or_backup_offset
    stx a:$A171
    lda a:$A177
    .a16
    and #$00FF
    asl
    sta a:$A173
    asl
    clc
    adc a:$A173
    clc
    adc a:$A171
    tax
    sep #$20
    lda f:$306283,X
    plx
    .a8
    cmp #$01
    bne append_three_native_saved_hero_confirmation_rows_c7535f
    lda a:$A216
    .a8
    and #$03
    .a8
    cmp #$03
    beq append_three_native_saved_hero_confirmation_rows_c7535f
    jsr append_terminated_native_saved_hero_confirmation_name
    .a8
    lda #$07
    jsr append_native_saved_slot_format_pair
    jsr append_native_confirmation_hero_level
    jsr append_native_saved_slot_text_line_token
    jsr append_two_native_saved_slot_text_space_tokens
    jsr append_native_confirmation_hero_statistics
    jsr append_native_saved_slot_text_line_token
    jsr append_two_native_saved_slot_text_space_tokens
    jsr append_optional_second_and_third_hero_confirmation_row
    jsr append_native_saved_slot_text_line_token
    bra append_three_native_saved_hero_confirmation_rows_c75368
append_three_native_saved_hero_confirmation_rows_c7535f:
    jsr append_native_saved_slot_text_line_token
    jsr append_native_saved_slot_text_line_token
    jsr append_native_saved_slot_text_line_token
append_three_native_saved_hero_confirmation_rows_c75368:
    rts
