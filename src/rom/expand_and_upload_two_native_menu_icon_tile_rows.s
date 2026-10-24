; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-icon-upload.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_four_native_menu_icon_tiles_from_original_graphics = $CA6E

.segment "CODE"
.org $C986
expand_and_upload_two_native_menu_icon_tile_rows:
    phx
    jsr prepare_four_native_menu_icon_tiles_from_original_graphics
    sep #$20
    lda a:$19F0
    .a8
    cmp #$C0
    beq expand_and_upload_two_native_menu_icon_tile_rows_d0c998
expand_and_upload_two_native_menu_icon_tile_rows_d0c993:
    lda a:$4212
    bpl expand_and_upload_two_native_menu_icon_tile_rows_d0c993
expand_and_upload_two_native_menu_icon_tile_rows_d0c998:
    rep #$20
    sep #$10
    lda a:$180C
    sta a:$2116
    .i8
    ldx #$01
    stx a:$4350
    .i8
    ldx #$18
    stx a:$4351
    .a16
    lda #$1900
    sta a:$4352
    .i8
    ldx #$00
    stx a:$4354
    .a16
    lda #$0040
    sta a:$4355
    .i8
    ldx #$20
    stx a:$420B
    lda a:$180C
    clc
    .a16
    adc #$0100
    sta a:$2116
    .i8
    ldx #$01
    stx a:$4350
    .i8
    ldx #$18
    stx a:$4351
    .a16
    lda #$1940
    sta a:$4352
    .i8
    ldx #$00
    stx a:$4354
    .a16
    lda #$0040
    sta a:$4355
    .i8
    ldx #$20
    stx a:$420B
    rep #$30
    lda a:$180C
    clc
    .a16
    adc #$0020
    sta a:$180C
    plx
    inx
    inx
    rts
