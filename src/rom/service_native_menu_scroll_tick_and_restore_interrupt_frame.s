; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-interrupt.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $20A7
service_native_menu_scroll_tick_and_restore_interrupt_frame:
    phx
    phy
    phb
    pha
    php
    sep #$20
    .a8
    lda #$7E
    pha
    plb
    lda f:$004210
    lda a:$A20C
    inc
    sta a:$A20C
    .a8
    and #$03
    bne service_native_menu_scroll_tick_and_restore_interrupt_frame_c020de
    lda a:$A20B
    inc
    sta a:$A20B
    pha
    sta f:$00210D
    .a8
    lda #$00
    sta f:$00210D
    pla
    sta f:$00210E
    .a8
    lda #$00
    sta f:$00210E
service_native_menu_scroll_tick_and_restore_interrupt_frame_c020de:
    plp
    pla
    plb
    ply
    plx
    rti
