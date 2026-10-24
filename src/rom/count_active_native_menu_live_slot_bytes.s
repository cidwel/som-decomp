; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-publication.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $29FC
count_active_native_menu_live_slot_bytes:
    phx
    .i16
    ldx #$0000
    .i16
    ldy #$0000
count_active_native_menu_live_slot_bytes_c02a03:
    lda a:$CF90,X
    inx
    .a8
    cmp #$01
    bne count_active_native_menu_live_slot_bytes_c02a0c
    iny
count_active_native_menu_live_slot_bytes_c02a0c:
    .i16
    cpx #$0008
    bne count_active_native_menu_live_slot_bytes_c02a03
    tya
    plx
    rtl
