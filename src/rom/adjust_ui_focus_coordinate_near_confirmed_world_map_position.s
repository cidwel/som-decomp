; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-exit.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B091
adjust_ui_focus_coordinate_near_confirmed_world_map_position:
    rep #$20
    lda $FA
    .a16
    and #$0FFF
    sec
    sbc a:$0128
    bpl adjust_ui_focus_coordinate_near_confirmed_world_map_position_c2b0ba
    .a16
    cmp #$F801
    bcc adjust_ui_focus_coordinate_near_confirmed_world_map_position_c2b0aa
    .a16
    cmp #$FF80
    bcc adjust_ui_focus_coordinate_near_confirmed_world_map_position_c2b0d6
    bra adjust_ui_focus_coordinate_near_confirmed_world_map_position_c2b0b2
adjust_ui_focus_coordinate_near_confirmed_world_map_position_c2b0aa:
    .a16
    adc #$1000
    .a16
    cmp #$0080
    bcs adjust_ui_focus_coordinate_near_confirmed_world_map_position_c2b0d6
adjust_ui_focus_coordinate_near_confirmed_world_map_position_c2b0b2:
    lda $FA
    clc
    .a16
    adc #$0080
    bra adjust_ui_focus_coordinate_near_confirmed_world_map_position_c2b0d0
adjust_ui_focus_coordinate_near_confirmed_world_map_position_c2b0ba:
    .a16
    cmp #$0800
    bcc adjust_ui_focus_coordinate_near_confirmed_world_map_position_c2b0c5
    .a16
    sbc #$1000
    .a16
    eor #$FFFF
adjust_ui_focus_coordinate_near_confirmed_world_map_position_c2b0c5:
    .a16
    cmp #$0080
    bcs adjust_ui_focus_coordinate_near_confirmed_world_map_position_c2b0d6
    lda $FA
    sec
    .a16
    sbc #$0080
adjust_ui_focus_coordinate_near_confirmed_world_map_position_c2b0d0:
    .a16
    and #$0FFF
    sta a:$0128
adjust_ui_focus_coordinate_near_confirmed_world_map_position_c2b0d6:
    rtl
