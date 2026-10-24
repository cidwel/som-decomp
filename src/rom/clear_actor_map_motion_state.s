; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A2E8
clear_actor_map_motion_state:
    rep #$20
    .a16
    lda #$0000
    sta a:$E006,X
    sta a:$E008,X
    sta a:$E00A,X
    sta a:$E010,X
    sta a:$E012,X
    sta a:$E014,X
    sta a:$E016,X
    sta a:$E018,X
    sta a:$E01A,X
    sta a:$E01C,X
    sta a:$E01E,X
    sta a:$E020,X
    sta a:$E022,X
    sta a:$E02C,X
    sta a:$E02E,X
    sta a:$E030,X
    sta a:$E036,X
    sta a:$E038,X
    sta a:$E040,X
    sta a:$E042,X
    sta a:$E044,X
    sta a:$E046,X
    sta a:$E048,X
    sta a:$E04A,X
    sta a:$E04C,X
    sta a:$E04E,X
    sta a:$E050,X
    sta a:$E052,X
    sta a:$E054,X
    sta a:$E056,X
    sta a:$E058,X
    sta a:$E060,X
    sta a:$E083,X
    sta a:$E100,X
    sta a:$E104,X
    sta a:$E108,X
    .a16
    lda #$00FF
    sta a:$E030,X
    rtl
