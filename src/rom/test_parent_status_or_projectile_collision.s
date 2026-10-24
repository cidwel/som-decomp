; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

scan_projectile_collision_and_mark_parent_target_contacts = $3CE8

.segment "CODE"
.org $3F64
test_parent_status_or_projectile_collision:
    lda a:$00B0,X
    tax
    lda a:$0190,X
    bmi test_parent_status_or_projectile_collision_c23f76
    jsr scan_projectile_collision_and_mark_parent_target_contacts
    bcs test_parent_status_or_projectile_collision_c23f76
    ldx $87
    clc
    rts
test_parent_status_or_projectile_collision_c23f76:
    sec
    rts
