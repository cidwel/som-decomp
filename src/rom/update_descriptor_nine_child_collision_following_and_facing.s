; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-nine-child.md.
.setcpu "65816"
.smart
.a8
.i16

refresh_descriptor_nine_child_animation_from_parent_byte_key = $6678
scan_projectile_collision_and_mark_parent_target_contacts = $3CE8

.segment "CODE"
.org $6630
update_descriptor_nine_child_collision_following_and_facing:
    ldx $87
    jsr scan_projectile_collision_and_mark_parent_target_contacts
    ldx $87
    lda a:$00B0,X
    tax
    lda a:$0094,X
    .a16
    cmp #$0006
    bcs update_descriptor_nine_child_collision_following_and_facing_c26676
    lda a:$002B,X
    sta $95
    lda a:$0032,X
    sta $97
    lda a:$0088,X
    sta $99
    lda a:$0098,X
    .a16
    and #$00C0
    sta $9B
    ldx $87
    lda $95
    sta a:$002B,X
    lda $97
    sta a:$0032,X
    lda a:$0098,X
    .a16
    and #$FF3F
    ora $9B
    sta a:$0098,X
    jsr refresh_descriptor_nine_child_animation_from_parent_byte_key
    clc
    rts
update_descriptor_nine_child_collision_following_and_facing_c26676:
    sec
    rts
