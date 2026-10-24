; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4EA9
select_zero_hp_actor_impact_motion:
    sep #$20
    lda $A4
    inc
    sta a:$E1E5,X
    .a8
    lda #$02
    sta a:$E190,X
    .a8
    lda #$20
    sta a:$E1B4,X
    rts
