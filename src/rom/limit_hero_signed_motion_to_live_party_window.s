; Recovered Secret of Mana USA routine; behaviour documented in docs/map-hero-motion.md.
.setcpu "65816"
.smart
.a8
.i16

test_hero_horizontal_step_against_camera_window = $D962
test_hero_vertical_step_against_camera_window = $D9E8
test_partner_horizontal_window_and_cancel_hero_step = $D9AE
test_partner_vertical_window_and_cancel_hero_step = $DA34

.segment "CODE"
.org $D6C8
limit_hero_signed_motion_to_live_party_window:
    sep #$30
    lda $FF
    beq limit_hero_signed_motion_to_live_party_window_c0d6cf
    rts
limit_hero_signed_motion_to_live_party_window_c0d6cf:
    lda $1E
    beq limit_hero_signed_motion_to_live_party_window_c0d70e
    jsr test_hero_horizontal_step_against_camera_window
    bcc limit_hero_signed_motion_to_live_party_window_c0d70e
    sep #$20
    rep #$10
    ldx $10
    lda a:$E02C,X
    bne limit_hero_signed_motion_to_live_party_window_c0d6e7
    stz $1E
    bra limit_hero_signed_motion_to_live_party_window_c0d70e
limit_hero_signed_motion_to_live_party_window_c0d6e7:
    lda $11
    beq limit_hero_signed_motion_to_live_party_window_c0d702
    .a8
    cmp #$02
    beq limit_hero_signed_motion_to_live_party_window_c0d6fa
    .i16
    ldx #$0000
    jsr test_partner_horizontal_window_and_cancel_hero_step
    .i16
    ldx #$0200
    bra limit_hero_signed_motion_to_live_party_window_c0d70b
limit_hero_signed_motion_to_live_party_window_c0d6fa:
    .i16
    ldx #$0000
    jsr test_partner_horizontal_window_and_cancel_hero_step
    bra limit_hero_signed_motion_to_live_party_window_c0d708
limit_hero_signed_motion_to_live_party_window_c0d702:
    .i16
    ldx #$0200
    jsr test_partner_horizontal_window_and_cancel_hero_step
limit_hero_signed_motion_to_live_party_window_c0d708:
    .i16
    ldx #$0400
limit_hero_signed_motion_to_live_party_window_c0d70b:
    jsr test_partner_horizontal_window_and_cancel_hero_step
limit_hero_signed_motion_to_live_party_window_c0d70e:
    sep #$20
    lda $1F
    beq limit_hero_signed_motion_to_live_party_window_c0d74b
    jsr test_hero_vertical_step_against_camera_window
    bcc limit_hero_signed_motion_to_live_party_window_c0d74b
    sep #$20
    rep #$10
    ldx $10
    lda a:$E02C,X
    beq limit_hero_signed_motion_to_live_party_window_c0d74c
    lda $11
    beq limit_hero_signed_motion_to_live_party_window_c0d73f
    .a8
    cmp #$02
    beq limit_hero_signed_motion_to_live_party_window_c0d737
    .i16
    ldx #$0000
    jsr test_partner_vertical_window_and_cancel_hero_step
    .i16
    ldx #$0200
    bra limit_hero_signed_motion_to_live_party_window_c0d748
limit_hero_signed_motion_to_live_party_window_c0d737:
    .i16
    ldx #$0000
    jsr test_partner_vertical_window_and_cancel_hero_step
    bra limit_hero_signed_motion_to_live_party_window_c0d745
limit_hero_signed_motion_to_live_party_window_c0d73f:
    .i16
    ldx #$0200
    jsr test_partner_vertical_window_and_cancel_hero_step
limit_hero_signed_motion_to_live_party_window_c0d745:
    .i16
    ldx #$0400
limit_hero_signed_motion_to_live_party_window_c0d748:
    jmp test_partner_vertical_window_and_cancel_hero_step
limit_hero_signed_motion_to_live_party_window_c0d74b:
    rts
limit_hero_signed_motion_to_live_party_window_c0d74c:
    stz $1F
    rts
