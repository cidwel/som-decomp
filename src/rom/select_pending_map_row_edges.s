; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i8

build_first_layer_tile_row = $C859
build_second_layer_tile_row = $D0C2
pending_row_return = $C7CD

pending_row_flags = $2E
tile_edge_offset = $00

.segment "CODE"
.org $C7E3
select_pending_map_row_edges:
    .a8
    and #$03
    beq select_pending_map_row_edges_c0c7fe
    .a8
    cmp #$02
    rep #$20
    .a16
    lda #$0000
    bcs select_pending_map_row_edges_c0c7f3
    .a16
    lda #$00F0
select_pending_map_row_edges_c0c7f3:
    sta tile_edge_offset
    jsr build_first_layer_tile_row
    sep #$20
    .a8
    lda #$80
    tsb pending_row_flags
select_pending_map_row_edges_c0c7fe:
    sep #$30
    lda pending_row_flags
    lsr
    lsr
    .a8
    and #$03
    beq pending_row_return
    .a8
    cmp #$02
    rep #$20
    .a16
    lda #$0000
    bcs select_pending_map_row_edges_c0c814
    .a16
    lda #$00F0
select_pending_map_row_edges_c0c814:
    sta tile_edge_offset
    jsr build_second_layer_tile_row
    sep #$20
    .a8
    lda #$40
    tsb pending_row_flags
    rts
