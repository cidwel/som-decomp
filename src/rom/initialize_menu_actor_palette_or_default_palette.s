; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-palette-graphics.md.
.setcpu "65816"
.smart
.a8
.i16

copy_selected_menu_actor_palette_with_mode7_product = $CDB2

.segment "CODE"
.org $CD8E
initialize_menu_actor_palette_or_default_palette:
    rep #$30
    lda a:$1847
    .a16
    and #$00FF
    bne copy_selected_menu_actor_palette_with_mode7_product
    .i16
    ldx #$0000
initialize_menu_actor_palette_or_default_palette_d0cd9b:
    lda f:$C81E6A,X
    sta a:$0702,X
    inx
    inx
    .i16
    cpx #$001E
    bcc initialize_menu_actor_palette_or_default_palette_d0cd9b
