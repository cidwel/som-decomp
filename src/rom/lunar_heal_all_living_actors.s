; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16


object_pending_heal = $E1F3
object_max_hp = $E184
object_status_high = $E191

.segment "CODE"
.org $EF2B
lunar_heal_all_living_actors:
    .i16
    ldy #$0A00
    sty $CC
lunar_heal_all_living_actors_c8ef30:
    ldy $CC
    lda a:object_status_high,Y
    bmi lunar_heal_all_living_actors_c8ef41
    rep #$20
    lda a:object_max_hp,Y
    sta a:object_pending_heal,Y
    sep #$20
lunar_heal_all_living_actors_c8ef41:
    dec $CD
    dec $CD
    bpl lunar_heal_all_living_actors_c8ef30
    rts
