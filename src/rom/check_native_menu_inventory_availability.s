; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-gate.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FC90
check_native_menu_inventory_availability:
    rep #$30
    sep #$20
    lda a:$1847
    beq check_native_menu_inventory_availability_d9fca2
    .a8
    cmp #$02
    bne check_native_menu_inventory_availability_d9fcba
    .i16
    ldy #$0000
    bra check_native_menu_inventory_availability_d9fca5
check_native_menu_inventory_availability_d9fca2:
    .i16
    ldy #$000C
check_native_menu_inventory_availability_d9fca5:
    .i16
    ldx #$0024
check_native_menu_inventory_availability_d9fca8:
    lda f:$7ECC00,X
    .a8
    cmp #$FE
    bcc check_native_menu_inventory_availability_d9fcba
    inx
    iny
    .i16
    cpy #$0030
    bcc check_native_menu_inventory_availability_d9fca8
    .a8
    lda #$00
    rtl
check_native_menu_inventory_availability_d9fcba:
    .a8
    lda #$01
    rtl
