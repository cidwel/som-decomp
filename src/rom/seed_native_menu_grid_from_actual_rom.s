; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $21BE
seed_native_menu_grid_from_actual_rom:
    .i16
    ldx #$0000
    .a8
    lda #$1C
    sta a:$A171
seed_native_menu_grid_from_actual_rom_c021c6:
    .a8
    lda #$10
seed_native_menu_grid_from_actual_rom_c021c8:
    xba
    lda f:$D2D880,X
    sta a:$9000,X
    inx
    xba
    dec
    bne seed_native_menu_grid_from_actual_rom_c021c8
    dec a:$A171
    bne seed_native_menu_grid_from_actual_rom_c021c6
    rts
