; Recovered Secret of Mana USA routine; behaviour documented in docs/map-camera-transition.md.
.setcpu "65816"
.smart
.a8
.i16

detect_map_scroll_edges_and_prepare_both_layer_tile_buffers = $C59F
emit_complete_map_actor_and_hud_sprites = $E38E
finalize_software_oam_hidden_sprite_tail = $BCAB
initialize_software_oam_and_optional_spell_frames = $BCCC
move_scene_camera_entry = $D1F9
routine_01fd37 = $1FD37

.segment "CODE"
.org $C059
slide_special_scene_camera_across_128_real_frames:
    sep #$20
    lda a:$010F
    .a8
    eor #$80
    bne slide_special_scene_camera_across_128_real_frames_c0c069
    lda a:$010E
    .a8
    cmp #$FF
    beq slide_special_scene_camera_across_128_real_frames_c0c06a
slide_special_scene_camera_across_128_real_frames_c0c069:
    rts
slide_special_scene_camera_across_128_real_frames_c0c06a:
    jsl f:routine_01fd37
    sep #$20
    .a8
    lda #$80
    sta $1F
slide_special_scene_camera_across_128_real_frames_c0c074:
    .a8
    lda #$88
    sta $84
    stz $86
    jsr move_scene_camera_entry
    jsr detect_map_scroll_edges_and_prepare_both_layer_tile_buffers
    jsr initialize_software_oam_and_optional_spell_frames
    jsr emit_complete_map_actor_and_hud_sprites
    jsr finalize_software_oam_hidden_sprite_tail
    sep #$20
    .a8
    lda #$08
    sta f:$7EE00F
    sta f:$7EE20F
    sta f:$7EE40F
    .a8
    lda #$01
    sta $EC
slide_special_scene_camera_across_128_real_frames_c0c09d:
    bit $EC
    bne slide_special_scene_camera_across_128_real_frames_c0c09d
    dec $1F
    bne slide_special_scene_camera_across_128_real_frames_c0c074
    sep #$30
    rts
