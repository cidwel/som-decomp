; Recovered Secret of Mana USA routine; behaviour documented in docs/cutscene-engine.md.
.setcpu "65816"
.smart
.a8
.i16

snapshot_map_scroll_and_actor_cache = $CBEA

.segment "CODE"
.org $CBCF
snapshot_map_state_and_backup:
    jsr snapshot_map_scroll_and_actor_cache
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$30
    .i16
    ldx #$00FE
snapshot_map_state_and_backup_c1cbde:
    lda a:$CD00,X
    sta a:$CE00,X
    dex
    dex
    bpl snapshot_map_state_and_backup_c1cbde
    plb
    rtl
