; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $03D1
upload_boss_sixteen_tile_rows:
    .i8
    ldx #$18
    stx a:$4371
    .i8
    ldy #$00
upload_boss_sixteen_tile_rows_c203d8:
    .a16
    lda #$0040
    sta a:$4375
    tya
    asl
    asl
    asl
    asl
    asl
    sta a:$0FAE
    clc
    .a16
    adc #$3800
    sta a:$2116
    lda a:$0FBC
    clc
    .a16
    adc #$0010
    bmi upload_boss_sixteen_tile_rows_c20414
    sec
    .a16
    sbc #$0100
    bpl upload_boss_sixteen_tile_rows_c20414
    .i8
    ldx #$01
    stx a:$4370
    .i8
    ldx #$7F
    stx a:$4374
    lda a:$0FAE
    asl
    clc
    .a16
    adc #$BC00
    sta a:$4372
    bra upload_boss_sixteen_tile_rows_c20424
upload_boss_sixteen_tile_rows_c20414:
    .i8
    ldx #$01
    stx a:$4370
    .i8
    ldx #$C2
    stx a:$4374
    .a16
    lda #$04C1
    sta a:$4372
upload_boss_sixteen_tile_rows_c20424:
    .i8
    ldx #$80
    stx a:$420B
    lda a:$0FBC
    clc
    .a16
    adc #$0008
    sta a:$0FBC
    iny
    .i8
    cpy #$10
    bne upload_boss_sixteen_tile_rows_c203d8
    rts
