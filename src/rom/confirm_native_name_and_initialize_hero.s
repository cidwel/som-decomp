; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-name-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

compare_native_name_against_other_party_members = $C75162
derive_native_menu_selected_pad_offset_preserving_accumulator_byte = $3269
expand_local_audio_preset_and_send_four_byte_request = $29D2
store_entered_hero_name_and_initialize_party_record = $C7507F

.segment "CODE"
.org $31E2
confirm_native_name_and_initialize_hero:
    jsr derive_native_menu_selected_pad_offset_preserving_accumulator_byte
    lda a:$A204,X
    .a8
    and #$10
    bne confirm_native_name_and_initialize_hero_c0320f
    lda a:$A1CC
    beq confirm_native_name_and_initialize_hero_c0320a
    jsl f:store_entered_hero_name_and_initialize_party_record
    jsl f:compare_native_name_against_other_party_members
    lda a:$A171
    beq confirm_native_name_and_initialize_hero_c0320a
    .a8
    lda #$07
    jsr expand_local_audio_preset_and_send_four_byte_request
    .a8
    lda #$01
    tsb a:$A20A
    bra confirm_native_name_and_initialize_hero_c0320f
confirm_native_name_and_initialize_hero_c0320a:
    .a8
    lda #$03
    jsr expand_local_audio_preset_and_send_four_byte_request
confirm_native_name_and_initialize_hero_c0320f:
    rts
