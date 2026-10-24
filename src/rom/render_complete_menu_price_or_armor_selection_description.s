; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_menu_item_price_preserving_register_context = $D8DE
format_native_menu_price_with_five_decimal_places = $D89E
resolve_selected_armor_inventory_row_and_description_id = $C07C4C

.segment "CODE"
.org $D822
render_complete_menu_price_or_armor_selection_description:
    rep #$30
    .a16
    lda #$1559
    sta a:$19D4
    .i16
    ldx #$19D6
    sep #$20
    lda a:$1847
    .a8
    cmp #$03
    bne render_complete_menu_price_or_armor_selection_description_d0d87f
    rep #$20
    .a16
    lda #$1059
    sta a:$19D4
    .a16
    lda #$00D0
    sta a:$19D6
    .a16
    lda #$BFBF
    sta a:$19D7
    sta a:$19D9
    lda a:$180A
    .a16
    and #$00FF
    asl
    tax
    lda f:$0018A0,X
    .a16
    bit #$4000
    bne render_complete_menu_price_or_armor_selection_description_d0d876
    jsl f:resolve_selected_armor_inventory_row_and_description_id
    sep #$20
    lda a:$1842
    inc
    clc
    .a8
    adc #$B5
    sta a:$19D7
    rep #$30
    .a16
    lda #$8080
    sta a:$19D8
render_complete_menu_price_or_armor_selection_description_d0d876:
    .a16
    lda #$1559
    sta a:$19DA
    .i16
    ldx #$19DC
render_complete_menu_price_or_armor_selection_description_d0d87f:
    rep #$30
    .a16
    lda #$0000
    sta $00,X
    jsr calculate_menu_item_price_preserving_register_context
    .a16
    cmp #$FFFF
    beq render_complete_menu_price_or_armor_selection_description_d0d89d
    jsr format_native_menu_price_with_five_decimal_places
    rep #$20
    .a16
    lda #$AAA1
    sta $00,X
    .a16
    lda #$0000
    sta $02,X
render_complete_menu_price_or_armor_selection_description_d0d89d:
    rts
