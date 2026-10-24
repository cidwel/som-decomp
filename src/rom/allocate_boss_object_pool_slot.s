; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0D53
allocate_boss_object_pool_slot:
    stx $66
    sty $68
    sep #$20
    .i16
    ldx #$0000
    lda $69
    .a8
    bit #$20
    beq allocate_boss_object_pool_slot_c20d65
    .i16
    ldx #$0003
allocate_boss_object_pool_slot_c20d65:
    lda a:$0E60,X
    beq allocate_boss_object_pool_slot_c20d74
    inx
    .i16
    cpx #$0009
    bne allocate_boss_object_pool_slot_c20d65
    rep #$20
    sec
    rts
allocate_boss_object_pool_slot_c20d74:
    .a8
    lda #$01
    sta a:$0E60,X
    rep #$20
    txa
    pha
    xba
    asl
    clc
    .a16
    adc #$E600
    tax
    lda $68
    sta a:$0098,X
    lda $66
    stz a:$0059,X
    sta a:$008E,X
    stz a:$0094,X
    stz a:$0096,X
    stz a:$00AD,X
    stz a:$0090,X
    stz a:$0070,X
    stz a:$0062,X
    stz a:$00A3,X
    stz a:$0088,X
    stz a:$0018
    stz a:$001A
    pla
    clc
    rts
