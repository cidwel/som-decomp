; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16

adjust_menu_price_for_shop_and_inventory_modes = $C07CD4
calculate_wrapped_native_menu_row_index = $C06BE2
hide_shop_hero_markers_before_price_selection = $C0793D
publish_shop_item_eligible_hero_markers = $D9F6
resolve_selected_armor_inventory_row_and_description_id = $C07C4C

.segment "CODE"
.org $D8E8
calculate_complete_native_menu_item_price:
    rep #$30
    sep #$20
    lda a:$1847
    dec
    beq calculate_complete_native_menu_item_price_d0d961
    dec
    beq calculate_complete_native_menu_item_price_d0d90f
    sep #$20
    jsl f:resolve_selected_armor_inventory_row_and_description_id
    lda a:$1842
    rep #$30
    .a16
    and #$00FF
    asl
    clc
    adc f:$D8FB82
    tax
    lda f:$D80000,X
    rts
calculate_complete_native_menu_item_price_d0d90f:
    sep #$20
    lda a:$1809
    .i16
    ldx #$0024
    .i16
    ldy #$0012
    .a8
    cmp #$04
    beq calculate_complete_native_menu_item_price_d0d938
    .i16
    ldx #$0030
    .i16
    ldy #$000C
    .a8
    cmp #$05
    beq calculate_complete_native_menu_item_price_d0d938
    .i16
    ldx #$003C
    .i16
    ldy #$0006
    .a8
    cmp #$06
    beq calculate_complete_native_menu_item_price_d0d938
    .i16
    ldx #$0048
    .i16
    ldy #$0000
calculate_complete_native_menu_item_price_d0d938:
    jsl f:calculate_wrapped_native_menu_row_index
    rep #$20
    .a16
    and #$00FF
    phx
    clc
    adc $01,S
    plx
    tax
    lda f:$7ECC00,X
    .a16
    and #$003F
    tyx
    .i16
    cpy #$0000
    bne calculate_complete_native_menu_item_price_d0d959
    .a16
    and #$001F
    bra calculate_complete_native_menu_item_price_d0d9a4
calculate_complete_native_menu_item_price_d0d959:
    sec
    sbc f:$D8FB86,X
    jmp calculate_complete_native_menu_item_price_d0d9a4
calculate_complete_native_menu_item_price_d0d961:
    sep #$20
    lda a:$180A
    rep #$20
    .a16
    and #$00FF
    clc
    adc a:$183C
    tax
    lda f:$D80000,X
    .a16
    and #$00FF
    pha
    jsl f:hide_shop_hero_markers_before_price_selection
    .i16
    ldx #$FFFA
calculate_complete_native_menu_item_price_d0d97f:
    inx
    inx
    inx
    inx
    inx
    inx
    lda f:$D8FB84,X
    cmp $01,S
    beq calculate_complete_native_menu_item_price_d0d98f
    bcs calculate_complete_native_menu_item_price_d0d97f
calculate_complete_native_menu_item_price_d0d98f:
    ply
    pha
    tya
    sec
    sbc $01,S
    pha
    phx
    php
    clc
    adc f:$D8FB86,X
    jsr publish_shop_item_eligible_hero_markers
    plp
    plx
    pla
    ply
calculate_complete_native_menu_item_price_d0d9a4:
    asl
    clc
    adc f:$D8FB88,X
    tax
    lda f:$D80000,X
    jsl f:adjust_menu_price_for_shop_and_inventory_modes
    rts
