; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-palette-exchange.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C7DD
exchange_native_scene_and_event_transition_palettes_when_active:
    sep #$20
    lda $2A
    bne exchange_native_scene_and_event_transition_palettes_when_active_c2c7e4
    rtl
exchange_native_scene_and_event_transition_palettes_when_active_c2c7e4:
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$30
    phy
    .i16
    ldy #$01FE
exchange_native_scene_and_event_transition_palettes_when_active_c2c7ef:
    lda a:$BE00,Y
    pha
    lda a:$0600,Y
    sta a:$BE00,Y
    pla
    sta a:$0600,Y
    dey
    dey
    bpl exchange_native_scene_and_event_transition_palettes_when_active_c2c7ef
    ply
    sep #$20
    plb
    rtl
