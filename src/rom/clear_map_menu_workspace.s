; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

reset_map_menu_state = $C00EBF

.segment "CODE"
.org $1063
clear_map_menu_workspace:
    .a8
    lda #$00
    sta f:$001D04
    sta f:$001D00
    sta f:$001D12
    php
    sep #$20
    rep #$10
    phb
    .a8
    lda #$7E
    pha
    plb
    .i16
    ldx #$0536
clear_map_menu_workspace_c0107e:
    stz a:$9BFF,X
    dex
    bne clear_map_menu_workspace_c0107e
    lda f:$001D04
    .a8
    ora #$44
    sta f:$001D04
    stz a:$A187
    jsl f:reset_map_menu_state
    plb
    plp
    rtl
