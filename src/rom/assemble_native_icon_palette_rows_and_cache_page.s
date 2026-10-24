; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-icon-palette.md.
.setcpu "65816"
.smart
.a8
.i16

append_one_native_icon_palette_color = $CBBF
cache_selected_native_menu_icon_palette_page = $CBD6
read_native_icon_color_or_disabled_row_color = $CBA2
request_menu_palette_upload = $CDA9

.segment "CODE"
.org $CB2F
assemble_native_icon_palette_rows_and_cache_page:
    txa
    sta a:$1822
    .i16
    ldy #$0000
    lda a:$180B
    .a16
    and #$00FF
assemble_native_icon_palette_rows_and_cache_page_d0cb3c:
    pha
    tya
    asl
    clc
    .a16
    adc #$1880
    tax
    clc
    .a16
    adc #$0020
    sta a:$1820
    lda $00,X
    .a16
    cmp #$FFFF
    beq assemble_native_icon_palette_rows_and_cache_page_d0cb76
    xba
    .a16
    and #$00FF
    pha
    asl
    asl
    clc
    adc $01,S
    asl
    tax
    pla
    rep #$20
    .i16
    cpy #$0003
    beq assemble_native_icon_palette_rows_and_cache_page_d0cb70
    .i16
    cpy #$0006
    beq assemble_native_icon_palette_rows_and_cache_page_d0cb70
    .i16
    cpy #$0009
    bne assemble_native_icon_palette_rows_and_cache_page_d0cb76
assemble_native_icon_palette_rows_and_cache_page_d0cb70:
    .a16
    lda #$0000
    jsr append_one_native_icon_palette_color
assemble_native_icon_palette_rows_and_cache_page_d0cb76:
    phx
    ldx a:$1820
    lda $00,X
    .a16
    and #$4000
    beq assemble_native_icon_palette_rows_and_cache_page_d0cb86
    .a16
    lda #$0000
    sta $01,S
assemble_native_icon_palette_rows_and_cache_page_d0cb86:
    plx
    jsr read_native_icon_color_or_disabled_row_color
    jsr read_native_icon_color_or_disabled_row_color
    jsr read_native_icon_color_or_disabled_row_color
    jsr read_native_icon_color_or_disabled_row_color
    jsr read_native_icon_color_or_disabled_row_color
    iny
    pla
    dec
    bne assemble_native_icon_palette_rows_and_cache_page_d0cb3c
    jsr request_menu_palette_upload
    jsr cache_selected_native_menu_icon_palette_page
    rtl
