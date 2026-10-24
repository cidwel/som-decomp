; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

tile_edge_offset = $00
remaining_cells = $04
tile_map_pointer = $10
first_layer_origin = $C8
first_layer_map_x = $A8
first_layer_map_y = $AA
first_layer_scroll_x = $B0
first_layer_scroll_y = $B2
first_layer_height_pixels = $C2
first_layer_width_tiles = $9C
first_row_vram_address = $76
first_row_vram_page = $77
first_row_left_count = $6C
first_row_right_count = $6D
first_layer_tile_top_left = $C000
first_layer_tile_top_right = $C002
first_layer_tile_bottom_left = $C004
first_layer_tile_bottom_right = $C006
first_row_top_buffer = $D000
first_row_bottom_buffer = $D044

.segment "CODE"
.org $C859
build_first_layer_tile_row:
    sep #$10
    rep #$20
    lda first_layer_map_y
    clc
    adc tile_edge_offset
    cmp first_layer_height_pixels
    bcc build_first_layer_tile_row_c0c868
    sbc first_layer_height_pixels
build_first_layer_tile_row_c0c868:
    .a16
    and #$07F0
    asl
    asl
    asl
    adc first_layer_origin
    sta tile_map_pointer
    lda first_layer_map_x
    lsr
    lsr
    lsr
    lsr
    sep #$20
    sta remaining_cells
    rep #$20
    lda tile_edge_offset
    clc
    adc first_layer_scroll_y
    .a16
    and #$00F0
    asl
    asl
    .a16
    ora #$5000
    sta first_row_vram_address
    lda first_layer_scroll_x
    sep #$30
    lsr
    lsr
    lsr
    .a8
    and #$1E
    pha
    ora first_row_vram_address
    sta first_row_vram_address
    pla
    asl
    .a8
    adc #$04
    sta first_row_right_count
    sec
    .a8
    sbc #$04
    .a8
    eor #$3F
    inc
    sta first_row_left_count
    xba
    beq build_first_layer_tile_row_c0c8b0
    .a8
    lda #$04
    tsb first_row_vram_page
build_first_layer_tile_row_c0c8b0:
    .i8
    ldx #$00
build_first_layer_tile_row_c0c8b2:
    sep #$30
    ldy remaining_cells
    tya
    inc
    sta remaining_cells
    cmp first_layer_width_tiles
    bcc build_first_layer_tile_row_c0c8c2
    sbc first_layer_width_tiles
    sta remaining_cells
build_first_layer_tile_row_c0c8c2:
    lda ($10),Y
    rep #$30
    .a16
    and #$00FF
    asl
    asl
    asl
    tay
    lda a:first_layer_tile_top_left,Y
    sta a:first_row_top_buffer,X
    lda a:first_layer_tile_bottom_left,Y
    sta a:first_row_bottom_buffer,X
    inx
    inx
    lda a:first_layer_tile_top_right,Y
    sta a:first_row_top_buffer,X
    lda a:first_layer_tile_bottom_right,Y
    sta a:first_row_bottom_buffer,X
    inx
    inx
    .i16
    cpx #$0044
    bcc build_first_layer_tile_row_c0c8b2
    rts
