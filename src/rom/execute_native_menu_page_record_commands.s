; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-page-records.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2443
execute_native_menu_page_record_commands:
    ldx a:$A20D
    inx
    inx
    phb
    .a8
    lda #$C7
    pha
    plb
    ldy a:$0000,X
execute_native_menu_page_record_commands_c02450:
    .a8
    lda #$F7
    and f:$7EA20A
    sta f:$7EA20A
    .a8
    lda #$00
    xba
    lda a:$0000,Y
    beq execute_native_menu_page_record_commands_c0248d
    iny
    pha
    .a8
    and #$80
    beq execute_native_menu_page_record_commands_c02472
    .a8
    lda #$18
    ora f:$7EA20A
    sta f:$7EA20A
execute_native_menu_page_record_commands_c02472:
    pla
    .a8
    bit #$40
    beq execute_native_menu_page_record_commands_c02483
    pha
    .a8
    lda #$20
    ora f:$7EA20A
    sta f:$7EA20A
    pla
execute_native_menu_page_record_commands_c02483:
    .a8
    and #$1F
    dec
    asl
    tax
    jsr ($2A68,X)
    bra execute_native_menu_page_record_commands_c02450
execute_native_menu_page_record_commands_c0248d:
    plb
    rts
