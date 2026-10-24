; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-records.md.
.setcpu "65816"
.smart
.a8
.i16

store_native_shop_five_bit_selector_and_form_oam_coordinate = $60BA

.segment "CODE"
.org $6081
publish_three_native_shop_five_bit_icon_selectors:
    rep #$20
    lda a:$A24E
    .a16
    and #$00FF
    asl
    tax
    lda a:$A23E,X
    sep #$10
    .i8
    ldx #$00
    pha
    jsr store_native_shop_five_bit_selector_and_form_oam_coordinate
    tay
    sty a:$9C00
    pla
    lsr
    lsr
    lsr
    lsr
    lsr
    pha
    jsr store_native_shop_five_bit_selector_and_form_oam_coordinate
    tay
    sty a:$9C04
    pla
    lsr
    lsr
    lsr
    lsr
    lsr
    jsr store_native_shop_five_bit_selector_and_form_oam_coordinate
    tay
    sty a:$9C08
    sep #$20
    rep #$10
    rts
