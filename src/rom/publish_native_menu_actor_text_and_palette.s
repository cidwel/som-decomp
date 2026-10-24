; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-constructor.md.
.setcpu "65816"
.smart
.a8
.i16

select_wram_source_for_native_menu_palette_dma = $25FB
upload_native_menu_assembled_text_tiles = $23BA

.segment "CODE"
.org $2082
publish_native_menu_actor_text_and_palette:
    .i16
    ldx #$0120
    stx a:$A191
    .i16
    ldx #$61F0
    stx a:$A18C
    jsr upload_native_menu_assembled_text_tiles
    .a8
    lda #$18
    sta f:$002121
    .i16
    ldx #$A1A4
    stx a:$A194
    .i16
    ldx #$0010
    stx a:$A191
    jsr select_wram_source_for_native_menu_palette_dma
    rts
