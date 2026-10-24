; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16

append_menu_stat_value_and_separator = $D787
append_menu_stat_value_and_terminator = $D7A9
calculate_wrapped_native_menu_row_index = $C06BE2
offset_armor_inventory_description_by_position = $D0D1FB
rebuild_selected_hero_attributes_for_menu_description = $D9CE

.segment "CODE"
.org $D6C0
compare_armor_stat_using_temporary_real_equipment_rebuild:
    jsr rebuild_selected_hero_attributes_for_menu_description
    rep #$30
    .a16
    lda #$1559
    sta a:$19D4
    ldx a:$1849
    lda f:$7EE1E8,X
    pha
    lda f:$7EE198,X
    .i16
    ldx #$19D6
    jsr append_menu_stat_value_and_separator
    phx
    jsl f:calculate_wrapped_native_menu_row_index
    sep #$30
    tay
    .i8
    ldx #$54
compare_armor_stat_using_temporary_real_equipment_rebuild_d0d6e7:
    lda f:$7ECC00,X
    inx
    .a8
    cmp #$FF
    beq compare_armor_stat_using_temporary_real_equipment_rebuild_d0d6e7
    dey
    bpl compare_armor_stat_using_temporary_real_equipment_rebuild_d0d6e7
    dex
    rep #$10
    jsl f:offset_armor_inventory_description_by_position
    ldx a:$1849
    sep #$20
    sta f:$7EE1E8,X
    jsr rebuild_selected_hero_attributes_for_menu_description
    rep #$20
    ldx a:$1849
    lda f:$7EE198,X
    plx
    jsr append_menu_stat_value_and_terminator
    pla
    ldx a:$1849
    sep #$20
    sta f:$7EE1E8,X
    jmp rebuild_selected_hero_attributes_for_menu_description
