; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-attack-entry.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B29F
select_controller_actor_and_begin_attack_variant:
    rep #$10
    .a8
    and #$06
    xba
    .a8
    lda #$00
    tax
