; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2781
clear_native_menu_sprite_and_tile_workspaces:
    .i16
    ldx #$0000
    .i16
    ldy #$0536
clear_native_menu_sprite_and_tile_workspaces_c02787:
    stz a:$9C00,X
    inx
    dey
    bne clear_native_menu_sprite_and_tile_workspaces_c02787
    .i16
    ldx #$0800
    .i16
    ldy #$0000
    .a8
    lda #$00
clear_native_menu_sprite_and_tile_workspaces_c02796:
    sta a:$9000,Y
    iny
    dex
    bne clear_native_menu_sprite_and_tile_workspaces_c02796
    rts
