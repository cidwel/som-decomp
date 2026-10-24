; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-menu-caller.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0FAA
clear_direct_page_and_party_workspace_before_load_game_menu:
    .i16
    ldx #$0000
clear_direct_page_and_party_workspace_before_load_game_menu_c00fad:
    stz $00,X
    inx
    .i16
    cpx #$0100
    bne clear_direct_page_and_party_workspace_before_load_game_menu_c00fad
    phb
    .a8
    lda #$7E
    pha
    plb
    .i16
    ldx #$0600
clear_direct_page_and_party_workspace_before_load_game_menu_c00fbd:
    stz a:$DFFF,X
    dex
    bne clear_direct_page_and_party_workspace_before_load_game_menu_c00fbd
    .i16
    ldx #$0080
clear_direct_page_and_party_workspace_before_load_game_menu_c00fc6:
    stz a:$CBFF,X
    dex
    bne clear_direct_page_and_party_workspace_before_load_game_menu_c00fc6
    .a8
    lda #$01
    sta $D9
    sta a:$E000
    plb
    rts
