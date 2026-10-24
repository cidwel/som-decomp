; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-page-sprites.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6D30
append_native_menu_grid_icon_tile_from_rom:
    lda a:$A15A
    asl
    asl
    asl
    sta a:$9C00,Y
    iny
    lda a:$A159
    asl
    asl
    asl
    sta a:$9C00,Y
    iny
    lda f:$C70000,X
    sta a:$9C00,Y
    iny
    inx
    lda f:$C70000,X
    sta a:$9C00,Y
    iny
    inx
    rts
