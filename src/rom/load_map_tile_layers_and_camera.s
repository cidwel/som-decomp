; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_map_trigger_tiles = $D037
fill_map_tile_rows = $CA71
load_map_piece_list = $CB90
routine_01cd17 = $1CD17

first_layer_width_tiles = $9C
second_layer_width_tiles = $A0
second_layer_present = $B9
first_layer_origin = $C8
second_layer_origin = $CA
map_entry_flags = $E8
transition_tile_x = $DE
transition_tile_y_and_half = $DF
vertical_half_tile_state = $BF
first_layer_width_pixels = $C0
first_layer_height_pixels = $C2
second_layer_width_pixels = $C4
second_layer_height_pixels = $C6
first_layer_map_x = $A8
first_layer_map_y = $AA
second_layer_map_x = $AC
second_layer_map_y = $AE
first_layer_aligned_x = $88
first_layer_aligned_y = $8A
second_layer_aligned_x = $8C
second_layer_aligned_y = $8E

.segment "CODE"
.org $C9EA
load_map_tile_layers_and_camera:
    sep #$20
    stz first_layer_width_tiles
    stz second_layer_width_tiles
    stz second_layer_present
    jsr load_map_piece_list
    jsr allocate_map_trigger_tiles
    rep #$20
    sep #$10
    .a16
    lda #$0000
    sta first_layer_origin
    .a16
    lda #$4000
    sta second_layer_origin
    ldx map_entry_flags
    bpl transition_camera
    jsl f:routine_01cd17
    bra fill_map_tile_rows
transition_camera:
    lda transition_tile_x
    .a16
    and #$007F
    asl
    asl
    asl
    asl
    sec
    .a16
    sbc #$0078
    bpl load_map_tile_layers_and_camera_c0ca21
    adc first_layer_width_pixels
load_map_tile_layers_and_camera_c0ca21:
    sta first_layer_map_x
    pha
    .a16
    and #$FFF0
    sta first_layer_aligned_x
    pla
    ldx second_layer_present
    beq load_map_tile_layers_and_camera_c0ca3d
wrap_second_layer_x:
    cmp second_layer_width_pixels
    bcc load_map_tile_layers_and_camera_c0ca36
    sbc second_layer_width_pixels
    bra wrap_second_layer_x
load_map_tile_layers_and_camera_c0ca36:
    sta second_layer_map_x
    .a16
    and #$FFF0
    sta second_layer_aligned_x
load_map_tile_layers_and_camera_c0ca3d:
    sep #$20
    lda transition_tile_y_and_half
    lsr
    ror vertical_half_tile_state
    rep #$20
    .a16
    and #$007F
    asl
    asl
    asl
    asl
    sec
    .a16
    sbc #$0068
    bpl load_map_tile_layers_and_camera_c0ca55
    adc first_layer_height_pixels
load_map_tile_layers_and_camera_c0ca55:
    sta first_layer_map_y
    pha
    .a16
    and #$FFF0
    sta first_layer_aligned_y
    pla
    ldx second_layer_present
    beq fill_map_tile_rows
wrap_second_layer_y:
    cmp second_layer_height_pixels
    bcc load_map_tile_layers_and_camera_c0ca6a
    sbc second_layer_height_pixels
    bra wrap_second_layer_y
load_map_tile_layers_and_camera_c0ca6a:
    sta second_layer_map_y
    .a16
    and #$FFF0
    sta second_layer_aligned_y
