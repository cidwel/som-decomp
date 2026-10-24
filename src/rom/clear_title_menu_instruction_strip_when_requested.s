; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-controller.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2985
clear_title_menu_instruction_strip_when_requested:
    lda a:$A202
    .a8
    cmp #$09
    bne clear_title_menu_instruction_strip_when_requested_c029a4
    lda f:$0019FE
    bne clear_title_menu_instruction_strip_when_requested_c029a4
    .i16
    ldx #$0068
    .i16
    ldy #$0014
    .a8
    lda #$14
clear_title_menu_instruction_strip_when_requested_c0299a:
    sta a:$9000,X
    sta a:$9040,X
    inx
    dey
    bne clear_title_menu_instruction_strip_when_requested_c0299a
clear_title_menu_instruction_strip_when_requested_c029a4:
    rts
