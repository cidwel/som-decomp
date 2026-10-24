; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

dma7_count_high = $4376
dma7_source_bank = $4374
dma7_mode_and_port = $4370
vram_increment_mode = $2115
dma7_source_address = $4372
vram_word_address = $2116
dma7_count_low = $4375
dma_enable = $420B
pending_column_flags = $2F
pending_row_flags = $2E
first_column_address = $78
second_column_address = $A6
first_row_address = $76
second_row_address = $A4
first_row_left_count = $6C
first_row_right_count = $6D
second_row_left_count = $6E
second_row_right_count = $6F

.segment "CODE"
.org $C692
upload_pending_map_tile_rows_and_columns:
    sep #$20
    rep #$10
    stz a:dma7_count_high
    .a8
    lda #$7F
    sta a:dma7_source_bank
    .i16
    ldx #$1801
    stx a:dma7_mode_and_port
    .a8
    lda #$81
    sta a:vram_increment_mode
    lda pending_column_flags
    bpl second_column
    .i16
    ldx #$D200
    stx a:dma7_source_address
    ldx first_column_address
    stx a:vram_word_address
    .a8
    lda #$40
    sta a:dma7_count_low
    .a8
    lda #$80
    sta a:dma_enable
    ldx first_column_address
    inx
    stx a:vram_word_address
    .a8
    lda #$40
    sta a:dma7_count_low
    .a8
    lda #$80
    sta a:dma_enable
second_column:
    bit pending_column_flags
    bvc rows
    .i16
    ldx #$D280
    stx a:dma7_source_address
    ldx second_column_address
    stx a:vram_word_address
    .a8
    lda #$40
    sta a:dma7_count_low
    .a8
    lda #$80
    sta a:dma_enable
    ldx second_column_address
    inx
    stx a:vram_word_address
    .a8
    lda #$40
    sta a:dma7_count_low
    .a8
    lda #$80
    sta a:dma_enable
rows:
    stz pending_column_flags
    .a8
    lda #$80
    sta a:vram_increment_mode
    lda pending_row_flags
    bpl second_row
    .i16
    ldx #$D000
    stx a:dma7_source_address
    ldx first_row_address
    stx a:vram_word_address
    lda first_row_left_count
    sta a:dma7_count_low
    .a8
    lda #$80
    sta a:dma_enable
    rep #$20
    lda first_row_address
    .a16
    ora #$0020
    sta first_row_address
    .a16
    eor #$0420
    .a16
    and #$FFE0
    sta a:vram_word_address
    sep #$20
    lda first_row_right_count
    sta a:dma7_count_low
    .a8
    lda #$80
    sta a:dma_enable
    ldx first_row_address
    stx a:vram_word_address
    lda first_row_left_count
    sta a:dma7_count_low
    .a8
    lda #$80
    sta a:dma_enable
    lda first_row_right_count
    sta a:dma7_count_low
    rep #$20
    lda first_row_address
    .a16
    eor #$0400
    .a16
    and #$FFE0
    sta a:vram_word_address
    sep #$20
    .a8
    lda #$80
    sta a:dma_enable
second_row:
    bit pending_row_flags
    bvc clear_row_flags
    .i16
    ldx #$D100
    stx a:dma7_source_address
    ldx second_row_address
    stx a:vram_word_address
    lda second_row_left_count
    sta a:dma7_count_low
    .a8
    lda #$80
    sta a:dma_enable
    rep #$20
    lda second_row_address
    .a16
    ora #$0020
    sta second_row_address
    .a16
    eor #$0420
    .a16
    and #$FFE0
    sta a:vram_word_address
    sep #$20
    lda second_row_right_count
    sta a:dma7_count_low
    .a8
    lda #$80
    sta a:dma_enable
    ldx second_row_address
    stx a:vram_word_address
    lda second_row_left_count
    sta a:dma7_count_low
    .a8
    lda #$80
    sta a:dma_enable
    lda second_row_right_count
    sta a:dma7_count_low
    rep #$20
    lda second_row_address
    .a16
    eor #$0400
    .a16
    and #$FFE0
    sta a:vram_word_address
    sep #$20
    .a8
    lda #$80
    sta a:dma_enable
clear_row_flags:
    stz pending_row_flags
    rts
