; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_automatic_map_camera_motion = $DBBA

.segment "CODE"
.org $DB48
advance_sine_map_layer_motion:
    rep #$30
    lda a:$0A8E,X
    clc
    adc a:$0A8A,X
    .a16
    and #$03FF
    sta a:$0A8A,X
    sta $00
    sep #$20
    lsr $01
    bcc advance_sine_map_layer_motion_c0db62
    .a8
    eor #$FF
    inc
advance_sine_map_layer_motion_c0db62:
    rep #$20
    .a16
    and #$00FF
    asl
    tay
    lda a:$FD22,Y
    sep #$30
    sta a:$211B
    xba
    sta a:$211B
    lda a:$0A8C,X
    sta a:$211C
    lda a:$2134
    clc
    adc a:$0A86,X
    sta a:$0A86,X
    lda a:$2135
    ldy a:$2136
    .a8
    adc #$00
    beq advance_sine_map_layer_motion_c0db9d
    .a8
    cmp #$09
    bcc advance_sine_map_layer_motion_c0db95
    .a8
    lda #$08
advance_sine_map_layer_motion_c0db95:
    lsr $01
    bcc dispatch_automatic_map_camera_motion
    .a8
    ora #$80
    bra dispatch_automatic_map_camera_motion
advance_sine_map_layer_motion_c0db9d:
    rts
