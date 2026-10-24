; Recovered Secret of Mana USA routine; behaviour documented in docs/map-motion-shared.md.
.setcpu "65816"
.smart
.a8
.i16

publish_hero_facing_pose_and_status_limited_motion = $D482
routine_01d28f = $1D28F
routine_01e76d = $1E76D
routine_c0bb11 = $BB11

.segment "CODE"
.org $D2E0
apply_actor_ground_contact_effect_to_live_motion:
    sep #$20
    rep #$10
    ldx $10
    lda a:$E029,X
    beq apply_actor_ground_contact_effect_to_live_motion_c0d316
    .a8
    bit #$01
    beq apply_actor_ground_contact_effect_to_live_motion_c0d2f3
    .a8
    and #$8A
    stz $1E
apply_actor_ground_contact_effect_to_live_motion_c0d2f3:
    .a8
    bit #$02
    beq apply_actor_ground_contact_effect_to_live_motion_c0d2fb
    .a8
    and #$85
    stz $1F
apply_actor_ground_contact_effect_to_live_motion_c0d2fb:
    .a8
    bit #$04
    beq apply_actor_ground_contact_effect_to_live_motion_c0d306
    xba
    lda a:$E03A,X
    sta $1E
    xba
apply_actor_ground_contact_effect_to_live_motion_c0d306:
    .a8
    bit #$08
    beq apply_actor_ground_contact_effect_to_live_motion_c0d311
    xba
    lda a:$E03B,X
    sta $1F
    xba
apply_actor_ground_contact_effect_to_live_motion_c0d311:
    .a8
    and #$80
    sta a:$E029,X
apply_actor_ground_contact_effect_to_live_motion_c0d316:
    sep #$20
    lda a:$E060,X
    bne apply_actor_ground_contact_effect_to_live_motion_c0d38e
    lda a:$E01C,X
    bne apply_actor_ground_contact_effect_to_live_motion_c0d38e
    lda $F1
    bmi apply_actor_ground_contact_effect_to_live_motion_c0d38e
    lda $D0
    beq apply_actor_ground_contact_effect_to_live_motion_c0d339
    .i16
    cpx #$0600
    bcc apply_actor_ground_contact_effect_to_live_motion_c0d335
    cpx $3A
    beq apply_actor_ground_contact_effect_to_live_motion_c0d38e
    bne apply_actor_ground_contact_effect_to_live_motion_c0d359
apply_actor_ground_contact_effect_to_live_motion_c0d335:
    cpx $D4
    beq apply_actor_ground_contact_effect_to_live_motion_c0d38e
apply_actor_ground_contact_effect_to_live_motion_c0d339:
    lda a:$E01B,X
    bne apply_actor_ground_contact_effect_to_live_motion_c0d345
    lda a:$E01A,X
    .a8
    cmp #$02
    bcc apply_actor_ground_contact_effect_to_live_motion_c0d359
apply_actor_ground_contact_effect_to_live_motion_c0d345:
    lda $1E
    beq apply_actor_ground_contact_effect_to_live_motion_c0d34f
    asl
    .a8
    lda #$02
    ror
    sta $1E
apply_actor_ground_contact_effect_to_live_motion_c0d34f:
    lda $1F
    beq apply_actor_ground_contact_effect_to_live_motion_c0d359
    asl
    .a8
    lda #$02
    ror
    sta $1F
apply_actor_ground_contact_effect_to_live_motion_c0d359:
    lda a:$E048,X
    sta $00
    .a8
    and #$F0
    beq apply_actor_ground_contact_effect_to_live_motion_c0d38e
    .a8
    cmp #$D0
    bne apply_actor_ground_contact_effect_to_live_motion_c0d372
    bit a:$E071,X
    bpl apply_actor_ground_contact_effect_to_live_motion_c0d38e
    lda $D0
    bne apply_actor_ground_contact_effect_to_live_motion_c0d38e
    brl apply_actor_ground_contact_effect_to_live_motion_c0d449
apply_actor_ground_contact_effect_to_live_motion_c0d372:
    .a8
    cmp #$20
    beq apply_actor_ground_contact_effect_to_live_motion_c0d391
    .a8
    cmp #$30
    beq apply_actor_ground_contact_effect_to_live_motion_c0d3dd
    .a8
    cmp #$40
    bne apply_actor_ground_contact_effect_to_live_motion_c0d38e
    lda $00
    .a8
    and #$0F
    .a8
    ora #$70
    cmp $95
    beq apply_actor_ground_contact_effect_to_live_motion_c0d38e
    .a8
    ora #$80
    jsl f:routine_01d28f
apply_actor_ground_contact_effect_to_live_motion_c0d38e:
    brl publish_hero_facing_pose_and_status_limited_motion
apply_actor_ground_contact_effect_to_live_motion_c0d391:
    lda $F4
    .a8
    and #$04
    beq apply_actor_ground_contact_effect_to_live_motion_c0d3b1
    .a8
    lda #$02
    and $00
    beq apply_actor_ground_contact_effect_to_live_motion_c0d3ae
    lda $F4
    lsr
    bcs apply_actor_ground_contact_effect_to_live_motion_c0d3ae
    lsr $00
    lda $1E
    beq apply_actor_ground_contact_effect_to_live_motion_c0d3ae
    bcs apply_actor_ground_contact_effect_to_live_motion_c0d3ac
    .a8
    eor #$80
