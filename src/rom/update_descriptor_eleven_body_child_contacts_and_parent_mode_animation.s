; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eleven-children.md.
.setcpu "65816"
.smart
.a8
.i16

scan_projectile_collision_and_mark_parent_target_contacts = $3CE8
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $8DF0
update_descriptor_eleven_body_child_contacts_and_parent_mode_animation:
    ldx $87
    jsr scan_projectile_collision_and_mark_parent_target_contacts
    ldx $87
    ldy a:$00B0,X
    lda a:$0094,Y
    .a16
    cmp #$0006
    bcs update_descriptor_eleven_body_child_contacts_and_parent_mode_animation_c28e19
    lda a:$007A,Y
    asl
    tax
    lda f:$C28EB0,X
    ldx $87
    cmp a:$00B2,X
    beq update_descriptor_eleven_body_child_contacts_and_parent_mode_animation_c28e18
    sta a:$00B2,X
    jsr select_boss_animation_and_reset_frame_cursor
update_descriptor_eleven_body_child_contacts_and_parent_mode_animation_c28e18:
    clc
update_descriptor_eleven_body_child_contacts_and_parent_mode_animation_c28e19:
    rts
