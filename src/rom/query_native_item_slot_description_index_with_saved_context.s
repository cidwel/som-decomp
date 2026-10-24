; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-api.md.
.setcpu "65816"
.smart
.a8
.i16

normalize_menu_native_direct_page_and_bank = $C064A4
offset_armor_inventory_description_by_position = $D0D1FB

.segment "CODE"
.org $6481
query_native_item_slot_description_index_with_saved_context:
    phx
    phy
    php
    phb
    phd
    jsl f:normalize_menu_native_direct_page_and_bank
    sep #$30
    .a8
    lda #$03
    sta a:$1809
    tya
    clc
    .a8
    adc #$54
    tax
    lda f:$7ECC00,X
    jsl f:offset_armor_inventory_description_by_position
    pld
    plb
    plp
    ply
    plx
    rtl
