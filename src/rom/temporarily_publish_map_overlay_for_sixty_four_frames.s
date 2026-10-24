; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-map-overlay-wait.md.
.setcpu "65816"
.smart
.a8
.i16

await_map_nmi_frame_request_two = $CFD5
wait_and_toggle_two_map_overlay_vram_regions = $CFE0

.segment "CODE"
.org $CFB8
temporarily_publish_map_overlay_for_sixty_four_frames:
    sep #$20
    phb
    .a8
    lda #$00
    pha
    plb
    .a8
    lda #$01
    jsr wait_and_toggle_two_map_overlay_vram_regions
    .a8
    lda #$40
temporarily_publish_map_overlay_for_sixty_four_frames_c2cfc6:
    xba
    jsr await_map_nmi_frame_request_two
    xba
    dec
    bne temporarily_publish_map_overlay_for_sixty_four_frames_c2cfc6
    .a8
    lda #$00
    jsr wait_and_toggle_two_map_overlay_vram_regions
    plb
    rtl
