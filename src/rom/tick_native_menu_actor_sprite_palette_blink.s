; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-controller.md.
.setcpu "65816"
.smart
.a8
.i16

select_native_menu_actor_sprite_span = $1F18

.segment "CODE"
.org $1ED1
tick_native_menu_actor_sprite_palette_blink:
    lda a:$A202
    .a8
    cmp #$04
    bne tick_native_menu_actor_sprite_palette_blink_c01efc
    dec a:$A19F
    bne tick_native_menu_actor_sprite_palette_blink_c01efc
    .a8
    lda #$00
    xba
    jsr select_native_menu_actor_sprite_span
tick_native_menu_actor_sprite_palette_blink_c01ee3:
    lda a:$9C03,X
    .a8
    eor #$30
    sta a:$9C03,X
    inx
    inx
    inx
    inx
    dey
    bne tick_native_menu_actor_sprite_palette_blink_c01ee3
    .a8
    lda #$0A
    sta a:$A19F
    .a8
    lda #$04
    tsb a:$A20A
tick_native_menu_actor_sprite_palette_blink_c01efc:
    rts
