; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-interrupts.md.
.setcpu "65816"
.smart
.a8
.i16

alternate_ui_scene_palettes_and_configure_window = $8A79
publish_requested_ui_scene_mode_and_scroll_state = $890B
publish_requested_ui_scene_tile_rows = $9840
upload_scene_oam_and_attribute_frame_buffers = $882B

.segment "CODE"
.org $88CF
service_ui_scene_frame_nmi_and_restore_interrupted_context:
    rep #$30
    pha
    phx
    phy
    phd
    phb
    sep #$10
    .i8
    ldx #$00
    phx
    plb
    ldx a:$4210
    .a16
    lda #$0000
    tcd
    .a16
    lda #$0000
    sta a:$212E
    ldx $E6
    stx a:$2100
    inc $F4
    jsr upload_scene_oam_and_attribute_frame_buffers
    jsr publish_requested_ui_scene_tile_rows
    jsr alternate_ui_scene_palettes_and_configure_window
    sep #$20
    lda $EC
    lsr
    bcc service_ui_scene_frame_nmi_and_restore_interrupted_context_c08903
    jsr publish_requested_ui_scene_mode_and_scroll_state
service_ui_scene_frame_nmi_and_restore_interrupted_context_c08903:
    rep #$30
    plb
    pld
    ply
    plx
    pla
    rti
