; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-constructor.md.
.setcpu "65816"
.smart
.a8
.i16

snapshot_tile_attributes_and_apply_character_row_exchange = $FA10

.segment "CODE"
.org $F83C
expand_packed_scene_tile_attributes_and_snapshot_vram:
    sep #$30
    .i8
    ldx #$00
    txy
expand_packed_scene_tile_attributes_and_snapshot_vram_c1f841:
    lda f:$C67D80,X
    pha
    asl
    asl
    asl
    asl
    sta a:$0600,Y
    iny
    pla
    .a8
    and #$F0
    sta a:$0600,Y
    inx
    iny
    bne expand_packed_scene_tile_attributes_and_snapshot_vram_c1f841
    lda a:$0600
    sta $04
    .a8
    lda #$00
    tay
    sta $03
    sta $00
    sta $01
    sta a:$2116
    sta a:$2117
    .a8
    lda #$C6
    sta $02
    .a8
    lda #$80
    sta a:$2115
    .i8
    ldx #$20
expand_packed_scene_tile_attributes_and_snapshot_vram_c1f877:
    lda [$00],Y
    pha
    .a8
    and #$0F
    ora $04
    sta a:$2119
    pla
    lsr
    lsr
    lsr
    lsr
    ora $04
    sta a:$2119
    dex
    bne expand_packed_scene_tile_attributes_and_snapshot_vram_c1f899
    inc $03
    ldx $03
    lda a:$0600,X
    sta $04
    .i8
    ldx #$20
expand_packed_scene_tile_attributes_and_snapshot_vram_c1f899:
    iny
    bne expand_packed_scene_tile_attributes_and_snapshot_vram_c1f877
    inc $01
    lda $01
    .a8
    cmp #$20
    bcc expand_packed_scene_tile_attributes_and_snapshot_vram_c1f877
    jmp snapshot_tile_attributes_and_apply_character_row_exchange
