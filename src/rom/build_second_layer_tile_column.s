; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

tile_edge_offset = $00
remaining_cells = $04
tile_map_pointer = $10
wrapped_column = $1A
second_layer_origin = $CA
second_layer_map_x = $AC
second_layer_map_y = $AE
second_layer_scroll_x = $B4
second_layer_scroll_y = $B6
second_layer_width_pixels = $C4
second_layer_height_pixels = $C6
second_column_vram_address = $A6
second_column_vram_page = $A7
second_layer_tile_top_left = $C800
second_layer_tile_top_right = $C802
second_layer_tile_bottom_left = $C804
second_layer_tile_bottom_right = $C806
second_column_left_buffer = $D280
second_column_right_buffer = $D2C0

.segment "CODE"
.org $D158
build_second_layer_tile_column:
    sep #$30
    rep #$20
    lda second_layer_map_y
    .a16
    and #$07F0
    sta remaining_cells
    asl
    asl
    asl
    adc second_layer_origin
    sta tile_map_pointer
    lda second_layer_height_pixels
    sec
    sbc remaining_cells
    lsr
    lsr
    lsr
    lsr
    sta remaining_cells
    lda second_layer_map_x
    clc
    adc tile_edge_offset
    cmp second_layer_width_pixels
    bcc build_second_layer_tile_column_c0d180
    sbc second_layer_width_pixels
build_second_layer_tile_column_c0d180:
    lsr
    lsr
    lsr
    lsr
    sta wrapped_column
    sep #$20
    ora tile_map_pointer
    sta tile_map_pointer
    rep #$20
    lda second_layer_scroll_x
    clc
    adc tile_edge_offset
    sep #$20
    lsr
    lsr
    lsr
    .a8
    and #$1E
    sta second_column_vram_address
    xba
    lsr
    .a8
    lda #$38
    bcc build_second_layer_tile_column_c0d1a4
    .a8
    lda #$3C
build_second_layer_tile_column_c0d1a4:
    sta second_column_vram_page
    .a8
    lda #$10
    sta tile_edge_offset
    stz $01
    lda second_layer_scroll_y
    lsr
    lsr
    .a8
    and #$FC
    tax
    rep #$30
build_second_layer_tile_column_c0d1b5:
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
    bne build_second_layer_tile_column_c0d1d0
    lda second_layer_origin
    ora wrapped_column
    sta tile_map_pointer
build_second_layer_tile_column_c0d1d0:
    lda a:second_layer_tile_top_left,Y
    sta a:second_column_left_buffer,X
    lda a:second_layer_tile_top_right,Y
    sta a:second_column_right_buffer,X
    inx
    inx
    lda a:second_layer_tile_bottom_left,Y
    sta a:second_column_left_buffer,X
    lda a:second_layer_tile_bottom_right,Y
    sta a:second_column_right_buffer,X
    inx
    inx
    .i16
    cpx #$0040
    bcc build_second_layer_tile_column_c0d1f4
    .i16
    ldx #$0000
build_second_layer_tile_column_c0d1f4:
    dec tile_edge_offset
    bne build_second_layer_tile_column_c0d1b5
    rts
