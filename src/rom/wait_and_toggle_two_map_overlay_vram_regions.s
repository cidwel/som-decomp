; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-map-overlay-wait.md.
.setcpu "65816"
.smart
.a8
.i16

await_map_nmi_frame_request_two = $CFD5

.segment "CODE"
.org $CFE0
wait_and_toggle_two_map_overlay_vram_regions:
    xba
    jsr await_map_nmi_frame_request_two
    .a8
    lda #$80
    sta a:$2115
    rep #$10
    .i16
    ldy #$1801
    sty a:$4370
    xba
    lsr
    bcs wait_and_toggle_two_map_overlay_vram_regions_c2d029
    .i16
    ldy #$40B8
    sty a:$2116
    .i16
    ldy #$7FF0
    sty a:$4372
    .a8
    lda #$D2
    sta a:$4374
    .i16
    ldy #$0010
    sty a:$4375
    .a8
    lda #$80
    sta a:$420B
    .i16
    ldy #$4140
    sty a:$2116
    .i16
    ldy #$8100
    sty a:$4372
    .i16
    ldy #$0010
    sty a:$4375
    .a8
    lda #$80
    sta a:$420B
    rts
wait_and_toggle_two_map_overlay_vram_regions_c2d029:
    .i16
    ldy #$40B8
    sty a:$2116
    .i16
    ldy #$D057
    sty a:$4372
    .a8
    lda #$02
    sta a:$4374
    .i16
    ldy #$0010
    sty a:$4375
    .a8
    lda #$80
    sta a:$420B
    .i16
    ldy #$4140
    sty a:$2116
    .i16
    ldy #$0010
    sty a:$4375
    .a8
    lda #$80
    sta a:$420B
    rts
