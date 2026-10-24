; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-controller.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $28D9
close_title_menu_after_idle_input_timeout:
    lda a:$A202
    .a8
    cmp #$00
    bne close_title_menu_after_idle_input_timeout_c028fe
    lda a:$A203
    ora a:$A204
    bne close_title_menu_after_idle_input_timeout_c028f8
    ldy a:$A213
    iny
    .i16
    cpy #$0708
    bne close_title_menu_after_idle_input_timeout_c028fb
    .a8
    lda #$01
    tsb a:$A20A
    bra close_title_menu_after_idle_input_timeout_c028fe
close_title_menu_after_idle_input_timeout_c028f8:
    .i16
    ldy #$0000
close_title_menu_after_idle_input_timeout_c028fb:
    sty a:$A213
close_title_menu_after_idle_input_timeout_c028fe:
    rts
