; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-currency.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $7D34
credit_native_shop_price_and_cap_persistent_money:
    rep #$30
    lda a:$1822
    pha
    .i16
    ldx #$0000
    lda f:$7ECC6A
    clc
    adc $01,S
    php
    sta f:$7ECC6A
    plp
    bcc credit_native_shop_price_and_cap_persistent_money_c07d57
    sep #$20
    lda f:$7ECC6C
    inc
    sta f:$7ECC6C
credit_native_shop_price_and_cap_persistent_money_c07d57:
    sep #$20
    lda f:$7ECC6C
    .a8
    cmp #$98
    bcc credit_native_shop_price_and_cap_persistent_money_c07d7f
    bne credit_native_shop_price_and_cap_persistent_money_c07d6e
    rep #$20
    lda f:$7ECC6A
    .a16
    cmp #$967F
    bcc credit_native_shop_price_and_cap_persistent_money_c07d7f
credit_native_shop_price_and_cap_persistent_money_c07d6e:
    sep #$20
    .a8
    lda #$98
    sta f:$7ECC6C
    rep #$20
    .a16
    lda #$967F
    sta f:$7ECC6A
credit_native_shop_price_and_cap_persistent_money_c07d7f:
    rep #$30
    pla
    rts
