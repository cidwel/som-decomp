; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16

rebuild_actor_stats_public_jump = $C00036

.segment "CODE"
.org $D9CE
rebuild_selected_hero_attributes_for_menu_description:
    rep #$30
    lda a:$1808
    asl
    xba
    .a16
    and #$0600
    tax
    jsl f:rebuild_actor_stats_public_jump
    rts
