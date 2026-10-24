; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-records.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6106
copy_six_native_shop_palette_record_bytes:
    rep #$20
    asl
    sta a:$A173
    asl
    clc
    adc a:$A173
    tax
    sep #$20
    .a8
    lda #$06
copy_six_native_shop_palette_record_bytes_c76116:
    xba
    lda f:$D2DB80,X
    sta a:$A1A6,Y
    iny
    inx
    xba
    dec
    bne copy_six_native_shop_palette_record_bytes_c76116
    rts
