; Recovered Secret of Mana USA routine; behaviour documented in docs/map-main-frame.md.
.setcpu "65816"
.smart
.a8
.i16

emit_cast_sprite_workspace = $E32C
initialize_map_sprite_workspace = $E355
retreat_scene_camera_by_nearest_party_depth = $BFA2
routine_01cb38 = $1CB38

.segment "CODE"
.org $BEFC
invoke_full_actor_ring_between_native_camera_and_frame_phases:
    sep #$20
    phx
    phy
    plx
    phx
    lda f:$7EE01C,X
    ora f:$7EE060,X
    beq invoke_full_actor_ring_between_native_camera_and_frame_phases_c0bf0f
    plx
    ply
    rts
invoke_full_actor_ring_between_native_camera_and_frame_phases_c0bf0f:
    stx $D4
    .a8
    lda #$01
    tsb $EC
invoke_full_actor_ring_between_native_camera_and_frame_phases_c0bf15:
    bit $EC
    bne invoke_full_actor_ring_between_native_camera_and_frame_phases_c0bf15
    clc
    jsr retreat_scene_camera_by_nearest_party_depth
    jsr emit_cast_sprite_workspace
    rep #$10
    ply
    plx
    jsl f:routine_01cb38
    jsr initialize_map_sprite_workspace
    sep #$20
    .a8
    lda #$04
    bit $E8
    bne invoke_full_actor_ring_between_native_camera_and_frame_phases_c0bf37
    sec
    brl retreat_scene_camera_by_nearest_party_depth
invoke_full_actor_ring_between_native_camera_and_frame_phases_c0bf37:
    rts
