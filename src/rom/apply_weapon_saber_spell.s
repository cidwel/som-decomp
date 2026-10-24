; Recovered Secret of Mana USA spell routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_spell_attack_roll = $E8C0
routine_c8ea69 = $EA69

object_saber_hits = $E19D
object_saber_elements = $E195
object_saber_status = $E199
object_critical_and_saber_level = $E1AE

.segment "CODE"
.org $EABF
apply_weapon_saber_spell:
    ldx $85
    stz a:object_saber_hits,X
    phy
    phx
    jsl f:$C04530
    plx
    ply
    .a8
    lda #$04
    sta $8F
    jsr calculate_spell_attack_roll
    pla
    ora a:object_saber_elements,X
    sta a:object_saber_elements,X
    rep #$20
    stz a:$CC78
    .i16
    ldy #$2ADD
    lda [$DC],Y
    ldy $83
    ora a:object_saber_status,X
    sta a:object_saber_status,X
    sep #$20
    jsr routine_c8ea69
    lda $9D
    inc
    asl
    asl
    sta a:object_saber_hits,X
    lda a:object_critical_and_saber_level,X
    .a8
    and #$F0
    ora $9D
    sta a:object_critical_and_saber_level,X
    rts
