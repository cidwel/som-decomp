; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-boot-menu-workspace.md.
.setcpu "65816"
.smart
.a8
.i16

load_eight_native_boot_settings_presets_from_real_tables = $0E8D

.segment "CODE"
.org $0E40
initialize_native_boot_menu_workspace_and_settings:
    php
    sep #$20
    rep #$10
    phb
    .a8
    lda #$00
    pha
    plb
    .a8
    lda #$30
    .a8
    lda #$00
initialize_native_boot_menu_workspace_and_settings_c00e4e:
    stz a:$1D00,X
    inx
    dec
    bne initialize_native_boot_menu_workspace_and_settings_c00e4e
    .a8
    lda #$01
    sta a:$1D1A
    .a8
    lda #$7E
    pha
    plb
    .i16
    ldy #$1260
    .i16
    ldx #$0000
initialize_native_boot_menu_workspace_and_settings_c00e64:
    stz a:$9000,X
    inx
    dey
    bne initialize_native_boot_menu_workspace_and_settings_c00e64
    jsr load_eight_native_boot_settings_presets_from_real_tables
    .i16
    ldx #$9C00
    stx a:$A19B
    .a8
    lda #$01
    sta a:$A1C6
    .a8
    lda #$06
    sta a:$A161
    .i16
    ldx #$0008
    .a8
    lda #$07
initialize_native_boot_menu_workspace_and_settings_c00e83:
    sta a:$A24E,X
    dec
    dex
    bne initialize_native_boot_menu_workspace_and_settings_c00e83
    plb
    plp
    rtl
