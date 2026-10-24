; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $F456
upload_map_graphics_descriptor:
    pha
    sep #$20
    lda [$10],Y
    stz $09
    inc
    sta $08
    bne upload_map_graphics_descriptor_c1f464
    inc $09
upload_map_graphics_descriptor_c1f464:
    stz $04
    xba
    .a8
    and #$E0
    .i16
    ldx #$0000
    .a8
    cmp #$80
    bcs upload_map_graphics_descriptor_c1f484
    pha
    .a8
    and #$40
    beq upload_map_graphics_descriptor_c1f477
    .a8
    lda #$FF
upload_map_graphics_descriptor_c1f477:
    sta $00
    pla
    .a8
    and #$20
    beq upload_map_graphics_descriptor_c1f480
    .a8
    lda #$FF
upload_map_graphics_descriptor_c1f480:
    sta $01
    bra upload_map_graphics_descriptor_c1f49f
upload_map_graphics_descriptor_c1f484:
    .a8
    cmp #$C0
    bcs upload_map_graphics_descriptor_c1f495
    .a8
    and #$20
    beq upload_map_graphics_descriptor_c1f48e
    .a8
    lda #$FF
upload_map_graphics_descriptor_c1f48e:
    sta $00
    .i16
    ldx #$0003
    bra upload_map_graphics_descriptor_c1f49f
upload_map_graphics_descriptor_c1f495:
    bne upload_map_graphics_descriptor_c1f49c
    .i16
    ldx #$0006
    bra upload_map_graphics_descriptor_c1f49f
upload_map_graphics_descriptor_c1f49c:
    .i16
    ldx #$0009
upload_map_graphics_descriptor_c1f49f:
    rep #$20
    pla
    .a16
    and #$1FFF
    .i16
    cpx #$0009
    bne upload_map_graphics_descriptor_c1f510
    stz $03
    lsr
    ror $03
    lsr
    ror $03
    sta $05
    lda $08
    asl
upload_map_graphics_descriptor_c1f4b7:
    asl
    asl
    asl
    asl
    asl
    sta a:$4375
    lda f:$CCE270,X
    clc
    adc $04
    sta a:$4372
    sep #$20
    lda f:$CCE272,X
    .a8
    ora #$C0
    adc $06
    sta a:$4374
    rep #$20
    lda a:$4372
    clc
    adc a:$4375
    bcc upload_map_graphics_descriptor_c1f508
    beq upload_map_graphics_descriptor_c1f508
    pha
    sep #$20
    lda a:$4374
    pha
    rep #$20
    lda a:$4372
    .a16
    eor #$FFFF
    inc
    sta a:$4375
    sep #$20
    .a8
    lda #$80
    sta a:$420B
    pla
    inc
    sta a:$4374
    rep #$20
    pla
    sta a:$4375
upload_map_graphics_descriptor_c1f508:
    sep #$20
    .a8
    lda #$80
    sta a:$420B
    rts
upload_map_graphics_descriptor_c1f510:
    .i16
    cpx #$0006
    bne upload_map_graphics_descriptor_c1f526
    stz $03
    lsr
    ror $03
    lsr
    ror $03
    lsr
    ror $03
    sta $05
    lda $08
    bra upload_map_graphics_descriptor_c1f4b7
upload_map_graphics_descriptor_c1f526:
    .i16
    cpx #$0000
    bne upload_map_graphics_descriptor_c1f56c
    asl
    asl
    asl
    asl
    php
    clc
    adc f:$CCE270,X
    stz $04
    tay
    plp
    sep #$20
    lda f:$CCE272,X
    .a8
    ora #$C0
    .a8
    adc #$00
    sta $06
    rep #$30
upload_map_graphics_descriptor_c1f547:
    .i16
    ldx #$0008
upload_map_graphics_descriptor_c1f54a:
    lda [$04],Y
    sta a:$2118
    iny
    bne upload_map_graphics_descriptor_c1f554
    inc $06
upload_map_graphics_descriptor_c1f554:
    iny
    bne upload_map_graphics_descriptor_c1f559
    inc $06
upload_map_graphics_descriptor_c1f559:
    dex
    bne upload_map_graphics_descriptor_c1f54a
    .i16
    ldx #$0008
    lda $00
upload_map_graphics_descriptor_c1f561:
    sta a:$2118
    dex
    bne upload_map_graphics_descriptor_c1f561
    dec $08
    bne upload_map_graphics_descriptor_c1f547
    rts
upload_map_graphics_descriptor_c1f56c:
    asl
    asl
    asl
    sta $04
    asl
    pha
    sep #$20
    .a8
    lda #$00
    .a8
    adc #$00
    sta $06
    rep #$20
    pla
    clc
    adc $04
    bcc upload_map_graphics_descriptor_c1f586
    inc $06
    clc
upload_map_graphics_descriptor_c1f586:
    adc f:$CCE270,X
    stz $04
    tay
    sep #$20
    lda f:$CCE272,X
    .a8
    ora #$C0
    adc $06
    sta $06
    rep #$30
upload_map_graphics_descriptor_c1f59b:
    .i16
    ldx #$0008
upload_map_graphics_descriptor_c1f59e:
    lda [$04],Y
    sta a:$2118
    iny
    bne upload_map_graphics_descriptor_c1f5a8
    inc $06
upload_map_graphics_descriptor_c1f5a8:
    iny
    bne upload_map_graphics_descriptor_c1f5ad
    inc $06
upload_map_graphics_descriptor_c1f5ad:
    dex
    bne upload_map_graphics_descriptor_c1f59e
    .i16
    ldx #$0008
    sep #$20
    lda $00
    xba
upload_map_graphics_descriptor_c1f5b8:
    sep #$20
    lda [$04],Y
    rep #$20
    sta a:$2118
    iny
    bne upload_map_graphics_descriptor_c1f5c6
    inc $06
upload_map_graphics_descriptor_c1f5c6:
    dex
    bne upload_map_graphics_descriptor_c1f5b8
    dec $08
    bne upload_map_graphics_descriptor_c1f59b
    rts
