; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

move_scene_camera_entry = $D1F9

.segment "CODE"
.org $8B5E
update_complete_map_frame_screen_effects:
    sep #$30
    lda $E2
    bne update_complete_map_frame_screen_effects_c08b65
    rts
update_complete_map_frame_screen_effects_c08b65:
    sep #$30
    .a8
    lda #$01
    bit $E2
    beq update_complete_map_frame_screen_effects_c08b97
    dec $E4
    bne update_complete_map_frame_screen_effects_c08b97
    lda $E5
    sta $E4
    lda $E6
    bpl update_complete_map_frame_screen_effects_c08b7b
    .a8
    lda #$00
update_complete_map_frame_screen_effects_c08b7b:
    cmp $E7
    beq update_complete_map_frame_screen_effects_c08b85
    bcc update_complete_map_frame_screen_effects_c08b84
    dec
    bra update_complete_map_frame_screen_effects_c08b85
update_complete_map_frame_screen_effects_c08b84:
    inc
update_complete_map_frame_screen_effects_c08b85:
    sta $E6
    cmp $E7
    bne update_complete_map_frame_screen_effects_c08b97
    .a8
    cmp #$00
    bne update_complete_map_frame_screen_effects_c08b93
    .a8
    lda #$8F
    sta $E6
update_complete_map_frame_screen_effects_c08b93:
    .a8
    lda #$01
    trb $E2
update_complete_map_frame_screen_effects_c08b97:
    .a8
    lda #$02
    bit $E2
    beq update_complete_map_frame_screen_effects_c08bc8
    lda a:$1057
    bpl update_complete_map_frame_screen_effects_c08bae
    clc
    .a8
    adc #$02
    bcc update_complete_map_frame_screen_effects_c08bb9
    lda $20
    sta a:$2106
    bra update_complete_map_frame_screen_effects_c08bb3
update_complete_map_frame_screen_effects_c08bae:
    clc
    .a8
    adc #$02
    bpl update_complete_map_frame_screen_effects_c08bb9
update_complete_map_frame_screen_effects_c08bb3:
    .a8
    lda #$02
    trb $E2
    bra update_complete_map_frame_screen_effects_c08bfe
update_complete_map_frame_screen_effects_c08bb9:
    sta a:$1057
    bpl update_complete_map_frame_screen_effects_c08bc0
    .a8
    eor #$FF
update_complete_map_frame_screen_effects_c08bc0:
    asl
    .a8
    and #$F0
    .a8
    ora #$07
    sta a:$2106
update_complete_map_frame_screen_effects_c08bc8:
    .a8
    lda #$04
    bit $E2
    beq update_complete_map_frame_screen_effects_c08bfe
    lda a:$1057
    beq update_complete_map_frame_screen_effects_c08bec
    dec a:$1057
    bne update_complete_map_frame_screen_effects_c08bec
    .a8
    lda #$04
    trb $E2
update_complete_map_frame_screen_effects_c08bdc:
    .a8
    lda #$02
    sta a:$2130
    lda $23
    sta a:$2131
    .a8
    lda #$E0
    sta a:$2132
    rts
update_complete_map_frame_screen_effects_c08bec:
    lda $F4
    lsr
    bcc update_complete_map_frame_screen_effects_c08bdc
    stz a:$2130
    .a8
    lda #$0F
    sta a:$2131
    .a8
    lda #$FF
    sta a:$2132
update_complete_map_frame_screen_effects_c08bfe:
    .a8
    lda #$08
    bit $E2
    beq update_complete_map_frame_screen_effects_c08c52
    rep #$10
    ldx $D4
    lda f:$7EE020,X
    stz $84
    .a8
    cmp #$7F
    bcc update_complete_map_frame_screen_effects_c08c29
    .a8
    cmp #$82
    bcs update_complete_map_frame_screen_effects_c08c29
    stz $86
    lda f:$7EE022,X
    .a8
    cmp #$7F
    bcc update_complete_map_frame_screen_effects_c08c43
    .a8
    cmp #$82
    bcs update_complete_map_frame_screen_effects_c08c43
    .a8
    lda #$08
    trb $E2
    rts
update_complete_map_frame_screen_effects_c08c29:
    bcs update_complete_map_frame_screen_effects_c08c2f
    .a8
    lda #$82
    bra update_complete_map_frame_screen_effects_c08c31
update_complete_map_frame_screen_effects_c08c2f:
    .a8
    lda #$02
update_complete_map_frame_screen_effects_c08c31:
    sta $84
    lda f:$7EE022,X
    stz $86
    .a8
    cmp #$7F
    bcc update_complete_map_frame_screen_effects_c08c43
    .a8
    cmp #$82
    bcs update_complete_map_frame_screen_effects_c08c43
    bra update_complete_map_frame_screen_effects_c08c4d
update_complete_map_frame_screen_effects_c08c43:
    bcs update_complete_map_frame_screen_effects_c08c49
    .a8
    lda #$82
    bra update_complete_map_frame_screen_effects_c08c4b
update_complete_map_frame_screen_effects_c08c49:
    .a8
    lda #$02
update_complete_map_frame_screen_effects_c08c4b:
    sta $86
update_complete_map_frame_screen_effects_c08c4d:
    jsr move_scene_camera_entry
    sec
    rts
update_complete_map_frame_screen_effects_c08c52:
    .a8
    lda #$10
    bit $E2
    beq update_complete_map_frame_screen_effects_c08c77
    lda $F4
    .a8
    and #$03
    bne update_complete_map_frame_screen_effects_c08c76
    dec a:$105A
    bne update_complete_map_frame_screen_effects_c08c76
    .a8
    lda #$10
    trb $E2
    lda $22
    sta a:$212D
    lda $23
    sta a:$2131
    .a8
    lda #$E0
    sta a:$2132
update_complete_map_frame_screen_effects_c08c76:
    rts
update_complete_map_frame_screen_effects_c08c77:
    rts
