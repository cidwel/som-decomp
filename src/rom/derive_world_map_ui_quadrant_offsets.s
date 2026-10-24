; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-scene.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9332
derive_world_map_ui_quadrant_offsets:
    sep #$30
    .a8
    lda #$02
    bit $01
    beq derive_world_map_ui_quadrant_offsets_c09340
    lsr $01
    bcc derive_world_map_ui_quadrant_offsets_c09356
    bcs derive_world_map_ui_quadrant_offsets_c0935f
derive_world_map_ui_quadrant_offsets_c09340:
    lsr $01
    bcs derive_world_map_ui_quadrant_offsets_c0934d
    .a8
    lda #$40
    sta $4C
    .a8
    lda #$00
    sta $4D
    rts
derive_world_map_ui_quadrant_offsets_c0934d:
    .a8
    lda #$C0
    sta $4C
    .a8
    lda #$80
    sta $4D
    rts
derive_world_map_ui_quadrant_offsets_c09356:
    .a8
    lda #$80
    sta $4C
    .a8
    lda #$C0
    sta $4D
    rts
derive_world_map_ui_quadrant_offsets_c0935f:
    .a8
    lda #$00
    sta $4C
    .a8
    lda #$40
    sta $4D
    rts
