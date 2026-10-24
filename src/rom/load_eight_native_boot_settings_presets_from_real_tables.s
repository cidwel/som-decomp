; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-boot-menu-workspace.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0E8D
load_eight_native_boot_settings_presets_from_real_tables:
    .a8
    lda #$08
    sta a:$A175
    .i16
    ldx #$0000
    .i16
    ldy #$0000
load_eight_native_boot_settings_presets_from_real_tables_c00e98:
    phx
    .a8
    lda #$00
    xba
    lda f:$C77161,X
    asl
    sta a:$A173
    asl
    clc
    adc a:$A173
    tax
    rep #$20
    lda f:$D2DB82,X
    sta a:$A23E,Y
    plx
    sep #$20
    iny
    iny
    inx
    dec a:$A175
    bne load_eight_native_boot_settings_presets_from_real_tables_c00e98
    rts
