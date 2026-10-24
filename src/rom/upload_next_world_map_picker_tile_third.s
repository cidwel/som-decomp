; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-scene.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A6F5
upload_next_world_map_picker_tile_third:
    stz a:$2115
    .a8
    lda #$7F
    sta a:$4374
    rep #$20
    .a16
    lda #$1800
    sta a:$4370
    .a16
    lda #$1556
    sta a:$4375
    dey
    bne upload_next_world_map_picker_tile_third_c0a713
    .a16
    lda #$0000
    bra upload_next_world_map_picker_tile_third_c0a727
upload_next_world_map_picker_tile_third_c0a713:
    dey
    bne upload_next_world_map_picker_tile_third_c0a71b
    .a16
    lda #$1555
    bra upload_next_world_map_picker_tile_third_c0a727
upload_next_world_map_picker_tile_third_c0a71b:
    .a16
    lda #$2AAA
    .i8
    ldx #$00
    stx a:$420C
    .i8
    ldx #$01
    stx $0D
upload_next_world_map_picker_tile_third_c0a727:
    sta a:$4372
    sta a:$2116
    .i8
    ldx #$80
    stx a:$420B
    rts
