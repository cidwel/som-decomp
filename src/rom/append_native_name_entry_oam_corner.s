; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-name-helpers.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5148
append_native_name_entry_oam_corner:
    phy
    lda a:$A173
    sta a:$9C00,X
    inx
    lda a:$A174
    sta a:$9C00,X
    inx
    pla
    sta a:$9C00,X
    inx
    pla
    sta a:$9C00,X
    inx
    rts
