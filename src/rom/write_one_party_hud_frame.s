; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $E228
write_one_party_hud_frame:
    pha
    stx $00
    stx a:$2116
    .a8
    lda #$80
    sta a:$2115
    rep #$20
    .i16
    ldx #$0000
write_one_party_hud_frame_c1e238:
    lda f:$D27E30,X
    sta a:$2118
    inx
    inx
    .i16
    cpx #$0014
    bcc write_one_party_hud_frame_c1e238
    lda $00
    clc
    .a16
    adc #$0020
    sta a:$2116
write_one_party_hud_frame_c1e24f:
    lda f:$D27E30,X
    sta a:$2118
    inx
    inx
    .i16
    cpx #$0028
    bcc write_one_party_hud_frame_c1e24f
    lda $00
    clc
    .a16
    adc #$0040
    sta a:$2116
write_one_party_hud_frame_c1e266:
    lda f:$D27E30,X
    sta a:$2118
    inx
    inx
    .i16
    cpx #$003C
    bcc write_one_party_hud_frame_c1e266
    sep #$20
    ldx $00
    inx
    stx a:$2116
    pla
    beq write_one_party_hud_frame_c1e291
    lsr
    bcs write_one_party_hud_frame_c1e289
    lsr
    bcs write_one_party_hud_frame_c1e28d
    .a8
    lda #$23
    bra write_one_party_hud_frame_c1e293
write_one_party_hud_frame_c1e289:
    .a8
    lda #$21
    bra write_one_party_hud_frame_c1e293
write_one_party_hud_frame_c1e28d:
    .a8
    lda #$22
    bra write_one_party_hud_frame_c1e293
write_one_party_hud_frame_c1e291:
    .a8
    lda #$16
write_one_party_hud_frame_c1e293:
    sta a:$2118
    rep #$20
    lda $00
    clc
    .a16
    adc #$0024
    sta a:$2116
    tya
    sep #$20
    bit $B8
    bmi write_one_party_hud_frame_c1e2aa
    bvc write_one_party_hud_frame_c1e2ac
write_one_party_hud_frame_c1e2aa:
    .a8
    lda #$24
write_one_party_hud_frame_c1e2ac:
    sta a:$2119
    sta a:$2119
    sta a:$2119
    sta a:$2119
    sta a:$2119
    rts
