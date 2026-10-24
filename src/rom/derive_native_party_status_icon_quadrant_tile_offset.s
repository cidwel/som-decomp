; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-art.md.
.setcpu "65816"
.smart
.a8
.i16

publish_four_native_party_status_icon_tiles_and_coordinates = $63C5

.segment "CODE"
.org $63AD
derive_native_party_status_icon_quadrant_tile_offset:
    tya
    .a8
    and #$0E
    sta a:$A17F
    tya
    .a8
    and #$01
    beq derive_native_party_status_icon_quadrant_tile_offset_c763ba
    .a8
    lda #$04
derive_native_party_status_icon_quadrant_tile_offset_c763ba:
    clc
    adc a:$A17E
    sta a:$A17E
    jsr publish_four_native_party_status_icon_tiles_and_coordinates
    rts
