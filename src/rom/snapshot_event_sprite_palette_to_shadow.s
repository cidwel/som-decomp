; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-actor-selection.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $AB42
snapshot_event_sprite_palette_to_shadow:
    rep #$30
    phy
    .i16
    ldy #$00FE
snapshot_event_sprite_palette_to_shadow_c2ab48:
    lda a:$0700,Y
    sta a:$C600,Y
    dey
    dey
    bpl snapshot_event_sprite_palette_to_shadow_c2ab48
    ply
    rtl
