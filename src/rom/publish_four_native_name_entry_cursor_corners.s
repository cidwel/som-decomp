; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-name-helpers.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_name_entry_oam_corner = $5148

.segment "CODE"
.org $503D
publish_four_native_name_entry_cursor_corners:
    ldy a:$A159
    sty a:$A173
    .i16
    ldx #$0000
    .i16
    ldy #$B021
    jsr append_native_name_entry_oam_corner
    lda a:$A173
    clc
    .a8
    adc #$0E
    sta a:$A173
    .i16
    ldy #$F021
    jsr append_native_name_entry_oam_corner
    lda a:$A174
    clc
    .a8
    adc #$08
    sta a:$A174
    .i16
    ldy #$7021
    jsr append_native_name_entry_oam_corner
    lda a:$A173
    sec
    .a8
    sbc #$0E
    sta a:$A173
    .i16
    ldy #$3021
    jsr append_native_name_entry_oam_corner
    .a8
    lda #$04
    tsb a:$A20A
    rtl
