; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-lifecycle.md.
.setcpu "65816"
.smart
.a8
.i16

advance_ui_tile_buffers_and_native_transition_or_sound_requests = $8093
advance_ui_visibility_zoom_state_and_sprite_coordinate_transition = $8272
build_scaled_ui_raster_window_records_and_request_native_publication = $95A0
derive_ui_frame_matrix_and_select_hdma_record_bank = $908B
dispatch_complete_manual_or_automatic_ui_motion_and_publish_focus = $83A8
poll_selected_hero_controller_and_restore_ui_input_word = $87E0
publish_ui_frame_sprites = $9AB8
routine_01fde4 = $1FDE4
routine_c0983a = $983A
update_complete_map_frame_screen_effects = $8B5E

.segment "CODE"
.org $8064
run_ui_frame_iteration_until_real_native_nmi_completion:
run_ui_frame_iteration_until_real_native_nmi_completion_c08064:
    sep #$20
    jsr update_complete_map_frame_screen_effects
    jsr dispatch_complete_manual_or_automatic_ui_motion_and_publish_focus
    jsr routine_c0983a
    jsr derive_ui_frame_matrix_and_select_hdma_record_bank
    jsr build_scaled_ui_raster_window_records_and_request_native_publication
    jsr publish_ui_frame_sprites
    jsl f:routine_01fde4
    jsr poll_selected_hero_controller_and_restore_ui_input_word
    jsr advance_ui_visibility_zoom_state_and_sprite_coordinate_transition
    jsr advance_ui_tile_buffers_and_native_transition_or_sound_requests
    sep #$20
    .a8
    lda #$81
    sta $EC
    .a8
    lda #$01
run_ui_frame_iteration_until_real_native_nmi_completion_c0808d:
    bit $EC
    bne run_ui_frame_iteration_until_real_native_nmi_completion_c0808d
    bra run_ui_frame_iteration_until_real_native_nmi_completion_c08064
