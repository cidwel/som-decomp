; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-page-records.md.
.setcpu "65816"
.smart
.a8
.i16

expand_native_menu_counted_rom_tile_rectangle = $272B

.segment "CODE"
.org $2697
consume_native_menu_rectangle_76f5:
    ldx a:$0000,Y
    iny
    iny
    phy
    .i16
    ldy #$76F5
    jsr expand_native_menu_counted_rom_tile_rectangle
    ply
    rts
