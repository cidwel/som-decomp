; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-personality-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

commit_native_hero_personality_and_reinitialize_actor_program = $C76CA7
compare_selected_pad_buttons_against_native_previous_buttons = $325A
highlight_native_menu_actor_sprite_palette = $1EFD
preserve_accumulator_byte_and_request_fixed_local_audio_presets = $1BA5
routine_c76d5c = $C76D5C

.segment "CODE"
.org $2F15
confirm_native_personality_selection_or_open_selector:
    jsr compare_selected_pad_buttons_against_native_previous_buttons
    beq confirm_native_personality_selection_or_open_selector_c02f40
    lda a:$A212
    .a8
    bit #$20
    bne confirm_native_personality_selection_or_open_selector_c02f32
    jsr preserve_accumulator_byte_and_request_fixed_local_audio_presets
    jsr highlight_native_menu_actor_sprite_palette
    jsl f:routine_c76d5c
    .a8
    lda #$20
    tsb a:$A212
    bra confirm_native_personality_selection_or_open_selector_c02f40
confirm_native_personality_selection_or_open_selector_c02f32:
    jsl f:commit_native_hero_personality_and_reinitialize_actor_program
    .a8
    lda #$01
    tsb a:$A20A
    .a8
    lda #$20
    trb a:$A212
confirm_native_personality_selection_or_open_selector_c02f40:
    rts
