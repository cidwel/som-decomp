; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-weapon-action.md.
.setcpu "65816"
.smart
.a8
.i16

build_native_three_actor_menu_target_list_and_count = $D0DA60
cast_spell_public_jump = $C0001B
dispatch_native_menu_ring_phase_from_original_jump_table = $6BF8
encode_native_menu_target_mask_from_selected_actor_or_multi_target_flags = $787E
persist_native_menu_category_row_and_equipment_rank = $C06B4C
publish_selected_equipment_description_row = $D0CE5D
request_event_menu_loop_and_initialize_input_state = $692D
request_native_menu_audio_0d = $D0CF00
request_native_menu_audio_0e = $D0CF08
routine_c07275 = $7275
select_native_menu_target_with_controller_edges_and_real_vblank = $D0DB58
test_native_equipment_row_eligibility_from_hero_state_and_level = $C073AC
wait_vblank_before_polling_native_menu_input = $695E
write_native_menu_cast_record_single_or_multiple_actor_targets = $731F

.segment "CODE"
.org $72B3
select_native_menu_spell_targets_and_validate_original_cast_request:
    jsl f:persist_native_menu_category_row_and_equipment_rank
    jsl f:publish_selected_equipment_description_row
    sep #$20
    sta a:$19D3
    rep #$30
    jsl f:test_native_equipment_row_eligibility_from_hero_state_and_level
    bcs select_native_menu_spell_targets_and_validate_original_cast_request_c072cf
    jsl f:request_native_menu_audio_0d
    jmp request_event_menu_loop_and_initialize_input_state
select_native_menu_spell_targets_and_validate_original_cast_request_c072cf:
    sep #$20
    sta a:$185B
    stx a:$182C
    jsl f:build_native_three_actor_menu_target_list_and_count
    beq select_native_menu_spell_targets_and_validate_original_cast_request_c072e6
    jsl f:select_native_menu_target_with_controller_edges_and_real_vblank
    beq select_native_menu_spell_targets_and_validate_original_cast_request_c072fd
    jmp routine_c07275
select_native_menu_spell_targets_and_validate_original_cast_request_c072e6:
    jsl f:request_native_menu_audio_0d
select_native_menu_spell_targets_and_validate_original_cast_request_c072ea:
    rep #$20
    jsr wait_vblank_before_polling_native_menu_input
    jsr dispatch_native_menu_ring_phase_from_original_jump_table
    lda a:$1800
    .a16
    and #$8000
    bne select_native_menu_spell_targets_and_validate_original_cast_request_c072ea
    jmp routine_c07275
select_native_menu_spell_targets_and_validate_original_cast_request_c072fd:
    jsl f:request_native_menu_audio_0e
    sep #$20
    lda a:$1808
    sta a:$19F1
    jsr encode_native_menu_target_mask_from_selected_actor_or_multi_target_flags
    jsr write_native_menu_cast_record_single_or_multiple_actor_targets
    rep #$30
    lda a:$1808
    .a16
    and #$0003
    xba
    asl
    tax
    jsl f:cast_spell_public_jump
    rts
