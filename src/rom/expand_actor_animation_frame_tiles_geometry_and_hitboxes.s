; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-animation-frames.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $F5AC
expand_actor_animation_frame_tiles_geometry_and_hitboxes:
    rep #$20
    lda $00
    inc
    inc
    sta a:$E016,X
    sep #$20
    inc a:$E00C,X
    lda a:$E010,X
    asl
    rep #$20
    lda [$00]
    sep #$20
    bcc expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f5c8
    .a8
    eor #$20
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f5c8:
    pha
    asl
    sta a:$E028,X
    pla
    .a8
    and #$07
    .a8
    cmp #$04
    bcc expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f5db
    .a8
    and #$03
    sta a:$E089,X
    .a8
    lda #$00
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f5db:
    sta a:$E012,X
    .a8
    lda #$D1
    sta $05
    lda a:$E041,X
    beq expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f5eb
    lda a:$E040,X
    xba
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f5eb:
    xba
    rep #$20
    .a16
    and #$00FF
    pha
    asl
    sta a:$E026,X
    clc
    adc a:$E02A,X
    sta $00
    pla
    clc
    adc a:$E07E,X
    sta $03
    lda [$00]
    pha
    xba
    .a16
    and #$00FF
    asl
    sta $00
    pla
    sep #$20
    .a8
    and #$C0
    xba
    lda a:$E041,X
    .a8
    cmp #$01
    xba
    bcs expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f61e
    eor a:$E028,X
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f61e:
    sta a:$E088,X
    .a8
    lda #$00
    .i16
    cpx #$0000
    beq expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f62f
    .i16
    cpx #$0600
    bcs expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f62f
    lda [$03]
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f62f:
    sta a:$E025,X
    lda a:$E033,X
    sta $02
    sta $12
    rep #$20
    lda a:$E072,X
    clc
    adc $00
    sta $00
    lda [$00]
    rep #$20
    ldx $14
    sta $10
    lda a:$E080,X
    sta $0A
    ldy a:$E06E,X
    sep #$20
    stz $01
    lda [$10]
    sta $04
    .a8
    and #$0F
    bne expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f661
    .a8
    lda #$01
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f661:
    sta a:$E083,X
    asl
    asl
    sta $00
    rep #$20
    inc $10
    ldx $00
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f66e:
    lda [$10]
    bmi expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f686
    inc $10
    inc $10
    .a16
    and #$3FF0
    asl
    adc $0A
    sta a:$0000,Y
    iny
    iny
    dex
    bne expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f66e
    beq expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f6c0
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f686:
    inc $10
    inc $10
    pha
    .a16
    and #$000F
    sta $02
    pla
    asl
    bpl expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f6ac
    .a16
    and #$7FE0
    clc
    adc $0A
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f69a:
    sta a:$0000,Y
    iny
    iny
    dex
    beq expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f6c0
    dec $02
    bmi expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f66e
    clc
    .a16
    adc #$0020
    bra expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f69a
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f6ac:
    .a16
    and #$7FE0
    clc
    adc $0A
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f6b2:
    sta a:$0000,Y
    iny
    iny
    dex
    beq expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f6c0
    dec $02
    bpl expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f6b2
    bmi expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f66e
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f6c0:
    rep #$30
    ldx $14
    lda a:$E083,X
    .a16
    and #$000F
    tay
    sta $06
    lda a:$E08A,X
    sta $0C
    sep #$20
    stz $01
    lda a:$E08E,X
    beq expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f6f6
    .a8
    cmp #$04
    bcs expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f6ea
    sec
    ror $01
    .a8
    cmp #$02
    beq expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f6f6
    .a8
    lda #$30
    bra expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f6f2
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f6ea:
    .a8
    and #$03
    asl
    asl
    asl
    asl
    .a8
    eor #$20
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f6f2:
    eor $0D
    sta $0D
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f6f6:
    lda a:$E088,X
    .a8
    and #$C0
    sta $02
    lda a:$E074,X
    .a8
    and #$7F
    sta $03
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f704:
    rep #$20
    lda [$10]
    inc $10
    inc $10
    sep #$20
    xba
    asl
    ror $00
    xba
    asl
    ror $00
    .a8
    cmp #$80
    bcc expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f721
    ror
    bit $02
    bmi expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f726
    bpl expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f72b
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f721:
    lsr
    bit $02
    bpl expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f72b
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f726:
    clc
    .a8
    adc #$0F
    .a8
    eor #$FF
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f72b:
    xba
    bpl expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f736
    sec
    ror
    bit $02
    bvs expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f73b
    bvc expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f740
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f736:
    lsr
    bit $02
    bvc expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f740
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f73b:
    clc
    .a8
    adc #$0F
    .a8
    eor #$FF
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f740:
    rep #$20
    sta a:$E090,X
    sep #$20
    lda $00
    bpl expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f75a
    bit $01
    bpl expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f75a
    .a8
    and #$40
    eor $02
    ora $0D
    clc
    .a8
    adc #$10
    bra expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f760
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f75a:
    .a8
    and #$40
    eor $02
    ora $0D
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f760:
    sta a:$E093,X
    lda $0C
    sta a:$E092,X
    clc
    .a8
    adc #$02
    .a8
    bit #$10
    beq expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f775
    .a8
    adc #$10
    bcc expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f775
    inc $0D
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f775:
    sta $0C
    inx
    inx
    inx
    inx
    dey
    beq expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f781
    brl expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f704
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f781:
    sep #$20
    bit $ED
    bmi expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f788
    rts
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f788:
    ldx $14
    .a8
    lda #$60
    bit $04
    bne expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f79c
    rep #$20
    .a16
    lda #$0000
    sta a:$E0CA,X
    sta a:$E0CE,X
    rts
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f79c:
    .i16
    ldy #$0000
    .a8
    lda #$40
    bit $04
    beq expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f822
    .a8
    lda #$10
    bit $04
    beq expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f7d4
    lda [$10],Y
    bit $02
    bpl expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f7b4
    .a8
    eor #$FF
    inc
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f7b4:
    iny
    sec
    sbc $03
    sbc a:$E045,X
    bvc expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f7bf
    .a8
    lda #$80
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f7bf:
    sta a:$E0C9,X
    lda [$10],Y
    bit $02
    bvc expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f7cb
    .a8
    eor #$FF
    inc
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f7cb:
    iny
    sta a:$E0C8,X
    lda [$10],Y
    iny
    bra expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f810
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f7d4:
    lda [$10],Y
    iny
    pha
    .a8
    and #$0F
    .a8
    cmp #$08
    bcc expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f7e0
    .a8
    ora #$F0
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f7e0:
    asl
    asl
    bit $02
    bvc expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f7e9
    .a8
    eor #$FF
    inc
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f7e9:
    sta a:$E0C8,X
    pla
    lsr
    lsr
    lsr
    lsr
    .a8
    cmp #$08
    bcc expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f7f7
    .a8
    ora #$F0
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f7f7:
    asl
    asl
    bit $02
    bpl expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f800
    .a8
    eor #$FF
    inc
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f800:
    sec
    sbc $03
    sbc a:$E045,X
    bvc expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f80a
    .a8
    lda #$80
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f80a:
    sta a:$E0C9,X
    lda [$10],Y
    iny
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f810:
    pha
    .a8
    and #$0F
    asl
    asl
    sta a:$E0CA,X
    pla
    lsr
    lsr
    .a8
    and #$3C
    sta a:$E0CB,X
    bra expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f82a
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f822:
    .a8
    lda #$00
    sta a:$E0CA,X
    sta a:$E0CB,X
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f82a:
    .a8
    lda #$20
    bit $04
    bne expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f839
    .a8
    lda #$00
    sta a:$E0CE,X
    sta a:$E0CF,X
    rts
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f839:
    .a8
    lda #$10
    bit $04
    beq expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f867
    lda [$10],Y
    bit $02
    bpl expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f848
    .a8
    eor #$FF
    inc
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f848:
    iny
    sec
    sbc $03
    sbc a:$E045,X
    bvc expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f853
    .a8
    lda #$80
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f853:
    sta a:$E0CD,X
    lda [$10],Y
    bit $02
    bvc expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f85f
    .a8
    eor #$FF
    inc
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f85f:
    iny
    sta a:$E0CC,X
    lda [$10],Y
    bra expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f8a2
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f867:
    lda [$10],Y
    iny
    pha
    .a8
    and #$0F
    .a8
    cmp #$08
    bcc expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f873
    .a8
    ora #$F0
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f873:
    asl
    asl
    bit $02
    bvc expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f87c
    .a8
    eor #$FF
    inc
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f87c:
    sta a:$E0CC,X
    pla
    lsr
    lsr
    lsr
    lsr
    .a8
    cmp #$08
    bcc expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f88a
    .a8
    ora #$F0
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f88a:
    asl
    asl
    bit $02
    bpl expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f893
    .a8
    eor #$FF
    inc
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f893:
    sec
    sbc $03
    sbc a:$E045,X
    bvc expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f89d
    .a8
    lda #$80
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f89d:
    sta a:$E0CD,X
    lda [$10],Y
expand_actor_animation_frame_tiles_geometry_and_hitboxes_c0f8a2:
    pha
    .a8
    and #$0F
    asl
    asl
    sta a:$E0CE,X
    pla
    lsr
    lsr
    .a8
    and #$3C
    sta a:$E0CF,X
    rts
