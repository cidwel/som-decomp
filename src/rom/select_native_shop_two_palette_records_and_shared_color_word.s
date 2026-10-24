; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-records.md.
.setcpu "65816"
.smart
.a8
.i16

copy_six_native_shop_palette_record_bytes = $6106

.segment "CODE"
.org $60D7
select_native_shop_two_palette_records_and_shared_color_word:
    .a8
    lda #$00
    xba
    lda a:$A24E
    tax
    phx
    lda f:$C77159,X
    .i16
    ldy #$0000
    jsr copy_six_native_shop_palette_record_bytes
    iny
    iny
    plx
    lda f:$C77161,X
    phx
    jsr copy_six_native_shop_palette_record_bytes
    plx
    rep #$20
    txa
    asl
    tax
    lda a:$A23E,X
    sta a:$A1B0
    sta a:$A22D
    sep #$20
    rts
