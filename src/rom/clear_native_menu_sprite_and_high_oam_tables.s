; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-controller.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1F36
clear_native_menu_sprite_and_high_oam_tables:
    .i16
    ldx #$0000
    .i16
    ldy #$0080
    rep #$20
    .a16
    lda #$F8F8
clear_native_menu_sprite_and_high_oam_tables_c01f41:
    sta a:$9C00,X
    inx
    inx
    stz a:$9C00,X
    inx
    inx
    dey
    bne clear_native_menu_sprite_and_high_oam_tables_c01f41
    sep #$20
    .i16
    ldy #$0020
clear_native_menu_sprite_and_high_oam_tables_c01f53:
    stz a:$9C00,X
    inx
    dey
    bne clear_native_menu_sprite_and_high_oam_tables_c01f53
    rts
