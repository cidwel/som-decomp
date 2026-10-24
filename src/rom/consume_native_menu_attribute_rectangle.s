; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-page-records.md.
.setcpu "65816"
.smart
.a8
.i16

expand_native_menu_counted_rom_tile_rectangle = $272B

.segment "CODE"
.org $2626
consume_native_menu_attribute_rectangle:
    ldx a:$0000,Y
    iny
    iny
    lda a:$0000,Y
    iny
    phy
    .i16
    ldy #$77C7
    sta f:$7EA198
    jsr expand_native_menu_counted_rom_tile_rectangle
    .a8
    lda #$00
    sta f:$7EA198
    ply
    rts
