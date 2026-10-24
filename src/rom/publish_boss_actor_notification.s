; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-actor-controller.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $35B9
publish_boss_actor_notification:
    lda $87
    sta a:$0360
    rts
