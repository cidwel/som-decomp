; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-scene.md.
.setcpu "65816"
.smart
.a8
.i16

advance_world_map_picker_brightness_counter = $A6D4
publish_world_map_picker_matrix_when_rows_are_complete = $A691
routine_02a801 = $2A801
upload_next_world_map_picker_tile_third = $A6F5

.segment "CODE"
.org $A64A
service_complete_temporary_world_map_picker_nmi:
    rep #$30
    pha
    phx
    phy
    phd
    phb
    sep #$30
    lda f:$004210
    .a8
    lda #$00
    pha
    plb
    rep #$20
    .a16
    lda #$0000
    tcd
    lda $F4
    inc
    sta $F4
    jsl f:routine_02a801
    sep #$20
    lda $0D
    beq service_complete_temporary_world_map_picker_nmi_c0a679
    lda $0C
    beq service_complete_temporary_world_map_picker_nmi_c0a679
    jsr advance_world_map_picker_brightness_counter
    bra service_complete_temporary_world_map_picker_nmi_c0a686
service_complete_temporary_world_map_picker_nmi_c0a679:
    lda $0E
    beq service_complete_temporary_world_map_picker_nmi_c0a686
    tay
    inc
    .a8
    and #$03
    sta $0E
    jsr upload_next_world_map_picker_tile_third
service_complete_temporary_world_map_picker_nmi_c0a686:
    jsr publish_world_map_picker_matrix_when_rows_are_complete
    rep #$30
    plb
    pld
    ply
    plx
    pla
    rti
