; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_copy_queue_record = $C915
allocate_ppu_register_entry = $C030
allocate_transfer_descriptor = $8FC7
append_copy_queue_record = $C95A
append_oneshot_ppu_entry = $C097
submit_transfer_or_program_hdma = $90DA

.segment "CODE"
.org $CE6B
build_title_window_scanline_table:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0008
    tcd
    tcs
    tya
    asl
    tay
    stx $05
    sec
    sbc $05
    bcs build_title_window_scanline_table_ce83
    .a16
    lda #$0000
build_title_window_scanline_table_ce83:
    lsr
    sta $01
    tya
    clc
    adc $05
    .a16
    cmp #$01C0
    bcc build_title_window_scanline_table_ce92
    .a16
    lda #$01BF
build_title_window_scanline_table_ce92:
    lsr
    sta $03
    sec
    sbc $01
    sta $05
    .a16
    lda #$002C
    jsr allocate_ppu_register_entry
    stx $07
    ldy a:$030C
    sep #$20
    lda $01
    beq build_title_window_scanline_table_cf19
    .a8
    cmp #$80
    bcc build_title_window_scanline_table_cedd
    phy
    lda a:$0002,X
    .a8
    and #$EE
    pha
    jsr allocate_copy_queue_record
    .a8
    lda #$7F
    sta a:$0005,X
    pla
    sta a:$0006,X
    .a8
    lda #$02
    sta a:$0004,X
    rep #$20
    lda $01,S
    sta a:$0001,X
    sep #$20
    jsr append_copy_queue_record
    ldx $07
    ply
    iny
    iny
    lda $01
    sec
    .a8
    sbc #$7F
build_title_window_scanline_table_cedd:
    phy
    pha
    lda a:$0002,X
    .a8
    and #$EE
    pha
    sta a:$0002,X
    jsr allocate_copy_queue_record
    pla
    sta a:$0006,X
    pla
    sta a:$0005,X
    .a8
    lda #$02
    sta a:$0004,X
    rep #$20
    lda $01,S
    sta a:$0001,X
    sep #$20
    jsr append_copy_queue_record
    ldx $07
    ply
    iny
    iny
    lda $03
    .a8
    cmp #$DF
    bcc build_title_window_scanline_table_cf21
    lda $05
    beq build_title_window_scanline_table_cf21
    dec $05
    dec $03
    bra build_title_window_scanline_table_cf21
build_title_window_scanline_table_cf19:
    lda a:$0002,X
    .a8
    ora #$11
    sta a:$0002,X
build_title_window_scanline_table_cf21:
    lda $05
    beq build_title_window_scanline_table_cf7e
    .a8
    cmp #$80
    bcc build_title_window_scanline_table_cf57
    phy
    lda a:$0002,X
    .a8
    ora #$11
    pha
    jsr allocate_copy_queue_record
    pla
    sta a:$0006,X
    .a8
    lda #$7F
    sta a:$0005,X
    .a8
    lda #$02
    sta a:$0004,X
    rep #$20
    lda $01,S
    sta a:$0001,X
    sep #$20
    jsr append_copy_queue_record
    ldx $07
    ply
    iny
    iny
    lda $05
    sec
    .a8
    sbc #$7F
build_title_window_scanline_table_cf57:
    phy
    pha
    lda a:$0002,X
    .a8
    ora #$11
    pha
    jsr allocate_copy_queue_record
    pla
    sta a:$0006,X
    pla
    sta a:$0005,X
    .a8
    lda #$02
    sta a:$0004,X
    rep #$20
    lda $01,S
    sta a:$0001,X
    sep #$20
    jsr append_copy_queue_record
    ply
    iny
    iny
build_title_window_scanline_table_cf7e:
    phy
    jsr allocate_copy_queue_record
    ldy $07
    .a8
    lda #$01
    sta a:$0005,X
    lda a:$0002,Y
    sta a:$0006,X
    stz a:$0007,X
    .a8
    lda #$03
    sta a:$0004,X
    rep #$20
    lda $01,S
    sta a:$0001,X
    sep #$20
    jsr append_copy_queue_record
    ply
    ldx $07
    jsr append_oneshot_ppu_entry
    ldx a:$030E
    bne build_title_window_scanline_table_cfd3
    rep #$20
    .a16
    lda #$0005
    jsr allocate_transfer_descriptor
    stx a:$030E
    lda a:$030C
    sta a:$0002,X
    sep #$20
    .a8
    lda #$00
    sta a:$0000,X
    .a8
    lda #$2C
    sta a:$0001,X
    .a8
    lda #$7F
    sta a:$0004,X
    jsr submit_transfer_or_program_hdma
build_title_window_scanline_table_cfd3:
    ldx $01
    ldy $03
    rep #$20
    tsc
    clc
    .a16
    adc #$0008
    tcs
    plp
    pld
    rts
