; Recovered Secret of Mana USA routine; behaviour documented in docs/map-scroll-edge-planning.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_pending_map_columns = $C8EF
prepare_pending_map_rows = $C7C3

.segment "CODE"
.org $C59F
detect_map_scroll_edges_and_prepare_both_layer_tile_buffers:
    sep #$10
    rep #$20
    .i8
    ldx #$00
    txy
    lda $88
    bne detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c5ba
    lda $A8
    .a16
    and #$FFF0
    beq detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c5d6
    sta $88
    .a16
    cmp #$0010
    beq detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c5d5
    bne detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c5d4
detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c5ba:
    lda $A8
    .a16
    and #$FFF0
    bne detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c5cc
    lda $88
    stz $88
    .a16
    cmp #$0010
    beq detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c5d4
    bne detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c5d5
detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c5cc:
    cmp $88
    beq detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c5d6
    sta $88
    bpl detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c5d5
detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c5d4:
    inx
detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c5d5:
    inx
detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c5d6:
    lda $8A
    bne detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c5ea
    lda $AA
    .a16
    and #$FFF0
    beq detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c606
    sta $8A
    .a16
    cmp #$0010
    beq detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c605
    bne detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c604
detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c5ea:
    lda $AA
    .a16
    and #$FFF0
    bne detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c5fc
    lda $8A
    stz $8A
    .a16
    cmp #$0010
    beq detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c604
    bne detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c605
detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c5fc:
    cmp $8A
    beq detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c606
    sta $8A
    bpl detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c605
detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c604:
    iny
detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c605:
    iny
detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c606:
    stx $2F
    sty $2E
    ldx $B9
    beq detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c68c
    .i8
    ldx #$00
    txy
    lda $8C
    bne detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c625
    lda $AC
    .a16
    and #$FFF0
    beq detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c641
    sta $8C
    .a16
    cmp #$0010
    beq detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c640
    bne detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c63f
detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c625:
    lda $AC
    .a16
    and #$FFF0
    bne detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c637
    lda $8C
    stz $8C
    .a16
    cmp #$0010
    beq detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c63f
    bne detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c640
detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c637:
    cmp $8C
    beq detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c641
    sta $8C
    bpl detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c640
detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c63f:
    inx
detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c640:
    inx
detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c641:
    lda $8E
    bne detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c655
    lda $AE
    .a16
    and #$FFF0
    beq detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c671
    sta $8E
    .a16
    cmp #$0010
    beq detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c670
    bne detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c66f
detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c655:
    lda $AE
    .a16
    and #$FFF0
    bne detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c667
    lda $8E
    stz $8E
    .a16
    cmp #$0010
    beq detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c66f
    bne detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c670
detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c667:
    cmp $8E
    beq detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c671
    sta $8E
    bpl detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c670
detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c66f:
    iny
detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c670:
    iny
detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c671:
    sep #$20
    lda $29
    .a8
    bit #$04
    beq detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c67e
    stz $2F
    stz $2E
    rts
detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c67e:
    txa
    asl
    asl
    ora $2F
    sta $2F
    tya
    asl
    asl
    ora $2E
    sta $2E
detect_map_scroll_edges_and_prepare_both_layer_tile_buffers_c0c68c:
    jsr prepare_pending_map_rows
    jmp prepare_pending_map_columns
