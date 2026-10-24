; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16

render_complete_menu_price_or_armor_selection_description = $D822

.segment "CODE"
.org $D5F3
dispatch_native_menu_second_line_description:
    sep #$30
    lda a:$1847
    beq dispatch_native_menu_second_line_description_d0d5fd
    jmp render_complete_menu_price_or_armor_selection_description
dispatch_native_menu_second_line_description_d0d5fd:
    .a8
    lda #$20
    bit a:$1803
    bne dispatch_native_menu_second_line_description_d0d60b
    lda a:$19D3
    .a8
    cmp #$9B
    bne dispatch_native_menu_second_line_description_d0d60c
dispatch_native_menu_second_line_description_d0d60b:
    rts
dispatch_native_menu_second_line_description_d0d60c:
    lda a:$1809
    asl
    tax
    rep #$30
    jmp ($D616,X)
