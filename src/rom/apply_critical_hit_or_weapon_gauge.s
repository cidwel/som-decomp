; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


object_primary_conditions = $E190
object_weapon_gauge = $E1ED
object_weapon_bonus = $E1AE
object_actor_kind = $E1FB
object_critical_rate = $E196
object_agility = $E189

.segment "CODE"
.org $532C
apply_critical_hit_or_weapon_gauge:
    lda a:object_weapon_bonus,Y
    .a8
    bit #$F0
    bne apply_critical_hit_or_weapon_gauge_c0536a
    lda a:object_weapon_gauge,Y
    bne apply_critical_hit_or_weapon_gauge_c05381
    lda a:object_critical_rate,Y
    sta $A4
    lda a:object_primary_conditions,X
    .a8
    bit #$10
    beq apply_critical_hit_or_weapon_gauge_c05346
    asl $A4
apply_critical_hit_or_weapon_gauge_c05346:
    lda a:object_actor_kind,Y
    bpl apply_critical_hit_or_weapon_gauge_c05361
    lda $82
    .a8
    cmp #$01
    bne apply_critical_hit_or_weapon_gauge_c0535a
    lda $A4
    clc
    .a8
    adc #$0A
    sta $A4
    bra apply_critical_hit_or_weapon_gauge_c05361
apply_critical_hit_or_weapon_gauge_c0535a:
    lda $A4
    clc
    .a8
    adc #$05
    sta $A4
apply_critical_hit_or_weapon_gauge_c05361:
    jsl f:$C0389C
    cmp $A4
    bcc apply_critical_hit_or_weapon_gauge_c05372
    rts
apply_critical_hit_or_weapon_gauge_c0536a:
    sec
    .a8
    sbc #$10
    sta a:object_weapon_bonus,Y
    bra apply_critical_hit_or_weapon_gauge_c05372
apply_critical_hit_or_weapon_gauge_c05372:
    jsl f:$C05990
    ldx $85
    ldy $83
    rep #$20
    asl $89
    sep #$20
    rts
apply_critical_hit_or_weapon_gauge_c05381:
    rep #$20
    lsr $89
    stz $CC
    stz $D8
    sep #$20
    stz $CE
    stz $DA
    lda a:object_agility,Y
    sta $AC
    .a8
    lda #$63
    sec
    sbc $AC
    lsr
    clc
    .a8
    adc #$50
    sta $AC
    lda a:object_weapon_gauge,Y
    sta $A8
    lda $AC
    sec
    sbc $A8
    sta f:$004202
    lda $89
    sta f:$004203
    nop
    nop
    nop
    rep #$20
    lda f:$004216
    sta $CC
    sep #$20
    lda $8A
    sta f:$004203
    nop
    nop
    nop
    rep #$20
    lda f:$004216
    clc
    adc $CD
    sta $CD
    sta f:$004204
    sep #$20
    lda $AC
    sta f:$004206
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    rep #$20
    lda f:$004214
    sta $D9
    sep #$20
    lda f:$004216
    xba
    lda $CC
    rep #$20
    sta f:$004204
    sep #$20
    lda $AC
    sta f:$004206
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    rep #$20
    lda f:$004214
    clc
    adc $D8
    sta $89
    sep #$20
    rts
