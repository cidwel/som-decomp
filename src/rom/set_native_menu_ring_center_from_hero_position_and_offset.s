; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-list-geometry.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $7134
set_native_menu_ring_center_from_hero_position_and_offset:
    lda f:$7EE020,X
    sec
    .a16
    sbc #$0008
    sta a:$181A
    phy
    lda f:$7EE022,X
    clc
    adc $01,S
    sta a:$181C
    ply
    rts
