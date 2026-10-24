; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-navigation.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8159
test_ui_target_tile_permission_and_request_map_transition:
    sep #$30
    lda $FD
    .a8
    and #$0C
    sta $00
    lda $FB
    lsr
    lsr
    .a8
    and #$03
    ora $00
    asl
    asl
    asl
    sta $00
    asl
    clc
    adc $00
    xba
    rol
    .a8
    and #$01
    xba
    rep #$30
    sta $00
    lda $FA
    lsr
    lsr
    lsr
    .a16
    and #$01FF
    sta $02
    lda $FC
    lsr
    lsr
    .a16
    and #$00FE
    xba
    ora $02
    tax
    lda f:$7F0000,X
    .a16
    and #$00FF
    .a16
    cmp #$00A0
    bcc test_ui_target_tile_permission_and_request_map_transition_c081ad
    .a16
    cmp #$00AF
    bne test_ui_target_tile_permission_and_request_map_transition_c081a7
    bit $E2
    bvc test_ui_target_tile_permission_and_request_map_transition_c081d3
    bvs test_ui_target_tile_permission_and_request_map_transition_c081ad
test_ui_target_tile_permission_and_request_map_transition_c081a7:
    bcs test_ui_target_tile_permission_and_request_map_transition_c081ad
    bit $E2
    bpl test_ui_target_tile_permission_and_request_map_transition_c081d3
test_ui_target_tile_permission_and_request_map_transition_c081ad:
    sta $02
    lsr
    lsr
    lsr
    clc
    adc $00
    tax
    sep #$20
    lda f:$C67600,X
    sep #$10
    sta $00
    lda $02
    .a8
    and #$07
    tax
    lda $00
    .i8
    cpx #$00
    beq test_ui_target_tile_permission_and_request_map_transition_c081cf
test_ui_target_tile_permission_and_request_map_transition_c081cb:
    lsr
    dex
    bne test_ui_target_tile_permission_and_request_map_transition_c081cb
test_ui_target_tile_permission_and_request_map_transition_c081cf:
    .a8
    and #$01
    beq test_ui_target_tile_permission_and_request_map_transition_c081d4
test_ui_target_tile_permission_and_request_map_transition_c081d3:
    rts
test_ui_target_tile_permission_and_request_map_transition_c081d4:
    sep #$30
    .a8
    lda #$03
    bit $F2
    beq test_ui_target_tile_permission_and_request_map_transition_c081e1
    .a8
    lda #$10
    tsb $CC
    rts
test_ui_target_tile_permission_and_request_map_transition_c081e1:
    lda $F2
    bmi test_ui_target_tile_permission_and_request_map_transition_c081e9
    .a8
    ora #$01
    sta $F2
test_ui_target_tile_permission_and_request_map_transition_c081e9:
    .a8
    lda #$80
    sta $FE
