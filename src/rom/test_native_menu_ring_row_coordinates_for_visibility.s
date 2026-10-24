; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-geometry.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6E8D
test_native_menu_ring_row_coordinates_for_visibility:
    lda $02,X
    .a16
    cmp #$0100
    bcs test_native_menu_ring_row_coordinates_for_visibility_c06e9d
    lda $04,X
    .a16
    cmp #$00E8
    bcs test_native_menu_ring_row_coordinates_for_visibility_c06e9d
    clc
    rts
test_native_menu_ring_row_coordinates_for_visibility_c06e9d:
    sec
    rts
