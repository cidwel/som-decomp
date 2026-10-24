; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-ten-terminal.md.
.setcpu "65816"
.smart
.a8
.i16

public_actor_death_jump = $C0006F

.segment "CODE"
.org $7ABD
publish_descriptor_ten_public_reward_after_tick24:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0018
    bcc publish_descriptor_ten_public_reward_after_tick24_c27ace
    inc a:$0094,X
    jsl f:public_actor_death_jump
publish_descriptor_ten_public_reward_after_tick24_c27ace:
    clc
    rts
