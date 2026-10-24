; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-effect-animation.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C9E0
update_event_radial_window_and_wait_frame:
    sep #$30
    .a8
    lda #$00
    sta f:$004204
    .a8
    lda #$FF
    sta f:$004205
    lda $18
    bne update_event_radial_window_and_wait_frame_c2c9f4
    .a8
    lda #$01
update_event_radial_window_and_wait_frame_c2c9f4:
    sta f:$004206
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    lda f:$004214
    sta $06
    sta $07
    lda f:$004215
    sta $08
    stz $09
    lda $18
    sta f:$004202
    .i8
    ldx #$00
    txy
    lda a:$F700,Y
    sta f:$004203
    nop
    nop
    nop
    nop
    lda f:$004217
    sta a:$F500,X
    inx
    inx
    ldy $08
    rep #$10
    .a8
    lda #$00
    xba
update_event_radial_window_and_wait_frame_c2ca34:
    lda a:$F700,Y
    sta f:$004203
    nop
    nop
    nop
    nop
    lda f:$004217
    sta a:$F500,X
    clc
    adc a:$F4FE,X
    ror
    sta a:$F4FF,X
    inx
    inx
    .i16
    cpx #$00E0
    bcs update_event_radial_window_and_wait_frame_c2ca6e
    lda $06
    clc
    adc $07
    sta $06
    tya
    adc $08
    bcs update_event_radial_window_and_wait_frame_c2ca64
    tay
    bra update_event_radial_window_and_wait_frame_c2ca34
update_event_radial_window_and_wait_frame_c2ca64:
    dex
update_event_radial_window_and_wait_frame_c2ca65:
    stz a:$F500,X
    inx
    .i16
    cpx #$00E0
    bcc update_event_radial_window_and_wait_frame_c2ca65
update_event_radial_window_and_wait_frame_c2ca6e:
    rep #$30
    lda $1F
    .a16
    and #$00FF
    asl
    tay
    .i16
    ldx #$0000
    phy
    sep #$20
update_event_radial_window_and_wait_frame_c2ca7d:
    lda $1E
    sec
    sbc a:$F500,X
    bcs update_event_radial_window_and_wait_frame_c2ca87
    .a8
    lda #$00
update_event_radial_window_and_wait_frame_c2ca87:
    sta a:$F220,Y
    cmp $1E
    bne update_event_radial_window_and_wait_frame_c2ca91
    dec
    bra update_event_radial_window_and_wait_frame_c2ca9b
update_event_radial_window_and_wait_frame_c2ca91:
    lda $1E
    clc
    adc a:$F500,X
    bcc update_event_radial_window_and_wait_frame_c2ca9b
    .a8
    lda #$FF
update_event_radial_window_and_wait_frame_c2ca9b:
    sta a:$F221,Y
    inx
    dey
    dey
    bpl update_event_radial_window_and_wait_frame_c2ca7d
    ply
    .a8
    lda #$E0
    sec
    sbc $1F
    sta $08
    .i16
    ldx #$0000
update_event_radial_window_and_wait_frame_c2caae:
    lda $1E
    sec
    sbc a:$F500,X
    bcs update_event_radial_window_and_wait_frame_c2cab8
    .a8
    lda #$00
update_event_radial_window_and_wait_frame_c2cab8:
    sta a:$F220,Y
    cmp $1E
    bne update_event_radial_window_and_wait_frame_c2cac2
    dec
    bra update_event_radial_window_and_wait_frame_c2cacc
update_event_radial_window_and_wait_frame_c2cac2:
    lda $1E
    clc
    adc a:$F500,X
    bcc update_event_radial_window_and_wait_frame_c2cacc
    .a8
    lda #$FF
update_event_radial_window_and_wait_frame_c2cacc:
    sta a:$F221,Y
    iny
    iny
    inx
    dec $08
    bne update_event_radial_window_and_wait_frame_c2caae
    .a8
    lda #$04
    sta $2C
    lda $18
    lsr
    lsr
    lsr
    .a8
    ora #$E0
    pha
    .a8
    lda #$0C
    sta $EC
update_event_radial_window_and_wait_frame_c2cae6:
    bit $EC
    bne update_event_radial_window_and_wait_frame_c2cae6
    pla
    sta f:$002132
    .a8
    lda #$30
    sta f:$002125
    .a8
    lda #$20
    sta f:$002130
    .a8
    lda #$13
    sta f:$00212C
    .a8
    lda #$33
    sta f:$002131
    .i16
    ldx #$0000
    rep #$20
update_event_radial_window_and_wait_frame_c2cb0c:
    lda a:$F220,X
    sta a:$F020,X
    inx
    inx
    .i16
    cpx #$01C0
    bcc update_event_radial_window_and_wait_frame_c2cb0c
    rts
