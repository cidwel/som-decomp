; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-geometry.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6D37
choose_next_native_menu_ring_row_with_directional_wrap:
    sep #$30
    ldx a:$180A
    dex
    lda a:$1806
    bmi choose_next_native_menu_ring_row_with_directional_wrap_c06d44
    inx
    inx
choose_next_native_menu_ring_row_with_directional_wrap_c06d44:
    txa
    cpx a:$180B
    bcc choose_next_native_menu_ring_row_with_directional_wrap_c06d54
    php
    .a8
    lda #$00
    plp
    bpl choose_next_native_menu_ring_row_with_directional_wrap_c06d54
    lda a:$180B
    dec
choose_next_native_menu_ring_row_with_directional_wrap_c06d54:
    rts
