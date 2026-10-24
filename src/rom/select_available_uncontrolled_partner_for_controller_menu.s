; Recovered Secret of Mana USA routine; behaviour documented in docs/map-main-frame-partner-selection.md.
.setcpu "65816"
.smart
.a8
.i16

test_partner_actor_active_uncontrolled_and_status_available = $A9F4

.segment "CODE"
.org $A943
select_available_uncontrolled_partner_for_controller_menu:
    lda $D9,X
    .a8
    and #$06
    xba
    .a8
    lda #$00
    rep #$10
    tay
    .i16
    cpy #$0000
    beq select_available_uncontrolled_partner_for_controller_menu_c2a9b7
    .i16
    cpy #$0200
    beq select_available_uncontrolled_partner_for_controller_menu_c2a986
    stz $00
    .i16
    ldx #$0000
    jsr test_partner_actor_active_uncontrolled_and_status_available
    bcs select_available_uncontrolled_partner_for_controller_menu_c2a963
    inc $00
select_available_uncontrolled_partner_for_controller_menu_c2a963:
    .i16
    ldx #$0200
    jsr test_partner_actor_active_uncontrolled_and_status_available
    bcs select_available_uncontrolled_partner_for_controller_menu_c2a96f
    inc $00
    inc $00
select_available_uncontrolled_partner_for_controller_menu_c2a96f:
    lda $00
    beq select_available_uncontrolled_partner_for_controller_menu_c2a9b5
    .a8
    cmp #$01
    beq select_available_uncontrolled_partner_for_controller_menu_c2a9ec
    .a8
    cmp #$02
    beq select_available_uncontrolled_partner_for_controller_menu_c2a9e8
    lda $BE
    .a8
    eor #$01
    sta $BE
    lsr
    bcs select_available_uncontrolled_partner_for_controller_menu_c2a9ec
    bcc select_available_uncontrolled_partner_for_controller_menu_c2a9e8
select_available_uncontrolled_partner_for_controller_menu_c2a986:
    stz $00
    .i16
    ldx #$0000
    jsr test_partner_actor_active_uncontrolled_and_status_available
    bcs select_available_uncontrolled_partner_for_controller_menu_c2a992
    inc $00
select_available_uncontrolled_partner_for_controller_menu_c2a992:
    .i16
    ldx #$0400
    jsr test_partner_actor_active_uncontrolled_and_status_available
    bcs select_available_uncontrolled_partner_for_controller_menu_c2a99e
    inc $00
    inc $00
select_available_uncontrolled_partner_for_controller_menu_c2a99e:
    lda $00
    beq select_available_uncontrolled_partner_for_controller_menu_c2a9b5
    .a8
    cmp #$01
    beq select_available_uncontrolled_partner_for_controller_menu_c2a9ec
    .a8
    cmp #$02
    beq select_available_uncontrolled_partner_for_controller_menu_c2a9e4
    lda $BE
    .a8
    eor #$01
    sta $BE
    lsr
    bcs select_available_uncontrolled_partner_for_controller_menu_c2a9ec
    bcc select_available_uncontrolled_partner_for_controller_menu_c2a9e4
select_available_uncontrolled_partner_for_controller_menu_c2a9b5:
    sec
    rtl
select_available_uncontrolled_partner_for_controller_menu_c2a9b7:
    stz $00
    .i16
    ldx #$0200
    jsr test_partner_actor_active_uncontrolled_and_status_available
    bcs select_available_uncontrolled_partner_for_controller_menu_c2a9c3
    inc $00
select_available_uncontrolled_partner_for_controller_menu_c2a9c3:
    .i16
    ldx #$0400
    jsr test_partner_actor_active_uncontrolled_and_status_available
    bcs select_available_uncontrolled_partner_for_controller_menu_c2a9cf
    inc $00
    inc $00
select_available_uncontrolled_partner_for_controller_menu_c2a9cf:
    lda $00
    beq select_available_uncontrolled_partner_for_controller_menu_c2a9b5
    .a8
    cmp #$01
    beq select_available_uncontrolled_partner_for_controller_menu_c2a9e8
    .a8
    cmp #$02
    beq select_available_uncontrolled_partner_for_controller_menu_c2a9e4
    lda $BE
    .a8
    eor #$01
    sta $BE
    lsr
    bcs select_available_uncontrolled_partner_for_controller_menu_c2a9e8
select_available_uncontrolled_partner_for_controller_menu_c2a9e4:
    .a8
    lda #$04
    bra select_available_uncontrolled_partner_for_controller_menu_c2a9ee
select_available_uncontrolled_partner_for_controller_menu_c2a9e8:
    .a8
    lda #$02
    bra select_available_uncontrolled_partner_for_controller_menu_c2a9ee
select_available_uncontrolled_partner_for_controller_menu_c2a9ec:
    .a8
    lda #$00
select_available_uncontrolled_partner_for_controller_menu_c2a9ee:
    xba
    .a8
    lda #$00
    tax
    clc
    rtl
