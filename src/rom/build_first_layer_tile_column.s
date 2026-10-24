; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

tile_edge_offset = $00
remaining_cells = $04
tile_map_pointer = $10
wrapped_column = $1A
first_layer_origin = $C8
first_layer_map_x = $A8
first_layer_map_y = $AA
first_layer_scroll_x = $B0
first_layer_scroll_y = $B2
first_layer_width_pixels = $C0
first_layer_height_pixels = $C2
first_column_vram_address = $78
first_column_vram_page = $79
first_layer_tile_top_left = $C000
first_layer_tile_top_right = $C002
first_layer_tile_bottom_left = $C004
first_layer_tile_bottom_right = $C006
first_column_left_buffer = $D200
first_column_right_buffer = $D240

.segment "CODE"
.org $C945
build_first_layer_tile_column:
    sep #$30
    rep #$20
    lda first_layer_map_y
    .a16
    and #$07F0
    sta remaining_cells
    asl
    asl
    asl
    adc first_layer_origin
    sta tile_map_pointer
    lda first_layer_height_pixels
    sec
    sbc remaining_cells
    lsr
    lsr
    lsr
    lsr
    sta remaining_cells
    lda first_layer_map_x
    clc
    adc tile_edge_offset
    cmp first_layer_width_pixels
    bcc build_first_layer_tile_column_c0c96d
    sbc first_layer_width_pixels
build_first_layer_tile_column_c0c96d:
    lsr
    lsr
    lsr
    lsr
    sta wrapped_column
    sep #$20
    ora tile_map_pointer
    sta tile_map_pointer
    rep #$20
    lda first_layer_scroll_x
    clc
    adc tile_edge_offset
    sep #$20
    lsr
    lsr
    lsr
    .a8
    and #$1E
    sta first_column_vram_address
    xba
    lsr
    .a8
    lda #$50
    bcc build_first_layer_tile_column_c0c991
    .a8
    lda #$54
build_first_layer_tile_column_c0c991:
    sta first_column_vram_page
    .a8
    lda #$10
    sta tile_edge_offset
    stz $01
    lda first_layer_scroll_y
    lsr
    lsr
    .a8
    and #$FC
    tax
    rep #$30
build_first_layer_tile_column_c0c9a2:
    lda ($10)
    .a16
    and #$00FF
    asl
    asl
    asl
    tay
    lda tile_map_pointer
    clc
    .a16
    adc #$0080
    sta tile_map_pointer
    dec remaining_cells
    bne build_first_layer_tile_column_c0c9bd
    lda first_layer_origin
    ora wrapped_column
    sta tile_map_pointer
build_first_layer_tile_column_c0c9bd:
    lda a:first_layer_tile_top_left,Y
    sta a:first_column_left_buffer,X
    lda a:first_layer_tile_top_right,Y
    sta a:first_column_right_buffer,X
    inx
    inx
    lda a:first_layer_tile_bottom_left,Y
    sta a:first_column_left_buffer,X
    lda a:first_layer_tile_bottom_right,Y
    sta a:first_column_right_buffer,X
    inx
    inx
    .i16
    cpx #$0040
    bcc build_first_layer_tile_column_c0c9e1
    .i16
    ldx #$0000
build_first_layer_tile_column_c0c9e1:
    dec tile_edge_offset
    bne build_first_layer_tile_column_c0c9a2
    rts
