; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-publication.md.
.setcpu "65816"
.smart
.a8
.i16

publish_three_native_shop_five_bit_icon_selectors = $6081

.segment "CODE"
.org $62B8
pack_three_native_shop_selectors_and_refresh_icon_oam:
    .a8
    lda #$00
    xba
    lda a:$A24E
    asl
    tax
    .i16
    ldy #$0000
    rep #$20
    stz a:$A23E,X
    .a16
    lda #$0003
    sta a:$A173
pack_three_native_shop_selectors_and_refresh_icon_oam_c762ce:
    .a16
    lda #$0005
    sta a:$A1CE
    lda a:$A1D1,Y
    .a16
    and #$001F
pack_three_native_shop_selectors_and_refresh_icon_oam_c762da:
    lsr
    ror a:$A23E,X
    dec a:$A1CE
    bne pack_three_native_shop_selectors_and_refresh_icon_oam_c762da
    iny
    dec a:$A173
    bne pack_three_native_shop_selectors_and_refresh_icon_oam_c762ce
    lsr a:$A23E,X
    lda a:$A23E,X
    sta a:$A22D
    sep #$20
    jsr publish_three_native_shop_five_bit_icon_selectors
    .a8
    lda #$04
    tsb a:$A20A
    rts
