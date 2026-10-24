; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-projection.md.
.setcpu "65816"
.smart
.a8
.i16

project_wrapped_ui_target_with_native_perspective = $B287
publish_clipped_ui_marker_sprite_records = $B247
routine_008260 = $8260

.segment "CODE"
.org $B10A
project_ui_focus_marker_and_trigger_real_map_transition:
    rep #$10
    sep #$20
    lda $8C
    bne project_ui_focus_marker_and_trigger_real_map_transition_c2b118
    lda $E3
    .a8
    bit #$40
    bne project_ui_focus_marker_and_trigger_real_map_transition_c2b119
project_ui_focus_marker_and_trigger_real_map_transition_c2b118:
    rtl
project_ui_focus_marker_and_trigger_real_map_transition_c2b119:
    lda $F4
    .a8
    and #$FF
    bne project_ui_focus_marker_and_trigger_real_map_transition_c2b133
    lda $F5
    lsr
    bcs project_ui_focus_marker_and_trigger_real_map_transition_c2b133
    lda $CF
    bne project_ui_focus_marker_and_trigger_real_map_transition_c2b133
    lda $C7
    clc
    .a8
    adc #$4B
    sta $C7
    .a8
    and #$3F
    sta $C6
project_ui_focus_marker_and_trigger_real_map_transition_c2b133:
    lda $C6
    beq project_ui_focus_marker_and_trigger_real_map_transition_c2b16b
    dec $C6
    rep #$20
    lda a:$0128
    bit $C6
    bvc project_ui_focus_marker_and_trigger_real_map_transition_c2b148
    clc
    .a16
    adc #$0006
    bra project_ui_focus_marker_and_trigger_real_map_transition_c2b14c
project_ui_focus_marker_and_trigger_real_map_transition_c2b148:
    sec
    .a16
    sbc #$0006
project_ui_focus_marker_and_trigger_real_map_transition_c2b14c:
    .a16
    and #$0FFF
    sta a:$0128
    lda a:$012A
    bit $C6
    bmi project_ui_focus_marker_and_trigger_real_map_transition_c2b15f
    clc
    .a16
    adc #$0006
    bra project_ui_focus_marker_and_trigger_real_map_transition_c2b163
project_ui_focus_marker_and_trigger_real_map_transition_c2b15f:
    sec
    .a16
    sbc #$0006
project_ui_focus_marker_and_trigger_real_map_transition_c2b163:
    .a16
    and #$0FFF
    sta a:$012A
    sep #$20
project_ui_focus_marker_and_trigger_real_map_transition_c2b16b:
    phy
    .a8
    lda #$D0
    sta $0B
    rep #$20
    lda a:$0128
    sta $0C
    lda a:$012A
    sta $0E
    jsr project_wrapped_ui_target_with_native_perspective
    ply
    bcc project_ui_focus_marker_and_trigger_real_map_transition_c2b18f
    sep #$20
    stz $BE
    stz $BF
    lda $CF
    beq project_ui_focus_marker_and_trigger_real_map_transition_c2b18e
    dec $CF
project_ui_focus_marker_and_trigger_real_map_transition_c2b18e:
    rtl
project_ui_focus_marker_and_trigger_real_map_transition_c2b18f:
    rep #$20
    .a16
    and #$0007
    asl
    tax
    lda f:$02B7A4,X
    tax
    lda $0C
    bpl project_ui_focus_marker_and_trigger_real_map_transition_c2b1a2
    .a16
    eor #$FFFF
project_ui_focus_marker_and_trigger_real_map_transition_c2b1a2:
    .a16
    cmp #$0040
    bcs project_ui_focus_marker_and_trigger_real_map_transition_c2b1e3
    lda $0E
    bpl project_ui_focus_marker_and_trigger_real_map_transition_c2b1ae
    .a16
    eor #$FFFF
project_ui_focus_marker_and_trigger_real_map_transition_c2b1ae:
    .a16
    cmp #$0040
    bcs project_ui_focus_marker_and_trigger_real_map_transition_c2b1e3
    sep #$20
    lda $F8
    .a8
    cmp #$B8
    bcc project_ui_focus_marker_and_trigger_real_map_transition_c2b1e3
    lda $CF
    inc
    .a8
    cmp #$5C
    bcc project_ui_focus_marker_and_trigger_real_map_transition_c2b1df
    lda $BF
    .a8
    adc #$00
    sta $BF
    bne project_ui_focus_marker_and_trigger_real_map_transition_c2b1eb
    .a8
    lda #$01
    sta $E8
    .a8
    lda #$80
    tsb $F2
    .i16
    ldx #$01FF
    txs
    rep #$30
    .a16
    lda #$000A
    jml f:routine_008260
project_ui_focus_marker_and_trigger_real_map_transition_c2b1df:
    inc $CF
    bra project_ui_focus_marker_and_trigger_real_map_transition_c2b1eb
project_ui_focus_marker_and_trigger_real_map_transition_c2b1e3:
    sep #$20
    lda $CF
    beq project_ui_focus_marker_and_trigger_real_map_transition_c2b1eb
    dec $CF
project_ui_focus_marker_and_trigger_real_map_transition_c2b1eb:
    .a8
    lda #$80
    tsb $BE
    bit $F2
    bpl project_ui_focus_marker_and_trigger_real_map_transition_c2b1f7
    .a8
    lda #$10
    tsb $CC
project_ui_focus_marker_and_trigger_real_map_transition_c2b1f7:
    sep #$20
    lda f:$C20000,X
    inx
    sta $02
    sta $04
    stz $03
    jsr publish_clipped_ui_marker_sprite_records
    sep #$20
    lda $BF
    beq project_ui_focus_marker_and_trigger_real_map_transition_c2b246
    bpl project_ui_focus_marker_and_trigger_real_map_transition_c2b21a
    lsr
    lsr
    lsr
    .a8
    and #$0F
    .a8
    eor #$0F
    sta $E6
    .a8
    lda #$7F
project_ui_focus_marker_and_trigger_real_map_transition_c2b21a:
    asl
    sta a:$4202
    lda $09
    .a8
    adc #$20
    sta a:$4203
    nop
    nop
    nop
    nop
    lda a:$4217
    .a8
    adc #$E4
    sta $09
    rep #$20
    lda $F4
    lsr
    .a16
    and #$0006
    tax
    lda f:$02B7B4,X
    tax
    .a16
    lda #$0002
    sta $02
    jsr publish_clipped_ui_marker_sprite_records
project_ui_focus_marker_and_trigger_real_map_transition_c2b246:
    rtl
