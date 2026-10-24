; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-palette-graphics.md.
.setcpu "65816"
.smart
.a8
.i16

select_event_menu_palette_slot_long = $C070DF

.segment "CODE"
.org $CDB2
copy_selected_menu_actor_palette_with_mode7_product:
    rep #$30
    ldx a:$183E
    sep #$20
    lda f:$7EE180,X
    sta a:$185B
    sta a:$211B
    stz a:$211B
    .a8
    lda #$1E
    sta a:$211C
    ldx a:$2134
    sta a:$211C
    rep #$20
    .a16
    lda #$0000
    jsl f:select_event_menu_palette_slot_long
    rep #$20
    .a16
    and #$00FF
    xba
    asl
    tay
    .a16
    lda #$0010
copy_selected_menu_actor_palette_with_mode7_product_d0cde5:
    pha
    lda f:$C81000,X
    phx
    tyx
    sta a:$0702,X
    plx
    inx
    inx
    iny
    iny
    pla
    dec
    bne copy_selected_menu_actor_palette_with_mode7_product_d0cde5
    rts
