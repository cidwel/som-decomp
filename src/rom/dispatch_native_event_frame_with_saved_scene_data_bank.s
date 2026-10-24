; Recovered Secret of Mana USA routine; behaviour documented in docs/map-main-frame-menu-bridge.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_event_opcode_or_wait_state = $E8D3

.segment "CODE"
.org $E8C7
dispatch_native_event_frame_with_saved_scene_data_bank:
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    jsr dispatch_native_event_opcode_or_wait_state
    plb
    rtl
