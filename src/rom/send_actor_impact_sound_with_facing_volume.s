; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

audio_command_sender_public_jump = $C30004

.segment "CODE"
.org $4157
send_actor_impact_sound_with_facing_volume:
    .a8
    lda #$02
    sta a:$1E00
    lda a:$E1AF,X
    sta a:$1E01
    .a8
    lda #$0F
    sta a:$1E02
    lda a:$E020,X
    .a8
    and #$F0
    bne send_actor_impact_sound_with_facing_volume_c0416f
    inc
send_actor_impact_sound_with_facing_volume_c0416f:
    sta a:$1E03
    jsl f:audio_command_sender_public_jump
    rts
