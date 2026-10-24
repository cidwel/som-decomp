; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-map-door-controller.md.
.setcpu "65816"
.smart
.a8
.i16

patch_indirect_door_tiles_and_request_layer_camera_row = $BB32
request_diagonal_hero_door_motion_and_black_fade = $BA8B
request_slow_black_fade = $8B16
select_door_tile_variant_and_deferred_audio_parameter = $BAD5

.segment "CODE"
.org $B9C5
dispatch_selected_hero_door_action_before_diagonal_continuation:
    sep #$20
    rep #$10
    ldx $D4
    lda $E0
    .a8
    and #$1F
    bne dispatch_selected_hero_door_action_before_diagonal_continuation_c0b9dc
dispatch_selected_hero_door_action_before_diagonal_continuation_c0b9d1:
    sep #$20
    lda $E0
    .a8
    ora #$1F
    sta $E0
    jmp request_slow_black_fade
dispatch_selected_hero_door_action_before_diagonal_continuation_c0b9dc:
    pha
    .a8
    lda #$80
    sta $4E
    pla
    .a8
    cmp #$1E
    bne dispatch_selected_hero_door_action_before_diagonal_continuation_c0b9ed
    lda f:$7EE00A,X
    beq dispatch_selected_hero_door_action_before_diagonal_continuation_c0b9d1
    rts
dispatch_selected_hero_door_action_before_diagonal_continuation_c0b9ed:
    .a8
    cmp #$05
    bcs dispatch_selected_hero_door_action_before_diagonal_continuation_c0ba4c
    sta $E1
    dec
    sta $00
    .a8
    lda #$20
    tsb $FF
    lda f:$7EE00E,X
    bmi dispatch_selected_hero_door_action_before_diagonal_continuation_c0ba14
    rep #$20
    lda f:$7EE020,X
    .a16
    cmp #$0100
    bcs dispatch_selected_hero_door_action_before_diagonal_continuation_c0ba14
    lda f:$7EE022,X
    .a16
    cmp #$0100
    bcc dispatch_selected_hero_door_action_before_diagonal_continuation_c0ba1e
dispatch_selected_hero_door_action_before_diagonal_continuation_c0ba14:
    sep #$20
    .a8
    lda #$20
    sta f:$7EE00A,X
    bra dispatch_selected_hero_door_action_before_diagonal_continuation_c0b9d1
dispatch_selected_hero_door_action_before_diagonal_continuation_c0ba1e:
    sep #$20
    .i16
    ldy #$8200
    lda $00
    beq dispatch_selected_hero_door_action_before_diagonal_continuation_c0ba36
    .i16
    ldy #$0200
    dec
    beq dispatch_selected_hero_door_action_before_diagonal_continuation_c0ba36
    .i16
    ldy #$0002
    dec
    beq dispatch_selected_hero_door_action_before_diagonal_continuation_c0ba36
    .i16
    ldy #$0082
dispatch_selected_hero_door_action_before_diagonal_continuation_c0ba36:
    .a8
    lda #$20
    sta f:$7EE00A,X
    rep #$20
    tya
    sta f:$7EE006
    sta f:$7EE206
    sta f:$7EE406
    rts
dispatch_selected_hero_door_action_before_diagonal_continuation_c0ba4c:
    lsr $4E
    .a8
    cmp #$0B
    bcs request_diagonal_hero_door_motion_and_black_fade
    jsr select_door_tile_variant_and_deferred_audio_parameter
    xba
    pha
    .a8
    lda #$82
    sta f:$7EE007
    sta f:$7EE207
    sta f:$7EE407
    .a8
    lda #$00
    sta f:$7EE006
    sta f:$7EE206
    sta f:$7EE406
    .a8
    lda #$10
    sta f:$7EE00A,X
    lda $E0
    .a8
    and #$E0
    .a8
    ora #$1F
    sta $E0
    phx
    jsr request_slow_black_fade
    plx
    pla
    brl patch_indirect_door_tiles_and_request_layer_camera_row
