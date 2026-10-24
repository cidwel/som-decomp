; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-effect-preparation.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CE11
initialize_event_radial_particle_workspace:
    rep #$20
    .i16
    ldx #$009E
initialize_event_radial_particle_workspace_c2ce16:
    lda f:$02CE21,X
    sta a:$F640,X
    dex
    bpl initialize_event_radial_particle_workspace_c2ce16
    rts
