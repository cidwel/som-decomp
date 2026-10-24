; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16

divide_menu_number_using_snes_arithmetic_registers = $D0D7E2

.segment "CODE"
.org $7CD4
adjust_menu_price_for_shop_and_inventory_modes:
    sta a:$1822
    tay
    .a16
    cmp #$FFFF
    beq adjust_menu_price_for_shop_and_inventory_modes_c07d07
    sep #$20
    lda a:$1847
    dec
    bne adjust_menu_price_for_shop_and_inventory_modes_c07cf3
    .a8
    lda #$99
    cmp a:$185B
    bne adjust_menu_price_for_shop_and_inventory_modes_c07d07
    rep #$20
    asl a:$1822
    bra adjust_menu_price_for_shop_and_inventory_modes_c07d07
adjust_menu_price_for_shop_and_inventory_modes_c07cf3:
    sep #$20
    dec
    bne adjust_menu_price_for_shop_and_inventory_modes_c07d07
    .a8
    lda #$03
    jsl f:divide_menu_number_using_snes_arithmetic_registers
    rep #$20
    lda a:$4214
    asl
    sta a:$1822
adjust_menu_price_for_shop_and_inventory_modes_c07d07:
    rep #$20
    lda a:$1822
    rtl
