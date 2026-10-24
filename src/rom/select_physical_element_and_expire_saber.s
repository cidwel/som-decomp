; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


object_element_type_word = $E194
object_resistance_mask = $E1A2
object_weakness_mask = $E1A0
object_saber_hits_remaining = $E19D
object_weapon_bonus = $E1AE
object_refresh_flags = $E1FA

.segment "CODE"
.org $50CA
select_physical_element_and_expire_saber:
    rep #$20
    lda a:object_element_type_word,X
    bit a:object_resistance_mask,X
    beq select_physical_element_and_expire_saber_c050dc
    sep #$20
    .a8
    lda #$01
    sta $8F
    bra select_physical_element_and_expire_saber_c050ef
select_physical_element_and_expire_saber_c050dc:
    bit a:object_weakness_mask,X
    beq select_physical_element_and_expire_saber_c050e9
    sep #$20
    .a8
    lda #$04
    sta $8F
    bra select_physical_element_and_expire_saber_c050ef
select_physical_element_and_expire_saber_c050e9:
    sep #$20
    .a8
    lda #$02
    sta $8F
select_physical_element_and_expire_saber_c050ef:
    lda a:object_saber_hits_remaining,Y
    beq select_physical_element_and_expire_saber_c05118
    dec
    sta a:object_saber_hits_remaining,Y
    beq select_physical_element_and_expire_saber_c050fb
    rts
select_physical_element_and_expire_saber_c050fb:
    lda a:object_weapon_bonus,Y
    .a8
    and #$F0
    sta a:object_weapon_bonus,Y
    phy
    phx
    tyx
    jsl f:$C04530
    jsl f:$C058B9
    plx
    ply
    lda a:object_refresh_flags,Y
    .a8
    ora #$04
    sta a:object_refresh_flags,Y
select_physical_element_and_expire_saber_c05118:
    rts
