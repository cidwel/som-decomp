; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6BE2
calculate_wrapped_native_menu_row_index:
    sep #$20
    lda a:$180A
    clc
    adc a:$182E
    cmp a:$180B
    bcc calculate_wrapped_native_menu_row_index_c06bf4
    sec
    sbc a:$180B
calculate_wrapped_native_menu_row_index_c06bf4:
    sta a:$1835
    rtl
