; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-hold-child.md.
.setcpu "65816"
.smart
.a8
.i16

boss_attack_notice_public_jump = $C00027
boss_external_actor_command_if_selected = $3963
request_follow_spell_target_sound = $9AD1
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $9F3C
initialize_binding_spell_and_selected_command_global_control:
    ldx $87
    lda a:$00B4,X
    jsl f:boss_attack_notice_public_jump
    ldx $87
    .a16
    lda #$0126
    jsr select_boss_animation_and_reset_frame_cursor
    inc a:$0094,X
    .a16
    lda #$0200
    sta a:$0066,X
    .a16
    lda #$07FF
    sta a:$0022,X
    lda a:$0098,X
    .a16
    and #$7FFF
    sta a:$0098,X
    .a16
    lda #$0001
    sta a:$0070,X
    .a16
    lda #$0001
    sta a:$0000,X
    sep #$20
    .a8
    lda #$01
    sta a:$000B,X
    rep #$20
    jsr request_follow_spell_target_sound
    .a16
    lda #$8B00
    jsr boss_external_actor_command_if_selected
    clc
    rts
