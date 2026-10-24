; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

draw_boss_frame_random_number = $300B
upload_boss_mode7_matrix_and_tile_rows = $0439
upload_boss_sixteen_tile_rows = $03D1

.segment "CODE"
.org $0266
upload_complete_boss_frame:
    php
    phd
    phb
    rep #$20
    sep #$10
    .a16
    lda #$0200
    tcd
    .i8
    ldx #$00
    phx
    plb
    ldx $CA
    beq upload_complete_boss_frame_c202cb
    .i8
    ldx #$01
    stx a:$4360
    stx a:$4370
    .i8
    ldx #$18
    stx a:$4361
    stx a:$4371
    .i8
    ldx #$7F
    stx a:$4364
    stx a:$4374
    .i8
    ldy #$00
upload_complete_boss_frame_c20293:
    tya
    asl
    asl
    tax
    .a16
    lda #$0040
    sta a:$4365
    sta a:$4375
    lda f:$7E0E7D,X
    sta a:$4362
    clc
    .a16
    adc #$0200
    sta a:$4372
    lda f:$7E0E7F,X
    sta a:$2116
    .i8
    ldx #$40
    stx a:$420B
    clc
    .a16
    adc #$0100
    sta a:$2116
    .i8
    ldx #$80
    stx a:$420B
    iny
    cpy $CA
    bne upload_complete_boss_frame_c20293
upload_complete_boss_frame_c202cb:
    lda a:$0FAE
    beq upload_complete_boss_frame_c202ef
    .a16
    bit #$0002
    bne upload_complete_boss_frame_c202e9
    lda a:$0FBE
    clc
    .a16
    adc #$0120
    bmi upload_complete_boss_frame_c202ec
    sec
    .a16
    sbc #$01C0
    bpl upload_complete_boss_frame_c202ec
    jsr upload_boss_sixteen_tile_rows
    bra upload_complete_boss_frame_c202ec
upload_complete_boss_frame_c202e9:
    jsr upload_boss_mode7_matrix_and_tile_rows
upload_complete_boss_frame_c202ec:
    stz a:$0FAE
upload_complete_boss_frame_c202ef:
    ldx a:$0352
    beq upload_complete_boss_frame_c2031f
    .i8
    ldx #$00
    stx a:$4370
    .i8
    ldx #$19
    stx a:$4371
    .i8
    ldx #$7F
    stx a:$4374
    .a16
    lda #$0800
    sta a:$4375
    lda a:$0353
    sta a:$4372
    lda a:$0355
    sta a:$2116
    .i8
    ldx #$80
    stx a:$420B
    .i8
    ldx #$00
    stx a:$0352
upload_complete_boss_frame_c2031f:
    ldx a:$0351
    beq upload_complete_boss_frame_c20357
    lda a:$1D04
    .a16
    bit #$0040
    bne upload_complete_boss_frame_c20357
    .i8
    ldx #$01
    stx a:$4370
    .i8
    ldx #$18
    stx a:$4371
    .i8
    ldx #$7F
    stx a:$4374
    .a16
    lda #$0800
    sta a:$4375
    .a16
    lda #$6000
    sta a:$4372
    .a16
    lda #$6200
    sta a:$2116
    .i8
    ldx #$80
    stx a:$420B
    .i8
    ldx #$00
    stx a:$0351
upload_complete_boss_frame_c20357:
    .i8
    ldx #$01
    stx a:$4370
    jsr draw_boss_frame_random_number
    plb
    pld
    plp
    rtl
