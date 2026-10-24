; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CCF5
restore_saved_map_snapshot:
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$30
    .i16
    ldx #$00FE
restore_saved_map_snapshot_c1cd01:
    lda a:$CE00,X
    sta a:$CD00,X
    dex
    dex
    bpl restore_saved_map_snapshot_c1cd01
    lda a:$CD08
    sta $DC
    .a16
    lda #$0000
    sta $DF
    plb
    rtl
