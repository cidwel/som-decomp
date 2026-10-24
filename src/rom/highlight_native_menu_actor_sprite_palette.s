; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-controller.md.
.setcpu "65816"
.smart
.a8
.i16

select_native_menu_actor_sprite_span = $1F18

.segment "CODE"
.org $1EFD
highlight_native_menu_actor_sprite_palette:
    .a8
    lda #$00
    xba
    jsr select_native_menu_actor_sprite_span
highlight_native_menu_actor_sprite_palette_c01f03:
    lda a:$9C03,X
    .a8
    ora #$30
    sta a:$9C03,X
    inx
    inx
    inx
    inx
    dey
    bne highlight_native_menu_actor_sprite_palette_c01f03
    .a8
    lda #$04
    tsb a:$A20A
    rts
