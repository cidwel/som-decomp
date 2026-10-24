; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

write_one_party_hud_frame = $E228

.segment "CODE"
.org $E113
place_party_hud_frames:
    sep #$20
    lda f:$7ECF00
    bne place_party_hud_frames_c1e11c
    rts
place_party_hud_frames_c1e11c:
    rep #$10
    lda f:$7EE000
    bmi place_party_hud_frames_c1e126
    bne place_party_hud_frames_c1e137
place_party_hud_frames_c1e126:
    lda f:$7EE200
    bmi place_party_hud_frames_c1e12e
    bne place_party_hud_frames_c1e154
place_party_hud_frames_c1e12e:
    lda f:$7EE400
    bmi place_party_hud_frames_c1e136
    bne place_party_hud_frames_c1e17a
place_party_hud_frames_c1e136:
    rts
place_party_hud_frames_c1e137:
    lda f:$7EE200
    bmi place_party_hud_frames_c1e13f
    bne place_party_hud_frames_c1e149
place_party_hud_frames_c1e13f:
    lda f:$7EE400
    bmi place_party_hud_frames_c1e15e
    bne place_party_hud_frames_c1e1af
    beq place_party_hud_frames_c1e15e
place_party_hud_frames_c1e149:
    lda f:$7EE400
    bmi place_party_hud_frames_c1e18c
    beq place_party_hud_frames_c1e18c
    brl place_party_hud_frames_c1e1f5
place_party_hud_frames_c1e154:
    lda f:$7EE400
    bmi place_party_hud_frames_c1e16c
    bne place_party_hud_frames_c1e1d2
    beq place_party_hud_frames_c1e16c
place_party_hud_frames_c1e15e:
    .a8
    lda #$4D
    sta a:$0A55
    lda f:$7EE02C
    .i16
    ldy #$0024
    bra place_party_hud_frames_c1e186
place_party_hud_frames_c1e16c:
    .a8
    lda #$4D
    sta a:$0A65
    lda f:$7EE22C
    .i16
    ldy #$0028
    bra place_party_hud_frames_c1e186
place_party_hud_frames_c1e17a:
    .a8
    lda #$4D
    sta a:$0A75
    lda f:$7EE42C
    .i16
    ldy #$002C
place_party_hud_frames_c1e186:
    .i16
    ldx #$5B2B
    brl write_one_party_hud_frame
place_party_hud_frames_c1e18c:
    .a8
    lda #$48
    sta a:$0A55
    .a8
    lda #$52
    sta a:$0A65
    lda f:$7EE02C
    .i16
    ldx #$5B26
    .i16
    ldy #$0024
    jsr write_one_party_hud_frame
    lda f:$7EE22C
    .i16
    ldx #$5B30
    .i16
    ldy #$0028
    bra write_one_party_hud_frame
place_party_hud_frames_c1e1af:
    .a8
    lda #$48
    sta a:$0A55
    .a8
    lda #$52
    sta a:$0A75
    lda f:$7EE02C
    .i16
    ldx #$5B26
    .i16
    ldy #$0024
    jsr write_one_party_hud_frame
    lda f:$7EE42C
    .i16
    ldx #$5B30
    .i16
    ldy #$002C
    bra write_one_party_hud_frame
place_party_hud_frames_c1e1d2:
    .a8
    lda #$48
    sta a:$0A65
    .a8
    lda #$52
    sta a:$0A75
    lda f:$7EE22C
    .i16
    ldx #$5B26
    .i16
    ldy #$0028
    jsr write_one_party_hud_frame
    lda f:$7EE42C
    .i16
    ldx #$5B30
    .i16
    ldy #$002C
    bra write_one_party_hud_frame
place_party_hud_frames_c1e1f5:
    .a8
    lda #$43
    sta a:$0A55
    .a8
    lda #$4D
    sta a:$0A65
    .a8
    lda #$57
    sta a:$0A75
    lda f:$7EE02C
    .i16
    ldx #$5B21
    .i16
    ldy #$0024
    jsr write_one_party_hud_frame
    lda f:$7EE22C
    .i16
    ldx #$5B2B
    .i16
    ldy #$0028
    jsr write_one_party_hud_frame
    lda f:$7EE42C
    .i16
    ldx #$5B35
    .i16
    ldy #$002C
