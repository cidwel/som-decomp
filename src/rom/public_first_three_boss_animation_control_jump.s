; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-public-party-services.md.
.setcpu "65816"
.smart
.a8
.i16

notify_control40_bosses_with_animation57_through7F = $0396

.segment "CODE"
.org $0018
public_first_three_boss_animation_control_jump:
    jmp notify_control40_bosses_with_animation57_through7F
