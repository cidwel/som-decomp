; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-palette-transition.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C806
snapshot_palette_for_event_color_transition:
    rep #$10
    .i16
    ldx #$01FE
    rep #$20
snapshot_palette_for_event_color_transition_c2c80d:
    lda a:$0600,X
    sta a:$BE00,X
    dex
    dex
    bpl snapshot_palette_for_event_color_transition_c2c80d
    lda a:$0600
    sta a:$0620
    sep #$30
    rtl