apply_actor_ground_contact_effect_to_live_motion_c0d3ac:
    sta $1F
apply_actor_ground_contact_effect_to_live_motion_c0d3ae:
    brl publish_hero_facing_pose_and_status_limited_motion
apply_actor_ground_contact_effect_to_live_motion_c0d3b1:
    lda $00
    .a8
    and #$02
    beq apply_actor_ground_contact_effect_to_live_motion_c0d3d6
    lda $1E
    beq apply_actor_ground_contact_effect_to_live_motion_c0d3d3
apply_actor_ground_contact_effect_to_live_motion_c0d3bb:
    stz $1E
    stz $1F
    bit $95
    bmi apply_actor_ground_contact_effect_to_live_motion_c0d3d3
    lda a:$E02C,X
    beq apply_actor_ground_contact_effect_to_live_motion_c0d3d3
    lda $F4
    .a8
    and #$07
    bne apply_actor_ground_contact_effect_to_live_motion_c0d3d3
    .a8
    lda #$EF
    jsr routine_c0bb11
apply_actor_ground_contact_effect_to_live_motion_c0d3d3:
    brl publish_hero_facing_pose_and_status_limited_motion
apply_actor_ground_contact_effect_to_live_motion_c0d3d6:
    lda $1F
    bne apply_actor_ground_contact_effect_to_live_motion_c0d3bb
    brl publish_hero_facing_pose_and_status_limited_motion
apply_actor_ground_contact_effect_to_live_motion_c0d3dd:
    lda $00
    pha
    jsr publish_hero_facing_pose_and_status_limited_motion
    sep #$20
    pla
    .a8
    and #$0F
    pha
    lsr
    lsr
    inc
    sta $00
    pla
    .a8
    and #$03
    beq apply_actor_ground_contact_effect_to_live_motion_c0d435
    dec
    beq apply_actor_ground_contact_effect_to_live_motion_c0d421
    dec
    beq apply_actor_ground_contact_effect_to_live_motion_c0d40d
    lda $1E
    bpl apply_actor_ground_contact_effect_to_live_motion_c0d400
    .a8
    eor #$7F
    inc
apply_actor_ground_contact_effect_to_live_motion_c0d400:
    clc
    adc $00
    bpl apply_actor_ground_contact_effect_to_live_motion_c0d40a
    .a8
    eor #$7F
    inc
    .a8
    ora #$80
apply_actor_ground_contact_effect_to_live_motion_c0d40a:
    sta $1E
    rts
apply_actor_ground_contact_effect_to_live_motion_c0d40d:
    lda $1E
    bpl apply_actor_ground_contact_effect_to_live_motion_c0d414
    .a8
    eor #$7F
    inc
apply_actor_ground_contact_effect_to_live_motion_c0d414:
    sec
    sbc $00
    bpl apply_actor_ground_contact_effect_to_live_motion_c0d41e
    .a8
    eor #$7F
    inc
    .a8
    ora #$80
apply_actor_ground_contact_effect_to_live_motion_c0d41e:
    sta $1E
    rts
apply_actor_ground_contact_effect_to_live_motion_c0d421:
    lda $1F
    bpl apply_actor_ground_contact_effect_to_live_motion_c0d428
    .a8
    eor #$7F
    inc
apply_actor_ground_contact_effect_to_live_motion_c0d428:
    clc
    adc $00
    bpl apply_actor_ground_contact_effect_to_live_motion_c0d432
    .a8
    eor #$7F
    inc
    .a8
    ora #$80
apply_actor_ground_contact_effect_to_live_motion_c0d432:
    sta $1F
    rts
apply_actor_ground_contact_effect_to_live_motion_c0d435:
    lda $1F
    bpl apply_actor_ground_contact_effect_to_live_motion_c0d43c
    .a8
    eor #$7F
    inc
apply_actor_ground_contact_effect_to_live_motion_c0d43c:
    sec
    sbc $00
    bpl apply_actor_ground_contact_effect_to_live_motion_c0d446
    .a8
    eor #$7F
    inc
    .a8
    ora #$80
apply_actor_ground_contact_effect_to_live_motion_c0d446:
    sta $1F
    rts
apply_actor_ground_contact_effect_to_live_motion_c0d449:
    lda a:$E01C,X
    ora a:$E045,X
    bne apply_actor_ground_contact_effect_to_live_motion_c0d479
    rep #$20
    lda a:$E05B,X
    sta $D4
    stx $3A
    stz $1E
    stz a:$E006,X
    lda a:$E048,X
    stz a:$E048,X
    pha
    .a16
    and #$000F
    sta $00
    pla
    lsr
    lsr
    lsr
    lsr
    .a16
    and #$0FF0
    ora $00
    jsl f:routine_01e76d
apply_actor_ground_contact_effect_to_live_motion_c0d479:
    rts
