; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-motion.md.
.setcpu "65816"
.smart
.a8
.i16

consume_native54_action_damage_and_initialize_auxiliary_recoil = $496C

.segment "CODE"
.org $4AD6
enter_native54_return_state_after_attack_notification:
    ldx $87
    jsr consume_native54_action_damage_and_initialize_auxiliary_recoil
    bcs enter_native54_return_state_after_attack_notification_c24ae8
    lda a:$00B8,X
    beq enter_native54_return_state_after_attack_notification_c24ae8
    .a16
    lda #$0007
    sta a:$0094,X
enter_native54_return_state_after_attack_notification_c24ae8:
    clc
    rts
