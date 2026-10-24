; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-setup.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8E9E
compute_wrapped_scene_target_deltas_and_direction_flags:
    rep #$20
    lda a:$0110
    .a16
    and #$00FF
    asl
    asl
    asl
    asl
    sta $04
    lda a:$0111
    .a16
    and #$00FF
    asl
    asl
    asl
    asl
    sta $06
    lda $FA
    sec
    sbc $04
    bcs compute_wrapped_scene_target_deltas_and_direction_flags_c08ece
    .a16
    eor #$FFFF
    inc
    .a16
    cmp #$0800
    bcc compute_wrapped_scene_target_deltas_and_direction_flags_c08ed7
    .a16
    eor #$0FFF
    inc
    bra compute_wrapped_scene_target_deltas_and_direction_flags_c08edb
compute_wrapped_scene_target_deltas_and_direction_flags_c08ece:
    .a16
    cmp #$0800
    bcc compute_wrapped_scene_target_deltas_and_direction_flags_c08edb
    .a16
    eor #$0FFF
    inc
compute_wrapped_scene_target_deltas_and_direction_flags_c08ed7:
    sta $00
    bra compute_wrapped_scene_target_deltas_and_direction_flags_c08ee4
compute_wrapped_scene_target_deltas_and_direction_flags_c08edb:
    sta $00
    lda $8D
    .a16
    eor #$0080
    sta $8D
compute_wrapped_scene_target_deltas_and_direction_flags_c08ee4:
    lda $FC
    sec
    sbc $06
    bcs compute_wrapped_scene_target_deltas_and_direction_flags_c08efa
    .a16
    eor #$FFFF
    inc
    .a16
    cmp #$0800
    bcc compute_wrapped_scene_target_deltas_and_direction_flags_c08f03
    .a16
    eor #$0FFF
    inc
    bra compute_wrapped_scene_target_deltas_and_direction_flags_c08f07
compute_wrapped_scene_target_deltas_and_direction_flags_c08efa:
    .a16
    cmp #$0800
    bcc compute_wrapped_scene_target_deltas_and_direction_flags_c08f07
    .a16
    eor #$0FFF
    inc
compute_wrapped_scene_target_deltas_and_direction_flags_c08f03:
    sta $02
    bra compute_wrapped_scene_target_deltas_and_direction_flags_c08f10
compute_wrapped_scene_target_deltas_and_direction_flags_c08f07:
    sta $02
    lda $8D
    .a16
    eor #$0040
    sta $8D
compute_wrapped_scene_target_deltas_and_direction_flags_c08f10:
    lda $00
    lsr
    sta $84
    lda $02
    lsr
    sta $88
    stz $86
    stz $8A
    .a16
    lda #$01FF
    sta $8E
    rts
