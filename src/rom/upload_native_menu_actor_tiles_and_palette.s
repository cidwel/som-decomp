; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-constructor.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2010
upload_native_menu_actor_tiles_and_palette:
    phb
    .a8
    lda #$00
    pha
    plb
    .i16
    ldx #$4200
    stx a:$2116
    rep #$20
    .i16
    ldx #$0000
    .i16
    ldy #$0002
upload_native_menu_actor_tiles_and_palette_c02023:
    phy
    .i16
    ldy #$0008
upload_native_menu_actor_tiles_and_palette_c02027:
    lda f:$D2DA30,X
    sta a:$2118
    inx
    inx
    dey
    bne upload_native_menu_actor_tiles_and_palette_c02027
    .i16
    ldy #$0008
upload_native_menu_actor_tiles_and_palette_c02036:
    stz a:$2118
    dey
    bne upload_native_menu_actor_tiles_and_palette_c02036
    ply
    dey
    bne upload_native_menu_actor_tiles_and_palette_c02023
    sep #$20
    .a8
    lda #$81
    sta a:$2121
    .i16
    ldy #$0006
    .i16
    ldx #$0030
upload_native_menu_actor_tiles_and_palette_c0204d:
    lda f:$D2DBC0,X
    sta a:$2122
    inx
    dey
    bne upload_native_menu_actor_tiles_and_palette_c0204d
    plb
    rts
