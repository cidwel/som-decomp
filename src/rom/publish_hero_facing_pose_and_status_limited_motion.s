; Recovered Secret of Mana USA routine; behaviour documented in docs/map-motion-shared.md.
.setcpu "65816"
.smart
.a8
.i16

clear_actor_motion_contact_pose_flags = $D47A

.segment "CODE"
.org $D482
publish_hero_facing_pose_and_status_limited_motion:
    sep #$20
    rep #$10
    ldx $10
    .i16
    cpx #$0600
    bcs clear_actor_motion_contact_pose_flags
    lda a:$E01C,X
    ora a:$E060,X
    bne clear_actor_motion_contact_pose_flags
    lda a:$E02F,X
    bne publish_hero_facing_pose_and_status_limited_motion_c0d4f8
    lda a:$E067,X
    bne clear_actor_motion_contact_pose_flags
    rep #$20
    lda a:$E190,X
    .a16
    bit #$4160
    bne clear_actor_motion_contact_pose_flags
    .a16
    bit #$8404
    sep #$20
    beq publish_hero_facing_pose_and_status_limited_motion_c0d4b3
    brl publish_hero_facing_pose_and_status_limited_motion_c0d531
publish_hero_facing_pose_and_status_limited_motion_c0d4b3:
    lda a:$E01D,X
    .a8
    bit #$30
    beq publish_hero_facing_pose_and_status_limited_motion_c0d4c1
    .a8
    and #$80
    sta a:$E01D,X
    bra publish_hero_facing_pose_and_status_limited_motion_c0d4e0
publish_hero_facing_pose_and_status_limited_motion_c0d4c1:
    lda a:$E006,X
    beq publish_hero_facing_pose_and_status_limited_motion_c0d4d0
    bmi publish_hero_facing_pose_and_status_limited_motion_c0d4cc
    .a8
    lda #$02
    bra publish_hero_facing_pose_and_status_limited_motion_c0d4dd
publish_hero_facing_pose_and_status_limited_motion_c0d4cc:
    .a8
    lda #$82
    bra publish_hero_facing_pose_and_status_limited_motion_c0d4dd
publish_hero_facing_pose_and_status_limited_motion_c0d4d0:
    lda a:$E007,X
    beq publish_hero_facing_pose_and_status_limited_motion_c0d4e0
    bmi publish_hero_facing_pose_and_status_limited_motion_c0d4db
    .a8
    lda #$01
    bra publish_hero_facing_pose_and_status_limited_motion_c0d4dd
publish_hero_facing_pose_and_status_limited_motion_c0d4db:
    .a8
    lda #$00
publish_hero_facing_pose_and_status_limited_motion_c0d4dd:
    sta a:$E010,X
publish_hero_facing_pose_and_status_limited_motion_c0d4e0:
    lda $1E
    bne publish_hero_facing_pose_and_status_limited_motion_c0d4fe
    lda $1F
    bne publish_hero_facing_pose_and_status_limited_motion_c0d4fe
    lda a:$E029,X
    bmi publish_hero_facing_pose_and_status_limited_motion_c0d52a
    bit $ED
    bpl publish_hero_facing_pose_and_status_limited_motion_c0d4fa
    lda a:$E1ED,X
    bne publish_hero_facing_pose_and_status_limited_motion_c0d4fa
    .a8
    lda #$03
publish_hero_facing_pose_and_status_limited_motion_c0d4f8:
    bra publish_hero_facing_pose_and_status_limited_motion_c0d526
publish_hero_facing_pose_and_status_limited_motion_c0d4fa:
    .a8
    lda #$00
    bra publish_hero_facing_pose_and_status_limited_motion_c0d526
publish_hero_facing_pose_and_status_limited_motion_c0d4fe:
    xba
    lda a:$E029,X
    bpl publish_hero_facing_pose_and_status_limited_motion_c0d50b
    stz a:$E029,X
    .a8
    lda #$08
    bne publish_hero_facing_pose_and_status_limited_motion_c0d526
publish_hero_facing_pose_and_status_limited_motion_c0d50b:
    bit $ED
    bpl publish_hero_facing_pose_and_status_limited_motion_c0d51b
    lda a:$E01A,X
    ora a:$E01B,X
    beq publish_hero_facing_pose_and_status_limited_motion_c0d51b
    .a8
    lda #$04
    bra publish_hero_facing_pose_and_status_limited_motion_c0d526
