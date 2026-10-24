; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-controller.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1F18
select_native_menu_actor_sprite_span:
    lda a:$A212
    .a8
    bit #$20
    beq select_native_menu_actor_sprite_span_c01f23
    .a8
    lda #$03
    bra select_native_menu_actor_sprite_span_c01f27
select_native_menu_actor_sprite_span_c01f23:
    lda f:$0019FE
select_native_menu_actor_sprite_span_c01f27:
    asl
    tax
    lda f:$C02A58,X
    pha
    lda f:$C02A59,X
    tay
    pla
    tax
    rts
