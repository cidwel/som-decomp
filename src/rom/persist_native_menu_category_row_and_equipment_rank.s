; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-navigation-icons.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_wrapped_native_menu_row_index = $C06BE2
locate_selected_armor_with_nonzero_level = $D0D0DA
locate_selected_weapon_with_nonzero_level = $D0D0B0

.segment "CODE"
.org $6B4C
persist_native_menu_category_row_and_equipment_rank:
    rep #$30
    lda a:$1808
    .a16
    and #$00FF
    clc
    .a16
    adc #$1870
    tax
    sep #$20
    .a8
    lda #$08
    bit a:$1803
    beq persist_native_menu_category_row_and_equipment_rank_c06b65
    jmp persist_native_menu_category_row_and_equipment_rank_c06bd2
persist_native_menu_category_row_and_equipment_rank_c06b65:
    lda a:$1809
    sta $00,X
    jsl f:calculate_wrapped_native_menu_row_index
    lda a:$1809
    .a8
    cmp #$03
    bcs persist_native_menu_category_row_and_equipment_rank_c06bd2
    .i16
    ldx #$1873
    .a8
    ora #$00
    beq persist_native_menu_category_row_and_equipment_rank_c06bcd
    .i16
    ldx #$1876
    dec
    bne persist_native_menu_category_row_and_equipment_rank_c06bcd
    lda a:$1808
    .a8
    cmp #$01
    bne persist_native_menu_category_row_and_equipment_rank_c06baa
    .i16
    ldx #$1874
    lda a:$1803
    bpl persist_native_menu_category_row_and_equipment_rank_c06bcd
    rep #$20
    jsl f:locate_selected_weapon_with_nonzero_level
    sep #$20
    lda a:$1835
    .a8
    and #$03
    asl
    asl
    asl
    asl
    pha
    lda a:$1878,X
    .a8
    and #$03
    bra persist_native_menu_category_row_and_equipment_rank_c06bc5
persist_native_menu_category_row_and_equipment_rank_c06baa:
    .i16
    ldx #$1875
    lda a:$1803
    bpl persist_native_menu_category_row_and_equipment_rank_c06bcd
    rep #$20
    jsl f:locate_selected_armor_with_nonzero_level
    sep #$20
    lda a:$1835
    .a8
    and #$03
    pha
    lda a:$1878,X
    .a8
    and #$30
persist_native_menu_category_row_and_equipment_rank_c06bc5:
    ora $01,S
    sta a:$1878,X
    pla
    bra persist_native_menu_category_row_and_equipment_rank_c06bd2
persist_native_menu_category_row_and_equipment_rank_c06bcd:
    lda a:$1835
    sta $00,X
persist_native_menu_category_row_and_equipment_rank_c06bd2:
    sep #$20
    lda a:$1808
    cmp a:$1805
    beq persist_native_menu_category_row_and_equipment_rank_c06bdf
    sta a:$1877
persist_native_menu_category_row_and_equipment_rank_c06bdf:
    rep #$20
    rtl
