; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-children.md.
.setcpu "65816"
.smart
.a8
.i16

test_parent_status_or_projectile_collision = $3F64

.segment "CODE"
.org $8A53
consume_native59_projectile_contact_and_finish_animation:
    ldx $87
    lda a:$00B4,X
    bne consume_native59_projectile_contact_and_finish_animation_c28a66
    jsr test_parent_status_or_projectile_collision
    bcc consume_native59_projectile_contact_and_finish_animation_c28a66
    ldx $87
    lda $C7
    sta a:$00B4,X
consume_native59_projectile_contact_and_finish_animation_c28a66:
    ldx $87
    lda a:$009E,X
    bne consume_native59_projectile_contact_and_finish_animation_c28a6f
    sec
    rts
consume_native59_projectile_contact_and_finish_animation_c28a6f:
    clc
    rts
