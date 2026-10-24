; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-page-records.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2596
expand_native_menu_border_interior_columns:
expand_native_menu_border_interior_columns_c02596:
    rep #$20
    sta a:$9000,X
    inx
    inx
    sep #$20
    dec a:$A164
    bne expand_native_menu_border_interior_columns_c02596
    lda a:$A16C
    sta a:$A164
    rep #$20
    rts
