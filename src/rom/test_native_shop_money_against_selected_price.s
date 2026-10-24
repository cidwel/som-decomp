; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-currency.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $7C86
test_native_shop_money_against_selected_price:
    rep #$30
    pha
    .i16
    ldx #$0000
    lda f:$7ECC6A
    sec
    sbc $01,S
    bcs test_native_shop_money_against_selected_price_c07ca1
    sep #$20
    lda f:$7ECC6C
    dec
    .a8
    cmp #$FF
    bne test_native_shop_money_against_selected_price_c07ca1
    inx
test_native_shop_money_against_selected_price_c07ca1:
    rep #$30
    pla
    rts
