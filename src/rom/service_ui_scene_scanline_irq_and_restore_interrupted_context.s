; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-interrupts.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8A4B
service_ui_scene_scanline_irq_and_restore_interrupted_context:
    sep #$20
    pha
    phb
    .a8
    lda #$00
    pha
    plb
    lda a:$4211
    lda a:$00F2
    bmi service_ui_scene_scanline_irq_and_restore_interrupted_context_c08a76
    rep #$10
    phx
    phy
    sep #$10
    .a8
    lda #$07
    ldx a:$003A
    ldy a:$003B
    sta a:$2105
    stx a:$210D
    sty a:$210D
    rep #$10
    ply
    plx
service_ui_scene_scanline_irq_and_restore_interrupted_context_c08a76:
    plb
    pla
    rti
