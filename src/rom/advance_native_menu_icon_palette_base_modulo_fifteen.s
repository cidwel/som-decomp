; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-icon-upload.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C9FC
advance_native_menu_icon_palette_base_modulo_fifteen:
    sep #$20
    lda a:$1810
    clc
    .a8
    adc #$05
    .a8
    cmp #$0F
    bcc advance_native_menu_icon_palette_base_modulo_fifteen_d0ca0a
    .a8
    lda #$00
advance_native_menu_icon_palette_base_modulo_fifteen_d0ca0a:
    sta a:$1810
    rep #$30
    rts
