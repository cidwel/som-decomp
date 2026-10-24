; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

tile_edge_offset = $00
remaining_cells = $04
tile_map_pointer = $10
second_layer_origin = $CA
second_layer_map_x = $AC
second_layer_map_y = $AE
second_layer_scroll_x = $B4
second_layer_scroll_y = $B6
second_layer_height_pixels = $C6
second_layer_width_tiles = $A0
second_row_vram_address = $A4
second_row_vram_page = $A5
second_row_left_count = $6E
second_row_right_count = $6F
second_layer_tile_top_left = $C800
second_layer_tile_top_right = $C802
second_layer_tile_bottom_left = $C804
second_layer_tile_bottom_right = $C806
second_row_top_buffer = $D100
second_row_bottom_buffer = $D144

.segment "CODE"
.org $D0C2
build_second_layer_tile_row:
    sep #$10
    rep #$20
    lda second_layer_map_y
    clc
    adc tile_edge_offset
    cmp second_layer_height_pixels
    bcc build_second_layer_tile_row_c0d0d1
    sbc second_layer_height_pixels
build_second_layer_tile_row_c0d0d1:
    .a16
    and #$07F0
    asl
    asl
    asl
    adc second_layer_origin
    sta tile_map_pointer
    lda second_layer_map_x
    lsr
    lsr
    lsr
    lsr
    sep #$20
    sta remaining_cells
    rep #$20
    lda tile_edge_offset
    clc
    adc second_layer_scroll_y
    .a16
    and #$00F0
    asl
    asl
    .a16
    ora #$3800
    sta second_row_vram_address
    lda second_layer_scroll_x
    sep #$30
    lsr
    lsr
    lsr
    .a8
    and #$1E
    pha
    ora second_row_vram_address
    sta second_row_vram_address
    pla
    asl
    .a8
    adc #$04
    sta second_row_right_count
    sec
    .a8
    sbc #$04
    .a8
    eor #$3F
    inc
    sta second_row_left_count
    xba
    beq build_second_layer_tile_row_c0d119
    .a8
    lda #$04
    tsb second_row_vram_page
build_second_layer_tile_row_c0d119:
    .i8
    ldx #$00
build_second_layer_tile_row_c0d11b:
    sep #$30
    ldy remaining_cells
    tya
    inc
    sta remaining_cells
    cmp second_layer_width_tiles
    bcc build_second_layer_tile_row_c0d12b
    sbc second_layer_width_tiles
    sta remaining_cells
build_second_layer_tile_row_c0d12b:
    lda ($10),Y
    rep #$30
    .a16
    and #$00FF
    asl
    asl
    asl
    tay
    lda a:second_layer_tile_top_left,Y
    sta a:second_row_top_buffer,X
    lda a:second_layer_tile_bottom_left,Y
    sta a:second_row_bottom_buffer,X
    inx
    inx
    lda a:second_layer_tile_top_right,Y
    sta a:second_row_top_buffer,X
    lda a:second_layer_tile_bottom_right,Y
    sta a:second_row_bottom_buffer,X
    inx
    inx
    .i16
    cpx #$0044
    bcc build_second_layer_tile_row_c0d11b
    rts
