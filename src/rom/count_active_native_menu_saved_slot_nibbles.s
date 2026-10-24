; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-publication.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2A14
count_active_native_menu_saved_slot_nibbles:
    .i16
    ldy #$0000
    .a8
    lda #$04
count_active_native_menu_saved_slot_nibbles_c02a19:
    xba
    lda f:$3060CB,X
    pha
    .a8
    and #$0F
    .a8
    cmp #$01
    bne count_active_native_menu_saved_slot_nibbles_c02a26
    iny
count_active_native_menu_saved_slot_nibbles_c02a26:
    pla
    .a8
    and #$F0
    .a8
    cmp #$10
    bne count_active_native_menu_saved_slot_nibbles_c02a2e
    iny
count_active_native_menu_saved_slot_nibbles_c02a2e:
    inx
    xba
    dec
    bne count_active_native_menu_saved_slot_nibbles_c02a19
    rtl
