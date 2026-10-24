; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-palette.md.
.setcpu "65816"
.smart
.a8
.i16

locate_native_menu_icon_palette_page = $CD18
request_menu_palette_upload = $CDA9

.segment "CODE"
.org $CC11
cycle_native_weapon_palette_every_third_menu_frame:
    sep #$20
    lda a:$1837
    inc
    .a8
    cmp #$03
    bcc cycle_native_weapon_palette_every_third_menu_frame_d0cc1d
    .a8
    lda #$00
cycle_native_weapon_palette_every_third_menu_frame_d0cc1d:
    sta a:$1837
    rep #$20
    bne cycle_native_weapon_palette_every_third_menu_frame_d0cc78
    lda a:$1820
    inc
    .a16
    cmp #$000A
    bcc cycle_native_weapon_palette_every_third_menu_frame_d0cc30
    .a16
    lda #$0000
cycle_native_weapon_palette_every_third_menu_frame_d0cc30:
    sta a:$1820
    asl
    tax
    lda f:$D9FEF4,X
    sta a:$1810
    .i16
    ldx #$8100
    .a16
    lda #$0003
cycle_native_weapon_palette_every_third_menu_frame_d0cc42:
    pha
    inx
    inx
    lda a:$1810
    sta f:$7E0000,X
    sta f:$7E000A,X
    sta f:$7E0014,X
    txa
    clc
    .a16
    adc #$001E
    tax
    pla
    dec
    bne cycle_native_weapon_palette_every_third_menu_frame_d0cc42
    jsr locate_native_menu_icon_palette_page
    tay
    .i16
    ldx #$0000
cycle_native_weapon_palette_every_third_menu_frame_d0cc65:
    lda f:$7E8100,X
    sta a:$0000,Y
    inx
    inx
    iny
    iny
    .i16
    cpx #$0080
    bcc cycle_native_weapon_palette_every_third_menu_frame_d0cc65
    jsr request_menu_palette_upload
cycle_native_weapon_palette_every_third_menu_frame_d0cc78:
    rts
