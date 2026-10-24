; Recovered Secret of Mana USA routine; behaviour documented in docs/map-main-frame.md.
.setcpu "65816"
.smart
.a8
.i16

advance_first_enemy_group_or_first_selected_boss_actor = $FC8C
advance_second_enemy_group_or_second_selected_boss_actor = $FCB5
advance_third_enemy_group_or_third_selected_boss_actor = $FCDE
advance_three_hero_animations_and_primary_geometry = $F4AB
consume_three_controller_menu_edges_and_dispatch_full_ring = $B136
order_map_sprite_actor_groups = $E8D7
publish_secondary_hero_frame_geometry_with_saved_data_bank = $F1AE
release_global_actor_freeze_when_visible_effects_finish = $B102
routine_02c820 = $2C820

.segment "CODE"
.org $B0D3
dispatch_five_phase_map_actor_animation_combat_and_menu_frame:
    sep #$20
    lda $56
    beq dispatch_five_phase_map_actor_animation_combat_and_menu_frame_c0b0f0
    dec
    beq dispatch_five_phase_map_actor_animation_combat_and_menu_frame_c0b0f6
    dec
    beq dispatch_five_phase_map_actor_animation_combat_and_menu_frame_c0b0fc
    dec
    beq dispatch_five_phase_map_actor_animation_combat_and_menu_frame_c0b0ed
    lda $2A
    beq dispatch_five_phase_map_actor_animation_combat_and_menu_frame_c0b0ea
    jsl f:routine_02c820
dispatch_five_phase_map_actor_animation_combat_and_menu_frame_c0b0ea:
    jmp publish_secondary_hero_frame_geometry_with_saved_data_bank
dispatch_five_phase_map_actor_animation_combat_and_menu_frame_c0b0ed:
    jmp advance_three_hero_animations_and_primary_geometry
dispatch_five_phase_map_actor_animation_combat_and_menu_frame_c0b0f0:
    jsr advance_first_enemy_group_or_first_selected_boss_actor
    jmp order_map_sprite_actor_groups
dispatch_five_phase_map_actor_animation_combat_and_menu_frame_c0b0f6:
    jsr release_global_actor_freeze_when_visible_effects_finish
    jmp advance_second_enemy_group_or_second_selected_boss_actor
dispatch_five_phase_map_actor_animation_combat_and_menu_frame_c0b0fc:
    jsr advance_third_enemy_group_or_third_selected_boss_actor
    jmp consume_three_controller_menu_edges_and_dispatch_full_ring
