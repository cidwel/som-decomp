; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-navigation-icons.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6740
request_native_menu_vertical_inventory_transition:
    sep #$30
    lda a:$1806
    bne request_native_menu_vertical_inventory_transition_c06774
    lda a:$1803
    .a8
    bit #$80
    bne request_native_menu_vertical_inventory_transition_c06774
    rep #$10
    lda a:$1801
    .i16
    ldx #$0001
    .i16
    ldy #$0002
    .a8
    bit #$08
    bne request_native_menu_vertical_inventory_transition_c06767
    .i16
    ldx #$FFFF
    .i16
    ldy #$0004
    .a8
    bit #$04
    beq request_native_menu_vertical_inventory_transition_c06774
request_native_menu_vertical_inventory_transition_c06767:
    tya
    sta a:$1812
    txa
    sta a:$1814
    .a8
    lda #$40
    trb a:$1803
request_native_menu_vertical_inventory_transition_c06774:
    rts
