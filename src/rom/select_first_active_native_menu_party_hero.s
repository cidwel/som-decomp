; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-page-graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5DDC
select_first_active_native_menu_party_hero:
    .i16
    ldx #$0000
select_first_active_native_menu_party_hero_c75ddf:
    .a8
    lda #$80
    and f:$0000D9,X
    bne select_first_active_native_menu_party_hero_c75df0
    inx
    .i16
    cpx #$0003
    bne select_first_active_native_menu_party_hero_c75ddf
    .i16
    ldx #$0000
select_first_active_native_menu_party_hero_c75df0:
    txa
    sta a:$A220
    sta f:$0019FD
    rts
