; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-navigation-icons.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $70A3
bind_native_menu_list_row_to_active_hero_oam_marker:
    rep #$30
    stz $0A,X
    phx
    tya
    asl
    tax
    lda a:$18A0,X
    sta a:$1810
    .a16
    and #$0003
    plx
    .a16
    ora #$0000
    beq bind_native_menu_list_row_to_active_hero_oam_marker_c070da
    dec
    asl
    pha
    xba
    phx
    tax
    lda f:$7EE000,X
    plx
    .a16
    and #$00FF
    dec
    beq bind_native_menu_list_row_to_active_hero_oam_marker_c070d0
    .a16
    lda #$0000
    bra bind_native_menu_list_row_to_active_hero_oam_marker_c070d7
bind_native_menu_list_row_to_active_hero_oam_marker_c070d0:
    lda $01,S
    asl
    clc
    .a16
    adc #$082C
bind_native_menu_list_row_to_active_hero_oam_marker_c070d7:
    sta $0A,X
    pla
bind_native_menu_list_row_to_active_hero_oam_marker_c070da:
    rts
