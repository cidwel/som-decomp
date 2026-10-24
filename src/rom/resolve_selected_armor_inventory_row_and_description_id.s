; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_wrapped_native_menu_row_index = $C06BE2

.segment "CODE"
.org $7C4C
resolve_selected_armor_inventory_row_and_description_id:
    jsl f:calculate_wrapped_native_menu_row_index
    rep #$30
    .a16
    and #$00FF
    tay
    .i16
    ldx #$0054
    sep #$20
resolve_selected_armor_inventory_row_and_description_id_c07c5b:
    lda f:$7ECC00,X
    inx
    .a8
    cmp #$FF
    beq resolve_selected_armor_inventory_row_and_description_id_c07c5b
    dey
    bpl resolve_selected_armor_inventory_row_and_description_id_c07c5b
    dex
    stx a:$183E
    sep #$30
    .a8
    and #$3F
    sta a:$1842
    txa
    sec
    .a8
    sbc #$54
    tax
    stx a:$1843
    rtl
