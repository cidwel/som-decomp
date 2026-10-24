; Recovered Secret of Mana USA routine; behaviour documented in docs/map-main-frame.md.
.setcpu "65816"
.smart
.a8
.i16

advance_all_automatic_map_layer_motion = $DB1E
advance_main_frame_menu_transition_and_native_wait = $A462
advance_native_charge_and_partner_follow_frame = $EB06
coordinate_map_screen_requests_doors_and_hero_tile_events = $B4FE
detect_map_scroll_edges_and_prepare_both_layer_tile_buffers = $C59F
dispatch_five_phase_map_actor_animation_combat_and_menu_frame = $B0D3
emit_complete_map_actor_and_hud_sprites = $E38E
finalize_software_oam_hidden_sprite_tail = $BCAB
initialize_software_oam_and_optional_spell_frames = $BCCC
poll_three_controller_words_and_publish_pressed_edges = $93B9
routine_01b033 = $1B033
routine_01bfe0 = $1BFE0
routine_01e8c7 = $1E8C7
routine_02bad6 = $2BAD6
routine_02c786 = $2C786
scan_map_contacts_then_dispatch_hero_and_actor_motion = $D5C0
schedule_three_controller_inputs_and_publish_actor_motion = $B69C
update_complete_map_frame_screen_effects = $8B5E

.segment "CODE"
.org $B08C
advance_complete_main_map_frame_and_finalize_native_oam:
    jsl f:routine_02c786
    sep #$20
    lda $D0
    beq advance_complete_main_map_frame_and_finalize_native_oam_c0b0a0
    lda $56
    .a8
    cmp #$03
    bne advance_complete_main_map_frame_and_finalize_native_oam_c0b0a0
    jsl f:routine_01e8c7
advance_complete_main_map_frame_and_finalize_native_oam_c0b0a0:
    jsr initialize_software_oam_and_optional_spell_frames
    jsr advance_main_frame_menu_transition_and_native_wait
    jsr update_complete_map_frame_screen_effects
    jsr advance_all_automatic_map_layer_motion
    jsr poll_three_controller_words_and_publish_pressed_edges
    jsr schedule_three_controller_inputs_and_publish_actor_motion
    jsr scan_map_contacts_then_dispatch_hero_and_actor_motion
    jsr coordinate_map_screen_requests_doors_and_hero_tile_events
    jsr detect_map_scroll_edges_and_prepare_both_layer_tile_buffers
    jsl f:routine_01b033
    jsl f:routine_01bfe0
    jsl f:routine_02bad6
    jsr advance_native_charge_and_partner_follow_frame
    jsr dispatch_five_phase_map_actor_animation_combat_and_menu_frame
    jsr emit_complete_map_actor_and_hud_sprites
    brl finalize_software_oam_hidden_sprite_tail
