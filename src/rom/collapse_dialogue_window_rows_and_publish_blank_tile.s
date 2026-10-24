; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-window-close.md.
.setcpu "65816"
.smart
.a8
.i16

exchange_dialogue_tilemap_entry_and_request_upload = $1BC0
exchange_dialogue_tilemap_entry_with_zero_tile = $1BBD
request_dialogue_transfer_and_conditional_window_flags = $0FFA
select_dialogue_window_geometry_from_state = $0D8B

.segment "CODE"
.org $06EA
collapse_dialogue_window_rows_and_publish_blank_tile:
    lda a:$A16D
    bne collapse_dialogue_window_rows_and_publish_blank_tile_c00748
    lda a:$A162
    .a8
    cmp #$01
    bne collapse_dialogue_window_rows_and_publish_blank_tile_c00714
    lda f:$001D11
    .a8
    ora #$08
    sta f:$001D11
    lda f:$001D04
    .a8
    ora #$05
    sta f:$001D04
    lda f:$001D12
    .a8
    and #$DF
    sta f:$001D12
collapse_dialogue_window_rows_and_publish_blank_tile_c00714:
    lda f:$001D03
    iny
    phb
    pha
    plb
    lda a:$0000,Y
    plb
    sep #$20
    jsr select_dialogue_window_geometry_from_state
    pha
    .a8
    lda #$01
    sta a:$A16D
    pla
    sta a:$A166
    clc
    adc a:$A164
    sta a:$A168
    xba
    sta a:$A165
    clc
    adc a:$A163
    inc
    sta a:$A167
    inc a:$A16C
    inc a:$A16C
collapse_dialogue_window_rows_and_publish_blank_tile_c00748:
    lda a:$A16C
    sta a:$A164
    lda a:$A166
    sta a:$A157
    lda a:$A165
    sta a:$A156
collapse_dialogue_window_rows_and_publish_blank_tile_c0075a:
    jsr exchange_dialogue_tilemap_entry_with_zero_tile
    inc a:$A156
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    dec a:$A156
    inc a:$A157
    dec a:$A164
    bne collapse_dialogue_window_rows_and_publish_blank_tile_c0075a
    lda a:$A16C
    sta a:$A164
    dec a:$A163
    beq collapse_dialogue_window_rows_and_publish_blank_tile_c007a4
    lda a:$A166
    sta a:$A157
    lda a:$A167
    sta a:$A156
collapse_dialogue_window_rows_and_publish_blank_tile_c00785:
    jsr exchange_dialogue_tilemap_entry_with_zero_tile
    dec a:$A156
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    inc a:$A156
    inc a:$A157
    dec a:$A164
    bne collapse_dialogue_window_rows_and_publish_blank_tile_c00785
    inc a:$A165
    dec a:$A167
    dec a:$A163
    bne collapse_dialogue_window_rows_and_publish_blank_tile_c007df
collapse_dialogue_window_rows_and_publish_blank_tile_c007a4:
    stz a:$9400
    .i16
    ldx #$9400
    .i16
    ldy #$9401
    rep #$20
    .a16
    lda #$001F
    mvn #$7E, #$7E
    .a16
    lda #$00FF
    sta a:$940E
    .i16
    ldx #$4900
    txa
    sta f:$001D06
    .a16
    lda #$0020
    sta f:$001D08
    sep #$20
    .a8
    lda #$07
    jsr request_dialogue_transfer_and_conditional_window_flags
    inc a:$A15E
    lda a:$A16C
    dec
    dec
    sta a:$A164
    inc a:$A168
collapse_dialogue_window_rows_and_publish_blank_tile_c007df:
    rts
