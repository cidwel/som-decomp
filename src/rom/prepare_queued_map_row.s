; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

build_first_layer_tile_row = $C859
build_second_layer_tile_row = $D0C2

pending_row_flags = $2E
queued_row_flags = $82
queued_row_offset = $83
tile_edge_offset = $00

.segment "CODE"
.org $C820
prepare_queued_map_row:
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    lda queued_row_offset
    .a16
    and #$00FF
    sta tile_edge_offset
    sep #$20
    sec
    .a8
    sbc #$10
    sta queued_row_offset
    bit queued_row_flags
    lda queued_row_flags
    bvc prepare_queued_map_row_c0c841
    .a8
    eor #$40
    sta queued_row_flags
    bra prepare_queued_map_row_c0c843
prepare_queued_map_row_c0c841:
    stz queued_row_flags
prepare_queued_map_row_c0c843:
    bmi prepare_queued_map_row_c0c84e
    .a8
    lda #$80
    sta pending_row_flags
    jsr build_first_layer_tile_row
    bra prepare_queued_map_row_c0c855
prepare_queued_map_row_c0c84e:
    .a8
    lda #$40
    sta pending_row_flags
    jsr build_second_layer_tile_row
prepare_queued_map_row_c0c855:
    sep #$20
    plb
    rts
