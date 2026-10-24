; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

advance_map_tile_row_coordinates = $CAC6
prepare_pending_map_rows = $C7C3
upload_pending_map_tile_rows_and_columns = $C692

pending_row_flags = $2E
pending_column_flags = $2F
second_layer_present = $B9
first_layer_map_x = $A8
first_layer_map_y = $AA
second_layer_map_x = $AC
second_layer_map_y = $AE
first_layer_scroll_x = $B0
first_layer_scroll_y = $B2
second_layer_scroll_x = $B4
second_layer_scroll_y = $B6

.segment "CODE"
.org $CA71
fill_map_tile_rows:
    rep #$20
    sep #$10
    lda first_layer_map_x
    .a16
    and #$000F
    sta first_layer_scroll_x
    lda second_layer_map_x
    .a16
    and #$000F
    sta second_layer_scroll_x
    lda first_layer_map_y
    pha
    .a16
    and #$000F
    sta first_layer_scroll_y
    pha
    lda second_layer_map_y
    pha
    .a16
    and #$000F
    sta second_layer_scroll_y
    pha
    .i8
    ldx #$10
fill_map_tile_rows_c0ca97:
    phx
    .i8
    ldx #$02
    ldy second_layer_present
    beq fill_map_tile_rows_c0caa0
    .i8
    ldx #$0A
fill_map_tile_rows_c0caa0:
    stx pending_row_flags
    .i8
    ldx #$00
    stx pending_column_flags
    jsr prepare_pending_map_rows
    jsr upload_pending_map_tile_rows_and_columns
    jsr advance_map_tile_row_coordinates
    sep #$10
    plx
    dex
    bne fill_map_tile_rows_c0ca97
    rep #$20
    sep #$10
    pla
    sta second_layer_scroll_y
    pla
    sta second_layer_map_y
    pla
    sta first_layer_scroll_y
    pla
    sta first_layer_map_y
    rts
