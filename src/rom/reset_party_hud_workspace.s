; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $E2FE
reset_party_hud_workspace:
    sep #$10
    rep #$20
    .i8
    ldx #$2E
    .a16
    lda #$0000
reset_party_hud_workspace_c1e307:
    sta a:$0A50,X
    dex
    bpl reset_party_hud_workspace_c1e307
    sep #$20
    .a8
    lda #$17
    sta a:$0A56
    sta a:$0A66
    sta a:$0A76
    .a8
    lda #$28
    sta a:$0A57
    sta a:$0A67
    sta a:$0A77
    rts
