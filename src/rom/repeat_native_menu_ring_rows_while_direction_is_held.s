; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-rows.md.
.setcpu "65816"
.smart
.a8
.i16

project_and_publish_all_native_menu_ring_rows = $6D1C
wait_vblank_before_polling_native_menu_input = $695E

.segment "CODE"
.org $6D55
repeat_native_menu_ring_rows_while_direction_is_held:
    rep #$20
    jsr project_and_publish_all_native_menu_ring_rows
repeat_native_menu_ring_rows_while_direction_is_held_c06d5a:
    sep #$20
    lda a:$1848
    beq repeat_native_menu_ring_rows_while_direction_is_held_c06d73
    dec a:$1848
    jsr wait_vblank_before_polling_native_menu_input
    sep #$20
    lda a:$1801
    .a8
    bit #$03
    bne repeat_native_menu_ring_rows_while_direction_is_held_c06d5a
    stz a:$1848
repeat_native_menu_ring_rows_while_direction_is_held_c06d73:
    rts
