; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0439
upload_boss_mode7_matrix_and_tile_rows:
    ldx a:$02CD
    stx a:$211B
    ldx a:$02CE
    stx a:$211B
    ldx a:$02CF
    stx a:$211C
    ldx a:$02D0
    stx a:$211C
    ldx a:$02D1
    stx a:$211D
    ldx a:$02D2
    stx a:$211D
    ldx a:$02D3
    stx a:$211E
    ldx a:$02D4
    stx a:$211E
    ldx a:$02D5
    stx a:$211F
    ldx a:$02D6
    stx a:$211F
    ldx a:$02D7
    stx a:$2120
    ldx a:$02D8
    stx a:$2120
    .i8
    ldx #$00
    stx a:$2115
    .i8
    ldx #$18
    stx a:$4371
    .i8
    ldy #$00
upload_boss_mode7_matrix_and_tile_rows_c2048d:
    .a16
    lda #$0020
    sta a:$4375
    tya
    xba
    lsr
    sta a:$0FAE
    sta a:$2116
    .i8
    ldx #$00
    stx a:$4370
    .i8
    ldx #$7F
    stx a:$4374
    lda a:$0FAE
    lsr
    clc
    .a16
    adc #$BC00
    sta a:$4372
    .i8
    ldx #$80
    stx a:$420B
    iny
    .i8
    cpy #$10
    bne upload_boss_mode7_matrix_and_tile_rows_c2048d
    .i8
    ldx #$80
    stx a:$2115
    rts
