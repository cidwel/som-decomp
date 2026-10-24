; Recovered Secret of Mana USA routine; behaviour documented in docs/map-main-frame-menu-bridge.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CB82
select_scene_bank_and_update_ring_sprite_shadow_priority:
    sep #$20
    .a8
    lda #$7E
    pha
    plb
