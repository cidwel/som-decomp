; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-navigation-icons.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $709C
add_native_menu_row_tile_segment_when_comparison_carries:
    bcc add_native_menu_row_tile_segment_when_comparison_carries_c070a2
    clc
    .a16
    adc #$0200
add_native_menu_row_tile_segment_when_comparison_carries_c070a2:
    rts
