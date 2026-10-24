; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-currency.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $7D0D
deduct_native_shop_price_from_persistent_money:
    rep #$30
    lda a:$1822
    pha
    .i16
    ldx #$0000
    lda f:$7ECC6A
    sec
    sbc $01,S
    php
    sta f:$7ECC6A
    plp
    bcs deduct_native_shop_price_from_persistent_money_c07d30
    sep #$20
    lda f:$7ECC6C
    dec
    sta f:$7ECC6C
deduct_native_shop_price_from_persistent_money_c07d30:
    rep #$30
    pla
    rts
