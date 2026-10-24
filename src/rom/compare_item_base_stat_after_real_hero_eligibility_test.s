; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16

add_wrapped_menu_row_to_inventory_label_offset = $D530
append_menu_stat_value_and_separator = $D787
append_menu_stat_value_and_terminator = $D7A9
locate_menu_category_inventory_and_equipment_spans = $D0C800
read_item_base_stat_from_native_ten_byte_table = $D9DE
routine_d0d7b1 = $D7B1
test_native_menu_item_eligibility_for_selected_hero = $C079C7

.segment "CODE"
.org $D720
compare_item_base_stat_after_real_hero_eligibility_test:
    jsl f:locate_menu_category_inventory_and_equipment_spans
    rep #$30
    tya
    clc
    adc a:$1849
    sta a:$184B
    stx a:$184D
    .a16
    lda #$1559
    sta a:$19D4
    ldx a:$184B
    lda f:$7EE180,X
    jsr read_item_base_stat_from_native_ten_byte_table
    .i16
    ldx #$19D6
    jsr append_menu_stat_value_and_separator
    rep #$30
    phx
    .a16
    lda #$0000
    jsr add_wrapped_menu_row_to_inventory_label_offset
    rep #$30
    .a16
    and #$00FF
    clc
    adc a:$184D
    tax
    lda f:$7ECC00,X
    phx
    php
    ldy a:$1808
    jsl f:test_native_menu_item_eligibility_for_selected_hero
    plp
    plx
    .a16
    and #$0001
    beq compare_item_base_stat_after_real_hero_eligibility_test_d0d778
    lda f:$7ECC00,X
    jsr read_item_base_stat_from_native_ten_byte_table
    plx
    bra append_menu_stat_value_and_terminator
compare_item_base_stat_after_real_hero_eligibility_test_d0d778:
    plx
    rep #$30
    .a16
    lda #$BFBF
    sta $00,X
    sta $02,X
    inx
    inx
    inx
    bra routine_d0d7b1
