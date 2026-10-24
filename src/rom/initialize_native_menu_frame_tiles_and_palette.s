; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-constructor.md.
.setcpu "65816"
.smart
.a8
.i16

copy_four_native_menu_frame_tile_chunks = $205A
select_rom_source_for_native_menu_palette_dma = $25F7
select_rom_source_for_native_menu_tile_dma = $25C8
select_wram_source_for_native_menu_tile_dma = $25CC

.segment "CODE"
.org $1F97
initialize_native_menu_frame_tiles_and_palette:
    rep #$20
    .a16
    lda #$4000
    sta f:$002116
    .a16
    lda #$0400
    sta a:$A191
    .a16
    lda #$FC00
    sta a:$A194
    sep #$20
    jsr select_rom_source_for_native_menu_tile_dma
    .a8
    lda #$20
    sta f:$002121
    .i16
    ldx #$FBE0
    stx a:$A194
    .i16
    ldx #$0020
    stx a:$A191
    jsr select_rom_source_for_native_menu_palette_dma
    .i16
    ldy #$0000
    .a8
    lda #$08
    sta a:$A176
initialize_native_menu_frame_tiles_and_palette_c01fce:
    .a8
    lda #$08
    sta a:$A171
initialize_native_menu_frame_tiles_and_palette_c01fd3:
    phy
    jsr copy_four_native_menu_frame_tile_chunks
    rep #$20
    pla
    clc
    .a16
    adc #$0008
    tay
    sep #$20
    dec a:$A171
    bne initialize_native_menu_frame_tiles_and_palette_c01fd3
    rep #$20
    tya
    clc
    .a16
    adc #$00C0
    tay
    sep #$20
    dec a:$A176
    bne initialize_native_menu_frame_tiles_and_palette_c01fce
    rep #$20
    .a16
    lda #$4800
    sta f:$002116
    .a16
    lda #$0800
    sta a:$A191
    .a16
    lda #$9000
    sta a:$A194
    sep #$20
    jsr select_wram_source_for_native_menu_tile_dma
    rts
