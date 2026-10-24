; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-frames.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $28FF
await_native_menu_vblank_edge:
await_native_menu_vblank_edge_c028ff:
    lda f:$004212
    .a8
    and #$80
    bne await_native_menu_vblank_edge_c028ff
await_native_menu_vblank_edge_c02907:
    lda f:$004212
    .a8
    and #$80
    beq await_native_menu_vblank_edge_c02907
    rts
