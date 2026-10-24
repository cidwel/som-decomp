; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-page-records.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $272B
expand_native_menu_counted_rom_tile_rectangle:
    lda a:$0001,Y
    sta f:$7EA174
    lda a:$0000,Y
    sta f:$7EA173
    lda f:$7EA174
    sta f:$7EA176
expand_native_menu_counted_rom_tile_rectangle_c02741:
    phx
    lda f:$7EA173
    sta f:$7EA171
expand_native_menu_counted_rom_tile_rectangle_c0274a:
    lda a:$0002,Y
    sta f:$7E9000,X
    lda a:$0003,Y
    ora f:$7EA198
    sta f:$7E9001,X
    inx
    inx
    iny
    iny
    lda f:$7EA171
    dec
    sta f:$7EA171
    bne expand_native_menu_counted_rom_tile_rectangle_c0274a
    rep #$20
    pla
    clc
    .a16
    adc #$0040
    tax
    sep #$20
    lda f:$7EA176
    dec
    sta f:$7EA176
    bne expand_native_menu_counted_rom_tile_rectangle_c02741
    rts
