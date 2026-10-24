; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

clear_party_hud_tilemap = $E2E5

.segment "CODE"
.org $E2BC
scan_party_hud_with_stalled_index:
    sep #$20
    rep #$10
    phb
    .a8
    lda #$7E
    pha
    plb
    .i16
    ldx #$0000
scan_party_hud_with_stalled_index_c1e2c8:
    lda a:$E000,X
    beq scan_party_hud_with_stalled_index_c1e2d7
    bmi scan_party_hud_with_stalled_index_c1e2d7
    lda a:$E02C,X
    bne scan_party_hud_with_stalled_index_c1e2d7
    jsr clear_party_hud_tilemap
scan_party_hud_with_stalled_index_c1e2d7:
    rep #$20
    txa
    clc
    .a16
    adc #$0200
    .a16
    cmp #$0600
    bcc scan_party_hud_with_stalled_index_c1e2c8
    plb
    rts
