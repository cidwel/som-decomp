; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C800
locate_menu_category_inventory_and_equipment_spans:
    rep #$30
    lda a:$1809
    .a16
    and #$00FF
    sec
    .a16
    sbc #$0004
    beq locate_menu_category_inventory_and_equipment_spans_d0c821
    dec
    beq locate_menu_category_inventory_and_equipment_spans_d0c82b
    dec
    beq locate_menu_category_inventory_and_equipment_spans_d0c835
    dec
    beq locate_menu_category_inventory_and_equipment_spans_d0c82b
    .i16
    ldx #$0054
    .i16
    ldy #$0063
    .a16
    lda #$0000
    rtl
locate_menu_category_inventory_and_equipment_spans_d0c821:
    .i16
    ldx #$0024
    .i16
    ldy #$0060
    .a16
    lda #$0000
    rtl
locate_menu_category_inventory_and_equipment_spans_d0c82b:
    .i16
    ldx #$0030
    .i16
    ldy #$0061
    .a16
    lda #$0015
    rtl
locate_menu_category_inventory_and_equipment_spans_d0c835:
    .i16
    ldx #$003C
    .i16
    ldy #$0062
    .a16
    lda #$002A
    rtl
