; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-page-callback.md.
.setcpu "65816"
.smart
.a8
.i16

advance_native_party_slot_with_three_slot_wrap = $C76BC7
compare_selected_pad_buttons_against_native_previous_buttons = $325A
load_native_party_slot_activity_minus_one = $C76BB7
preserve_accumulator_byte_and_request_fixed_local_audio_presets = $1BA5

.segment "CODE"
.org $2EE0
cycle_native_party_page_to_next_active_hero:
    phy
    jsr compare_selected_pad_buttons_against_native_previous_buttons
    beq cycle_native_party_page_to_next_active_hero_c02f13
    lda f:$0019FE
    jsl f:advance_native_party_slot_with_three_slot_wrap
    tay
    jsl f:load_native_party_slot_activity_minus_one
    beq cycle_native_party_page_to_next_active_hero_c02f01
    tya
    jsl f:advance_native_party_slot_with_three_slot_wrap
    tay
    jsl f:load_native_party_slot_activity_minus_one
    bne cycle_native_party_page_to_next_active_hero_c02f13
cycle_native_party_page_to_next_active_hero_c02f01:
    tya
    sta f:$0019FE
    .a8
    lda #$07
    sta a:$A210
    jsr preserve_accumulator_byte_and_request_fixed_local_audio_presets
    .a8
    lda #$01
    tsb a:$A20A
cycle_native_party_page_to_next_active_hero_c02f13:
    ply
    rts
