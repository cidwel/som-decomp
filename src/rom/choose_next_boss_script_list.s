; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-actor-controller.md.
.setcpu "65816"
.smart
.a8
.i16

choose_script_with_hp_action_and_nonlocal_death_gate = $35CC

.segment "CODE"
.org $3551
choose_next_boss_script_list:
    ldx $87
    jsr choose_script_with_hp_action_and_nonlocal_death_gate
    ldx $87
    sta a:$00B0,X
    stz a:$00B2,X
    inc a:$0094,X
