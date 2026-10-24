; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-icon-upload.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C83F
hide_native_menu_icon_oam_objects:
    rep #$30
    .i16
    ldx #$082D
    sep #$20
    .a8
    lda #$E8
hide_native_menu_icon_oam_objects_d0c848:
    sta $00,X
    inx
    inx
    inx
    inx
    .i16
    cpx #$0878
    bcc hide_native_menu_icon_oam_objects_d0c848
    rep #$30
    rtl
