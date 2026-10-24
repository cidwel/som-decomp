; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-action-direction.md.
.setcpu "65816"
.smart
.a8
.i16

decode_actor_direction_command_and_diagonal_facing = $DB27

.segment "CODE"
.org $DADD
apply_actor_directional_command_and_reset_changed_pose:
    .a8
    lda #$80
    sta a:$E067,X
    stz a:$E013,X
    lda a:$E010,X
    sta $0C
    lda a:$E011,X
    sta $0D
    lda a:$E142,X
    sta a:$E011,X
    lda a:$E143,X
    bne apply_actor_directional_command_and_reset_changed_pose_c1db01
    .a8
    lda #$80
    sta a:$E064,X
    .a8
    lda #$00
apply_actor_directional_command_and_reset_changed_pose_c1db01:
    sta a:$E062,X
    jsr decode_actor_direction_command_and_diagonal_facing
    sta a:$E010,X
    lda a:$E030,X
    .a8
    cmp #$FF
    rep #$20
    beq apply_actor_directional_command_and_reset_changed_pose_c1db1d
    lda a:$E010,X
    cmp $0C
    beq apply_actor_directional_command_and_reset_changed_pose_c1db26
    .a16
    lda #$00FF
apply_actor_directional_command_and_reset_changed_pose_c1db1d:
    sta a:$E030,X
    stz a:$E006,X
    stz a:$E008,X
apply_actor_directional_command_and_reset_changed_pose_c1db26:
    rtl
