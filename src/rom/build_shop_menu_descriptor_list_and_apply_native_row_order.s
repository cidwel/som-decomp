; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-descriptor-sources.md.
.setcpu "65816"
.smart
.a8
.i16

clear_native_menu_descriptor_row_attributes = $D308
rotate_native_menu_descriptor_rows_and_append_category_tail = $D319

.segment "CODE"
.org $CF61
build_shop_menu_descriptor_list_and_apply_native_row_order:
    rep #$30
    jsr clear_native_menu_descriptor_row_attributes
    ldx a:$183C
    .i16
    ldy #$1880
build_shop_menu_descriptor_list_and_apply_native_row_order_d0cf6c:
    txa
    sec
    sbc a:$183C
    .a16
    cmp #$000C
    beq build_shop_menu_descriptor_list_and_apply_native_row_order_d0cf93
    lda f:$D80000,X
    inx
    .a16
    and #$00FF
    .a16
    cmp #$00FF
    beq build_shop_menu_descriptor_list_and_apply_native_row_order_d0cf93
    phx
    dec
    asl
    tax
    lda f:$D8FD7E,X
    sta a:$0000,Y
    iny
    iny
    plx
    bra build_shop_menu_descriptor_list_and_apply_native_row_order_d0cf6c
build_shop_menu_descriptor_list_and_apply_native_row_order_d0cf93:
    .a16
    lda #$FFFF
    sta a:$0000,Y
    jmp rotate_native_menu_descriptor_rows_and_append_category_tail
