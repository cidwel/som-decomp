; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-constructor.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B75E
conditionally_upload_scene_overlay_graphics_and_palette:
    sep #$20
    lda $8C
    beq conditionally_upload_scene_overlay_graphics_and_palette_c2b76a
    lda $E3
    .a8
    and #$06
    beq conditionally_upload_scene_overlay_graphics_and_palette_c2b7a3
conditionally_upload_scene_overlay_graphics_and_palette_c2b76a:
    rep #$10
    .a8
    lda #$80
    sta a:$2115
    .i16
    ldx #$7800
    stx a:$2116
    .i16
    ldx #$1801
    stx a:$4370
    .i16
    ldx #$B8D6
    stx a:$4372
    .a8
    lda #$C2
    sta a:$4374
    .i16
    ldx #$0200
    stx a:$4375
    .a8
    lda #$80
    sta a:$420B
    .i16
    ldx #$001E
    rep #$20
conditionally_upload_scene_overlay_graphics_and_palette_c2b798:
    lda f:$02B7BC,X
    sta a:$07E2,X
    dex
    dex
    bpl conditionally_upload_scene_overlay_graphics_and_palette_c2b798
conditionally_upload_scene_overlay_graphics_and_palette_c2b7a3:
    rtl
