; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

queue_selected_effect_hp_message = $C05BC0
random_byte_long_wrapper = $C0389C

.segment "CODE"
.org $E2CB
actor_selected_effect_hp_or_damage_and_message:
    ldx $85
    jsl f:random_byte_long_wrapper
    .a8
    bit #$07
    bne actor_selected_effect_hp_or_damage_and_message_c8e2e3
    rep #$20
    lda a:$E182,X
    sta a:$E1F1,X
    stz a:$E1F3,X
    sep #$20
    rts
actor_selected_effect_hp_or_damage_and_message_c8e2e3:
    .a8
    lda #$01
    sta a:$E182,X
    stz a:$E183,X
    lda $80
    .a8
    ora #$40
    sta $80
    jsl f:queue_selected_effect_hp_message
    rts
