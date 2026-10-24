; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-palette.md.
.setcpu "65816"
.smart
.a8
.i16

locate_native_menu_icon_palette_page = $CD18
request_menu_palette_upload = $CDA9
rotate_one_native_enabled_equipment_row_palette = $CCD6
routine_d0cc78 = $CC78

.segment "CODE"
.org $CC79
rotate_native_packed_equipment_palettes_and_blink_rows:
    sep #$20
    lda a:$1838
    inc
    .a8
    cmp #$0C
    bcc rotate_native_packed_equipment_palettes_and_blink_rows_d0cc97
    rep #$20
    .i16
    ldx #$0000
    lda a:$1822
    bne rotate_native_packed_equipment_palettes_and_blink_rows_d0cc90
    .i16
    ldx #$0020
rotate_native_packed_equipment_palettes_and_blink_rows_d0cc90:
    stx a:$1822
    sep #$20
    .a8
    lda #$00
rotate_native_packed_equipment_palettes_and_blink_rows_d0cc97:
    sta a:$1838
    lda a:$1837
    inc
    .a8
    cmp #$06
    bcc rotate_native_packed_equipment_palettes_and_blink_rows_d0cca4
    .a8
    lda #$00
rotate_native_packed_equipment_palettes_and_blink_rows_d0cca4:
    sta a:$1837
    rep #$20
    bne routine_d0cc78
    .a16
    lda #$0000
    .i16
    ldx #$8102
    jsr rotate_one_native_enabled_equipment_row_palette
    jsr rotate_one_native_enabled_equipment_row_palette
    jsr rotate_one_native_enabled_equipment_row_palette
    jsr locate_native_menu_icon_palette_page
    rep #$20
    tay
    .i16
    ldx #$0000
rotate_native_packed_equipment_palettes_and_blink_rows_d0ccc3:
    lda f:$7E8100,X
    sta a:$0000,Y
    inx
    inx
    iny
    iny
    .i16
    cpx #$0020
    bcc rotate_native_packed_equipment_palettes_and_blink_rows_d0ccc3
    jmp request_menu_palette_upload