publish_hero_facing_pose_and_status_limited_motion_c0d51b:
    xba
    .a8
    and #$7F
    .a8
    cmp #$03
    .a8
    lda #$01
    bcc publish_hero_facing_pose_and_status_limited_motion_c0d526
    .a8
    lda #$02
publish_hero_facing_pose_and_status_limited_motion_c0d526:
    sta a:$E011,X
    rts
publish_hero_facing_pose_and_status_limited_motion_c0d52a:
    stz a:$E029,X
    .a8
    lda #$08
    bne publish_hero_facing_pose_and_status_limited_motion_c0d526
publish_hero_facing_pose_and_status_limited_motion_c0d531:
    lda $FF
    bne publish_hero_facing_pose_and_status_limited_motion_c0d57c
    lda a:$E191,X
    bpl publish_hero_facing_pose_and_status_limited_motion_c0d556
    lda $1E
    asl
    .a8
    cmp #$06
    bcc publish_hero_facing_pose_and_status_limited_motion_c0d548
    .a8
    lda #$04
    asl $1E
    ror
    sta $1E
publish_hero_facing_pose_and_status_limited_motion_c0d548:
    lda $1F
    asl
    .a8
    cmp #$06
    bcc publish_hero_facing_pose_and_status_limited_motion_c0d556
    .a8
    lda #$04
    asl $1F
    ror
    sta $1F
publish_hero_facing_pose_and_status_limited_motion_c0d556:
    lda a:$E190,X
    ora a:$E191,X
    .a8
    bit #$04
    beq publish_hero_facing_pose_and_status_limited_motion_c0d57c
    lda $1E
    asl
    .a8
    cmp #$04
    bcc publish_hero_facing_pose_and_status_limited_motion_c0d56e
    .a8
    lda #$02
    asl $1E
    ror
    sta $1E
publish_hero_facing_pose_and_status_limited_motion_c0d56e:
    lda $1F
    asl
    .a8
    cmp #$04
    bcc publish_hero_facing_pose_and_status_limited_motion_c0d57c
    .a8
    lda #$02
    asl $1F
    ror
    sta $1F
publish_hero_facing_pose_and_status_limited_motion_c0d57c:
    lda a:$E006,X
    beq publish_hero_facing_pose_and_status_limited_motion_c0d58b
    bmi publish_hero_facing_pose_and_status_limited_motion_c0d587
    .a8
    lda #$02
    bra publish_hero_facing_pose_and_status_limited_motion_c0d598
publish_hero_facing_pose_and_status_limited_motion_c0d587:
    .a8
    lda #$82
    bra publish_hero_facing_pose_and_status_limited_motion_c0d598
publish_hero_facing_pose_and_status_limited_motion_c0d58b:
    lda a:$E007,X
    beq publish_hero_facing_pose_and_status_limited_motion_c0d59b
    bmi publish_hero_facing_pose_and_status_limited_motion_c0d596
    .a8
    lda #$01
    bra publish_hero_facing_pose_and_status_limited_motion_c0d598
publish_hero_facing_pose_and_status_limited_motion_c0d596:
    .a8
    lda #$00
publish_hero_facing_pose_and_status_limited_motion_c0d598:
    sta a:$E010,X
publish_hero_facing_pose_and_status_limited_motion_c0d59b:
    lda a:$E191,X
    bpl publish_hero_facing_pose_and_status_limited_motion_c0d5ac
    lda $1E
    ora $1F
    .a8
    cmp #$01
    .a8
    lda #$00
    rol
    brl publish_hero_facing_pose_and_status_limited_motion_c0d526
publish_hero_facing_pose_and_status_limited_motion_c0d5ac:
    .a8
    bit #$04
    beq publish_hero_facing_pose_and_status_limited_motion_c0d5b5
    .a8
    lda #$04
    brl publish_hero_facing_pose_and_status_limited_motion_c0d526
publish_hero_facing_pose_and_status_limited_motion_c0d5b5:
    lda $1E
    ora $1F
    beq publish_hero_facing_pose_and_status_limited_motion_c0d5bd
    .a8
    lda #$04
publish_hero_facing_pose_and_status_limited_motion_c0d5bd:
    brl publish_hero_facing_pose_and_status_limited_motion_c0d526
