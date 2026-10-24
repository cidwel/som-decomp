; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_menu_digit_with_leading_zero_suppression = $D7FD
calculate_wrapped_native_menu_row_index = $C06BE2
read_consumable_inventory_quantity = $D9B4
read_consumable_inventory_record = $D9BF

.segment "CODE"
.org $D624
format_consumable_inventory_quantity_description:
    jsl f:calculate_wrapped_native_menu_row_index
    rep #$30
    .a16
    and #$00FF
    jsr read_consumable_inventory_record
    .a16
    and #$001F
    .a16
    cmp #$0006
    bcc format_consumable_inventory_quantity_description_d0d63d
    .a16
    cmp #$000A
    bcc format_consumable_inventory_quantity_description_d0d66e
format_consumable_inventory_quantity_description_d0d63d:
    .a16
    lda #$1A59
    sta a:$19D4
    .i16
    ldx #$19D6
    .a16
    lda #$00CD
    sta $00,X
    jsl f:calculate_wrapped_native_menu_row_index
    rep #$20
    .a16
    and #$00FF
    jsr read_consumable_inventory_quantity
    pha
    .a16
    lda #$0010
    tsb a:$1802
    pla
    .a16
    and #$000F
    sep #$20
    .i16
    ldx #$19D7
    jsr append_native_menu_digit_with_leading_zero_suppression
    .a8
    lda #$00
    sta $01,X
format_consumable_inventory_quantity_description_d0d66e:
    rts
