; Recovered Secret of Mana USA routine; behaviour documented in docs/hero-controller-action-gates.md.
.setcpu "65816"
.smart
.a8
.i16

clear_actor_status_four_and_refresh_live_weapon_graphics = $AFE3

.segment "CODE"
.org $AFD0
refresh_all_three_party_status_cancelled_weapons:
    .i16
    ldx #$0000
    jsr clear_actor_status_four_and_refresh_live_weapon_graphics
    .i16
    ldx #$0200
    jsr clear_actor_status_four_and_refresh_live_weapon_graphics
    .i16
    ldx #$0400
    jsr clear_actor_status_four_and_refresh_live_weapon_graphics
    rtl
