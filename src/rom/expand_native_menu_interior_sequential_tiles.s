; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-page-records.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2533
expand_native_menu_interior_sequential_tiles:
    lda a:$A1C7
expand_native_menu_interior_sequential_tiles_c02536:
    rep #$20
    sta a:$9000,X
    inc
    inc
    sta a:$9040,X
    inc
    inc
    inx
    inx
    sep #$20
    dec a:$A164
    bne expand_native_menu_interior_sequential_tiles_c02536
    rep #$20
    .a16
    ora #$2000
    sta a:$A1C7
    sep #$20
    rts
