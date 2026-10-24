; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-list.md.
.setcpu "65816"
.smart
.a8
.i16

add_native_menu_row_tile_segment_when_comparison_carries = $709C
bind_native_menu_list_row_to_active_hero_oam_marker = $70A3
build_native_menu_descriptor_source_for_shop_or_inventory = $D0CF48
hide_native_menu_icon_oam_objects = $D0C83F
hide_shop_hero_markers_before_price_selection = $C0793D
publish_native_menu_icons_and_palette_between_real_vblank_frames = $6977
read_selected_menu_actor_direction_flag = $6A41
routine_c06f7a = $6F7A
routine_c070eb = $70EB
select_event_menu_oam_palette_attribute = $70E3
select_native_menu_ring_hero_and_shop_geometry = $7108

.segment "CODE"
.org $6F7D
build_native_ring_descriptors_icons_geometry_and_row_records:
    sep #$20
    stz a:$1848
    stz a:$1806
    jsr read_selected_menu_actor_direction_flag
    jsl f:hide_native_menu_icon_oam_objects
    jsl f:build_native_menu_descriptor_source_for_shop_or_inventory
    jsr select_native_menu_ring_hero_and_shop_geometry
    beq routine_c06f7a
    jsr publish_native_menu_icons_and_palette_between_real_vblank_frames
    rep #$30
    .i16
    ldx #$0000
    .i16
    ldy #$0048
    lda a:$1812
    .a16
    cmp #$0001
    beq build_native_ring_descriptors_icons_geometry_and_row_records_c06fae
    .i16
    ldx #$00E8
    .i16
    ldy #$FE98
build_native_ring_descriptors_icons_geometry_and_row_records_c06fae:
    stx a:$181E
    sty a:$1816
    stz a:$1822
    jsl f:hide_shop_hero_markers_before_price_selection
    .i16
    ldx #$082C
    .a16
    lda #$0001
    jsr select_event_menu_oam_palette_attribute
    clc
    .a16
    adc #$010A
    sta $02,X
    .a16
    lda #$0002
    jsr select_event_menu_oam_palette_attribute
    clc
    .a16
    adc #$010C
    sta $06,X
    .a16
    lda #$0003
    jsr select_event_menu_oam_palette_attribute
    clc
    .a16
    adc #$010E
    sta $0A,X
    .i16
    ldx #$0838
    lda a:$181A
    .a16
    and #$00FF
    .a16
    ora #$E800
    sec
    .a16
    sbc #$0008
    sta $00,X
    sta $08,X
    clc
    .a16
    adc #$0010
    sta $04,X
    sta $0C,X
    lda a:$1808
    .a16
    and #$00FF
    inc
    jsr select_event_menu_oam_palette_attribute
    clc
    .a16
    adc #$0108
    sta $02,X
    .a16
    ora #$4000
    sta $06,X
    .a16
    ora #$8000
    sta $0E,X
    .a16
    and #$BFFF
    sta $0A,X
    .i16
    ldx #$18C0
    .i16
    ldy #$0000
    lda a:$180B
    .a16
    and #$00FF
build_native_ring_descriptors_icons_geometry_and_row_records_c07029:
    pha
    stz $00,X
    stz $02,X
    .a16
    lda #$00E8
    sta $04,X
    jsr bind_native_menu_list_row_to_active_hero_oam_marker
    tya
    asl
    .i16
    cpy #$0008
    bcc build_native_ring_descriptors_icons_geometry_and_row_records_c07041
    clc
    .a16
    adc #$0010
build_native_ring_descriptors_icons_geometry_and_row_records_c07041:
    clc
    .a16
    adc #$00E0
    pha
    lda a:$1802
    .a16
    and #$0001
    beq build_native_ring_descriptors_icons_geometry_and_row_records_c07051
    .a16
    lda #$0800
build_native_ring_descriptors_icons_geometry_and_row_records_c07051:
    clc
    adc $01,S
    .a16
    ora #$3000
    .i16
    cpy #$0003
    jsr add_native_menu_row_tile_segment_when_comparison_carries
    .i16
    cpy #$0006
    jsr add_native_menu_row_tile_segment_when_comparison_carries
    .i16
    cpy #$0009
    jsr add_native_menu_row_tile_segment_when_comparison_carries
    sta $06,X
    lda a:$1810
    bpl build_native_ring_descriptors_icons_geometry_and_row_records_c07077
    lda $00,X
    .a16
    ora #$8000
    sta $00,X
build_native_ring_descriptors_icons_geometry_and_row_records_c07077:
    pla
    tya
    asl
    clc
    adc a:$180E
    phx
    tax
    lda f:$D80000,X
    plx
    clc
    adc a:$1816
    .a16
    and #$03FF
    sta $08,X
    txa
    clc
    .a16
    adc #$0010
    tax
    iny
    pla
    dec
    beq routine_c070eb
    jmp build_native_ring_descriptors_icons_geometry_and_row_records_c07029
