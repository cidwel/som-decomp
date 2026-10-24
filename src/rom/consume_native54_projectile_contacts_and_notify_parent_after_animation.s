; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-projectiles.md.
.setcpu "65816"
.smart
.a8
.i16

copy_boss_palette_with_cpu_words = $26F9
scan_projectile_collision_and_mark_parent_target_contacts = $3CE8

.segment "CODE"
.org $5041
consume_native54_projectile_contacts_and_notify_parent_after_animation:
    ldx $87
    lda a:$00B2,X
    bne consume_native54_projectile_contacts_and_notify_parent_after_animation_c25053
    jsr scan_projectile_collision_and_mark_parent_target_contacts
    bcc consume_native54_projectile_contacts_and_notify_parent_after_animation_c25053
    .a16
    lda #$0001
    sta a:$00B2,X
consume_native54_projectile_contacts_and_notify_parent_after_animation_c25053:
    lda a:$009E,X
    bne consume_native54_projectile_contacts_and_notify_parent_after_animation_c2507b
    lda a:$00B0,X
    tax
    lda a:$0042,X
    asl
    clc
    adc a:$0042,X
    .a16
    adc #$0022
    .i16
    ldx #$000F
    jsr copy_boss_palette_with_cpu_words
    ldx $87
    lda a:$00B0,X
    tax
    .a16
    lda #$0001
    sta a:$00B8,X
    sec
    rts
consume_native54_projectile_contacts_and_notify_parent_after_animation_c2507b:
    clc
    rts
