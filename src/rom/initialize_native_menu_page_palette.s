; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-constructor.md.
.setcpu "65816"
.smart
.a8
.i16

override_native_menu_page_four_five_colors = $212F
select_wram_source_for_native_menu_palette_dma = $25FB

.segment "CODE"
.org $20E4
initialize_native_menu_page_palette:
    pha
    lda f:$C7FBE0
    sta a:$9000
    lda f:$C7FBE1
    sta a:$9001
    .i16
    ldx #$0000
    .i16
    ldy #$0002
    .a8
    lda #$0A
    sta a:$A171
initialize_native_menu_page_palette_c020fe:
    .a8
    lda #$06
initialize_native_menu_page_palette_c02100:
    xba
    lda f:$D2DBC0,X
    sta a:$9000,Y
    inx
    iny
    xba
    dec
    bne initialize_native_menu_page_palette_c02100
    iny
    iny
    dec a:$A171
    bne initialize_native_menu_page_palette_c020fe
    pla
    jsr override_native_menu_page_four_five_colors
    .a8
    lda #$00
    sta f:$002121
    .i16
    ldx #$9000
    stx a:$A194
    .i16
    ldx #$0040
    stx a:$A191
    jsr select_wram_source_for_native_menu_palette_dma
    rts
