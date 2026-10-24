; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-party-obstacle-detour.md.
.setcpu "65816"
.smart
.a8
.i16

advance_all_normal_charge_workers_with_native_actor_loop = $FB8F
advance_three_hero_charge_workers_after_link_preparation = $EB18
update_native_two_partners_from_selected_leader = $EE8C

.segment "CODE"
.org $EB06
advance_native_charge_and_partner_follow_frame:
    sep #$30
    phb
    .a8
    lda #$7E
    pha
    plb
    jsr advance_three_hero_charge_workers_after_link_preparation
    jsr update_native_two_partners_from_selected_leader
    jsr advance_all_normal_charge_workers_with_native_actor_loop
    plb
    rts
