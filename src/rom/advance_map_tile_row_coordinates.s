; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


second_layer_present = $B9
first_layer_map_y = $AA
second_layer_map_y = $AE
first_layer_scroll_y = $B2
second_layer_scroll_y = $B6
first_layer_height_pixels = $C2
second_layer_height_pixels = $C6

.segment "CODE"
.org $CAC6
advance_map_tile_row_coordinates:
    sep #$10
    rep #$20
    lda first_layer_map_y
    clc
    .a16
    adc #$0010
    cmp first_layer_height_pixels
    bcc advance_map_tile_row_coordinates_c0cad6
    sbc first_layer_height_pixels
advance_map_tile_row_coordinates_c0cad6:
    sta first_layer_map_y
    lda first_layer_scroll_y
    clc
    .a16
    adc #$0010
    sta first_layer_scroll_y
    sep #$20
    lda second_layer_present
    beq advance_map_tile_row_coordinates_c0cafe
    rep #$20
    lda second_layer_map_y
    clc
    .a16
    adc #$0010
    cmp second_layer_height_pixels
    bcc advance_map_tile_row_coordinates_c0caf4
    sbc second_layer_height_pixels
advance_map_tile_row_coordinates_c0caf4:
    sta second_layer_map_y
    lda second_layer_scroll_y
    clc
    .a16
    adc #$0010
    sta second_layer_scroll_y
advance_map_tile_row_coordinates_c0cafe:
    rts
