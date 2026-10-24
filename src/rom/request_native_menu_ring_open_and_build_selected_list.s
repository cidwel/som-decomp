; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-waits.md.
.setcpu "65816"
.smart
.a8
.i16

build_native_menu_ring_list_without_initial_category_step = $6F72

.segment "CODE"
.org $6906
request_native_menu_ring_open_and_build_selected_list:
    rep #$20
    .a16
    lda #$0001
    sta a:$1812
    sta a:$1814
    jmp build_native_menu_ring_list_without_initial_category_step
