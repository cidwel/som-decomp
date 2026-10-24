; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-effect-particles.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CC07
update_and_emit_event_radial_particle:
    sep #$20
    lda $18
    .a8
    bit #$03
    bne update_and_emit_event_radial_particle_c2cc21
    tya
    lda a:$F645,Y
    clc
    .a8
    adc #$55
    sta a:$F645,Y
    .a8
    and #$03
    asl
    .a8
    ora #$20
    sta a:$F646,Y
update_and_emit_event_radial_particle_c2cc21:
    lda a:$F641,Y
    clc
    adc a:$F642,Y
    bcc update_and_emit_event_radial_particle_c2cc4c
    lda a:$F643,Y
    .a8
    eor #$08
    sta a:$F643,Y
    lda a:$F640,Y
    .a8
    eor #$10
    sta a:$F640,Y
    .a8
    lda #$00
    bit $19
    bpl update_and_emit_event_radial_particle_c2cc4c
    bit $18
    bmi update_and_emit_event_radial_particle_c2cc4c
    sta a:$F642,Y
    .a8
    lda #$FF
    sta a:$F640,Y
update_and_emit_event_radial_particle_c2cc4c:
    sta a:$F641,Y
    rep #$20
    .a16
    and #$00FF
    .a16
    eor #$00FF
    asl
    tax
    .a16
    lda #$0100
    sec
    sbc f:$00FD22,X
    .a16
    cmp #$0100
    sep #$20
    bcc update_and_emit_event_radial_particle_c2cc6d
    lda a:$F640,Y
    bra update_and_emit_event_radial_particle_c2cc80
update_and_emit_event_radial_particle_c2cc6d:
    sta f:$004202
    lda a:$F640,Y
    sta f:$004203
    nop
    nop
    nop
    nop
    lda f:$004217
update_and_emit_event_radial_particle_c2cc80:
    sta $00
    lda a:$F643,Y
    .a8
    and #$40
    .a8
    cmp #$40
    rep #$20
    lda a:$F643,Y
    .a16
    and #$003F
    bcc update_and_emit_event_radial_particle_c2cc96
    .a16
    eor #$003F
update_and_emit_event_radial_particle_c2cc96:
    asl
    asl
    asl
    tax
    lda f:$00FD22,X
    .a16
    cmp #$0100
    bcc update_and_emit_event_radial_particle_c2cca6
    .a16
    lda #$00FF
update_and_emit_event_radial_particle_c2cca6:
    sta $02
    txa
    .a16
    eor #$01FE
    inc
    inc
    tax
    lda f:$00FD22,X
    .a16
    cmp #$0100
    bcc update_and_emit_event_radial_particle_c2ccbb
    .a16
    lda #$00FF
update_and_emit_event_radial_particle_c2ccbb:
    sta $04
    sep #$20
    lda $00
    sta f:$004202
    lda $02
    sta f:$004203
    nop
    nop
    nop
    nop
    lda f:$004217
    sta $02
    lda $04
    sta f:$004203
    nop
    nop
    nop
    nop
    lda f:$004217
    sta $04
    lda a:$F643,Y
    bmi update_and_emit_event_radial_particle_c2ccfc
    .a8
    cmp #$40
    bcc update_and_emit_event_radial_particle_c2cd18
    lda $04
    .a8
    eor #$FF
    sta $04
    lda $05
    .a8
    eor #$FF
    sta $05
    bra update_and_emit_event_radial_particle_c2cd18
update_and_emit_event_radial_particle_c2ccfc:
    .a8
    cmp #$C0
    bcs update_and_emit_event_radial_particle_c2cd0c
    lda $04
    .a8
    eor #$FF
    sta $04
    lda $05
    .a8
    eor #$FF
    sta $05
update_and_emit_event_radial_particle_c2cd0c:
    lda $02
    .a8
    eor #$FF
    sta $02
    lda $03
    .a8
    eor #$FF
    sta $03
update_and_emit_event_radial_particle_c2cd18:
    rep #$20
    lda $1E
    .a16
    and #$00FF
    sec
    .a16
    sbc #$0004
    clc
    adc $02
    .a16
    cmp #$0100
    bcs update_and_emit_event_radial_particle_c2cd3e
    sta $02
    lda $1F
    sec
    .a16
    sbc #$0004
    .a16
    and #$00FF
    clc
    adc $04
    .a16
    cmp #$0100
    bcc update_and_emit_event_radial_particle_c2cd3f
update_and_emit_event_radial_particle_c2cd3e:
    rts
update_and_emit_event_radial_particle_c2cd3f:
    sta $03
    ldx $08
    lda $02
    sta a:$0900,X
    lda a:$F646,Y
    sta a:$0902,X
    inx
    inx
    inx
    inx
    stx $08
    rts
