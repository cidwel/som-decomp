; Recovered Secret of Mana USA routine; behaviour documented in docs/map-tile-refresh.md.
.setcpu "65816"
.smart
.a8
.i16

advance_map_tile_row_coordinates = $CAC6
prepare_pending_map_rows = $C7C3
upload_pending_map_tile_rows_and_columns = $C692

.segment "CODE"
.org $CB43
refresh_sixteen_map_tile_rows_across_real_frames:
    sep #$10
    rep #$20
    lda $AA
    pha
    lda $B2
    pha
    lda $AE
    pha
    lda $B6
    pha
    .i8
    ldx #$10
refresh_sixteen_map_tile_rows_across_real_frames_c0cb55:
    phx
    .i8
    ldx #$02
    ldy $B9
    beq refresh_sixteen_map_tile_rows_across_real_frames_c0cb5e
    .i8
    ldx #$0A
refresh_sixteen_map_tile_rows_across_real_frames_c0cb5e:
    stx $2E
    .i8
    ldx #$00
    stx $2F
    jsr prepare_pending_map_rows
    sep #$20
    .a8
    lda #$02
    tsb $EC
refresh_sixteen_map_tile_rows_across_real_frames_c0cb6d:
    bit $EC
    bne refresh_sixteen_map_tile_rows_across_real_frames_c0cb6d
    jsr upload_pending_map_tile_rows_and_columns
    jsr advance_map_tile_row_coordinates
    sep #$10
    plx
    dex
    bne refresh_sixteen_map_tile_rows_across_real_frames_c0cb55
    rep #$20
    pla
    sta $B6
    pla
    sta $AE
    pla
    sta $B2
    pla
    sta $AA
    rts
