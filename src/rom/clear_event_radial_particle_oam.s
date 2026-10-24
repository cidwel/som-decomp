; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-effect-preparation.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CD55
clear_event_radial_particle_oam:
    rep #$30
    .i16
    ldx #$004C
    .a16
    lda #$E0FF
clear_event_radial_particle_oam_c2cd5d:
    sta a:$0900,X
    dex
    dex
    dex
    dex
    bpl clear_event_radial_particle_oam_c2cd5d
    rts
