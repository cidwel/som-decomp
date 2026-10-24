; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-weapon-restore.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00e9f4 = $E9F4

.segment "CODE"
.org $8DAB
restore_actor_weapon_after_cast:
    sep #$20
    .i16
    cpx #$0600
    bcc restore_actor_weapon_after_cast_c18db6
    bit $5C
    bmi restore_actor_weapon_after_cast_c18dbf
restore_actor_weapon_after_cast_c18db6:
    jsl f:routine_00e9f4
    rep #$10
    ldx $14
    rts
restore_actor_weapon_after_cast_c18dbf:
    .a8
    lda #$02
    sta a:$E001,X
    rts
