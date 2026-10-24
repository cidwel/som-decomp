; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-builder.md.
.setcpu "65816"
.smart
.a8
.i16

build_native_inventory_descriptors_apply_status_masks_and_rotate = $CF9C
build_shop_menu_descriptor_list_and_apply_native_row_order = $CF61

.segment "CODE"
.org $CF48
build_native_menu_descriptor_source_for_shop_or_inventory:
    rep #$30
    stz a:$182E
    sep #$20
    stz a:$180A
    lda a:$1847
    .a8
    cmp #$01
    beq build_native_menu_descriptor_source_for_shop_or_inventory_d0cf5d
    jsr build_native_inventory_descriptors_apply_status_masks_and_rotate
    rtl
build_native_menu_descriptor_source_for_shop_or_inventory_d0cf5d:
    jsr build_shop_menu_descriptor_list_and_apply_native_row_order
    rtl
