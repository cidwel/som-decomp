; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i8

build_first_layer_tile_column = $C945
build_second_layer_tile_column = $D158
pending_column_return = $C8F9

pending_column_flags = $2F
tile_edge_offset = $00

.segment "CODE"
.org $C908
select_pending_map_column_edges:
    .a8
    and #$03
    beq select_pending_map_column_edges_c0c923
    .a8
    cmp #$02
    rep #$20
    .a16
    lda #$0000
    bcs select_pending_map_column_edges_c0c918
    .a16
    lda #$0100
select_pending_map_column_edges_c0c918:
    sta tile_edge_offset
    jsr build_first_layer_tile_column
    sep #$20
    .a8
    lda #$80
    tsb pending_column_flags
select_pending_map_column_edges_c0c923:
    sep #$30
    lda pending_column_flags
    lsr
    lsr
    .a8
    and #$03
    beq pending_column_return
    .a8
    cmp #$02
    rep #$20
    .a16
    lda #$0000
    bcs select_pending_map_column_edges_c0c939
    .a16
    lda #$0100
select_pending_map_column_edges_c0c939:
    sta tile_edge_offset
    jsr build_second_layer_tile_column
    sep #$20
    .a8
    lda #$40
    tsb pending_column_flags
    rts
