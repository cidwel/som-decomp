; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $E2E5
clear_party_hud_tilemap:
    sep #$20
    .a8
    lda #$80
    sta a:$2115
    rep #$30
    .a16
    lda #$5B20
    sta a:$2116
    .i16
    ldy #$0060
clear_party_hud_tilemap_c1e2f7:
    stz a:$2118
    dey
    bne clear_party_hud_tilemap_c1e2f7
    rts
