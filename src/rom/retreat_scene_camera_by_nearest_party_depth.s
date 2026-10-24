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
routine_c0c037 = $C037

.segment "CODE"
.org $BFA2
retreat_scene_camera_by_nearest_party_depth:
    sep #$20
    bcs retreat_scene_camera_by_nearest_party_depth_c0c024
    lda f:$7EE022,X
    sta $1F
    lda f:$7EE000
    beq retreat_scene_camera_by_nearest_party_depth_c0bfc4
    bmi retreat_scene_camera_by_nearest_party_depth_c0bfc4
    lda f:$7EE02C
    bne retreat_scene_camera_by_nearest_party_depth_c0bfc4
    lda f:$7EE022
    cmp $1F
    bcs retreat_scene_camera_by_nearest_party_depth_c0bfc4
    sta $1F
retreat_scene_camera_by_nearest_party_depth_c0bfc4:
    lda f:$7EE200
    beq retreat_scene_camera_by_nearest_party_depth_c0bfdc
    bmi retreat_scene_camera_by_nearest_party_depth_c0bfdc
    lda f:$7EE22C
    bne retreat_scene_camera_by_nearest_party_depth_c0bfdc
    lda f:$7EE222
    cmp $1F
    bcs retreat_scene_camera_by_nearest_party_depth_c0bfdc
    sta $1F
retreat_scene_camera_by_nearest_party_depth_c0bfdc:
    lda f:$7EE400
    beq retreat_scene_camera_by_nearest_party_depth_c0bff4
    bmi retreat_scene_camera_by_nearest_party_depth_c0bff4
    lda f:$7EE42C
    bne retreat_scene_camera_by_nearest_party_depth_c0bff4
    lda f:$7EE422
    cmp $1F
    bcs retreat_scene_camera_by_nearest_party_depth_c0bff4
    sta $1F
retreat_scene_camera_by_nearest_party_depth_c0bff4:
    lda $1F
    .a8
    cmp #$64
    bcc retreat_scene_camera_by_nearest_party_depth_c0c000
    .a8
    lda #$00
    sta $1F
    clc
    rts
retreat_scene_camera_by_nearest_party_depth_c0c000:
    .a8
    lda #$64
    sec
    sbc $1F
    .a8
    cmp #$1C
    bcc retreat_scene_camera_by_nearest_party_depth_c0c00b
    .a8
    lda #$1C
retreat_scene_camera_by_nearest_party_depth_c0c00b:
    sta $1F
    .a8
    cmp #$0F
    bcs retreat_scene_camera_by_nearest_party_depth_c0c015
    .a8
    ora #$80
    bra retreat_scene_camera_by_nearest_party_depth_c0c037
retreat_scene_camera_by_nearest_party_depth_c0c015:
    .a8
    lda #$8E
    jsr routine_c0c037
    lda $1F
    sec
    .a8
    sbc #$0E
    .a8
    ora #$80
    brl retreat_scene_camera_by_nearest_party_depth_c0c037
retreat_scene_camera_by_nearest_party_depth_c0c024:
    lda $1F
    bne retreat_scene_camera_by_nearest_party_depth_c0c029
    rts
retreat_scene_camera_by_nearest_party_depth_c0c029:
    .a8
    cmp #$0F
    bcc retreat_scene_camera_by_nearest_party_depth_c0c037
    .a8
    lda #$0E
    jsr routine_c0c037
    lda $1F
    sec
    .a8
    sbc #$0E
retreat_scene_camera_by_nearest_party_depth_c0c037:
    sta $86
    stz $84
    jsr move_scene_camera_entry
    jsr detect_map_scroll_edges_and_prepare_both_layer_tile_buffers
    jsr initialize_software_oam_and_optional_spell_frames
    jsr emit_complete_map_actor_and_hud_sprites
    jsr finalize_software_oam_hidden_sprite_tail
    jsr initialize_software_oam_and_optional_spell_frames
    sep #$20
    .a8
    lda #$01
    sta $EC
retreat_scene_camera_by_nearest_party_depth_c0c053:
    bit $EC
    bne retreat_scene_camera_by_nearest_party_depth_c0c053
    sec
    rts
