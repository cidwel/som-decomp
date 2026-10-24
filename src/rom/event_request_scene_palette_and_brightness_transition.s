; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-palette-transition.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_event_opcode_or_wait_state = $E8D3
routine_02c806 = $2C806

.segment "CODE"
.org $ED35
event_request_scene_palette_and_brightness_transition:
    lda $05
    bpl event_request_scene_palette_and_brightness_transition_c1ed44
    .a8
    cmp #$90
    bcs event_request_scene_palette_and_brightness_transition_c1ed41
    .a8
    and #$0F
    bra event_request_scene_palette_and_brightness_transition_c1ed8b
event_request_scene_palette_and_brightness_transition_c1ed41:
    brl event_request_scene_palette_and_brightness_transition_c1edc9
event_request_scene_palette_and_brightness_transition_c1ed44:
    bne event_request_scene_palette_and_brightness_transition_c1ed56
    .a8
    lda #$00
    sta a:$1057
    lda $E6
    sta a:$1058
    .a8
    lda #$04
    tsb $E2
    bra event_request_scene_palette_and_brightness_transition_c1edc9
event_request_scene_palette_and_brightness_transition_c1ed56:
    .a8
    cmp #$01
    bne event_request_scene_palette_and_brightness_transition_c1ed61
    .a8
    lda #$01
    sta a:$1057
    bra event_request_scene_palette_and_brightness_transition_c1edc9
event_request_scene_palette_and_brightness_transition_c1ed61:
    .a8
    cmp #$02
    bne event_request_scene_palette_and_brightness_transition_c1ed6b
    .a8
    lda #$E0
    sta $49
    bra event_request_scene_palette_and_brightness_transition_c1edc9
event_request_scene_palette_and_brightness_transition_c1ed6b:
    .a8
    cmp #$03
    bne event_request_scene_palette_and_brightness_transition_c1ed75
    .a8
    lda #$60
    sta $49
    bra event_request_scene_palette_and_brightness_transition_c1edc9
event_request_scene_palette_and_brightness_transition_c1ed75:
    .a8
    cmp #$04
    bne event_request_scene_palette_and_brightness_transition_c1ed7d
    stz $49
    bra event_request_scene_palette_and_brightness_transition_c1edc9
event_request_scene_palette_and_brightness_transition_c1ed7d:
    .a8
    cmp #$05
    bne event_request_scene_palette_and_brightness_transition_c1ed85
    .a8
    lda #$20
    bra event_request_scene_palette_and_brightness_transition_c1ed8b
event_request_scene_palette_and_brightness_transition_c1ed85:
    .a8
    cmp #$06
    bne event_request_scene_palette_and_brightness_transition_c1eda8
    .a8
    lda #$60
event_request_scene_palette_and_brightness_transition_c1ed8b:
    pha
    jsl f:routine_02c806
    pla
    sta $2A
    rep #$20
    .i8
    ldy #$02
    lda [$D1],Y
    sta a:$010C
    stz a:$010A
    lda $D1
    clc
    .a16
    adc #$0004
    sta $D1
    rts
event_request_scene_palette_and_brightness_transition_c1eda8:
    .a8
    cmp #$07
    bne event_request_scene_palette_and_brightness_transition_c1edbb
    lda $2A
    beq event_request_scene_palette_and_brightness_transition_c1edc9
    .a8
    ora #$80
    sta $2A
event_request_scene_palette_and_brightness_transition_c1edb4:
    rep #$20
    inc $D1
    inc $D1
    rts
event_request_scene_palette_and_brightness_transition_c1edbb:
    .a8
    cmp #$08
    bne event_request_scene_palette_and_brightness_transition_c1edc9
    .a8
    lda #$08
    tsb $E2
    .a8
    lda #$86
    sta $D0
    bra event_request_scene_palette_and_brightness_transition_c1edb4
event_request_scene_palette_and_brightness_transition_c1edc9:
    rep #$20
    inc $D1
    inc $D1
    brl dispatch_native_event_opcode_or_wait_state
