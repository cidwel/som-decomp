; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-actor-selection.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $AB30
restore_event_sprite_palette_from_shadow:
    rep #$30
    phy
    .i16
    ldy #$00FE
restore_event_sprite_palette_from_shadow_c2ab36:
    lda a:$C600,Y
    sta a:$0700,Y
    dey
    dey
    bpl restore_event_sprite_palette_from_shadow_c2ab36
    ply
    rtl
