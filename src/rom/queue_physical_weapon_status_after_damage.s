; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

random_below_long_wrapper = $C03884

.segment "CODE"
.org $5119
queue_physical_weapon_status_after_damage:
    lda a:$E190,X
    .a8
    bit #$10
    beq queue_physical_weapon_status_after_damage_c05125
    .a8
    and #$EF
    sta a:$E190,X
queue_physical_weapon_status_after_damage_c05125:
    rep #$20
    lda a:$E199,Y
    bit a:$E1AA,X
    bne queue_physical_weapon_status_after_damage_c05148
    sep #$20
    .a8
    lda #$64
    jsl f:random_below_long_wrapper
    cmp a:$E1F7,Y
    bcs queue_physical_weapon_status_after_damage_c05148
    rep #$20
    lda a:$E1F1,X
    beq queue_physical_weapon_status_after_damage_c05148
    lda a:$E199,Y
    sta $9A
queue_physical_weapon_status_after_damage_c05148:
    sep #$20
    rts
