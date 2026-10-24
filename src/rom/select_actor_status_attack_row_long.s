; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

select_actor_status_attack_row = $E5FF



.segment "CODE"
.org $E5FB
select_actor_status_attack_row_long:
    jsr select_actor_status_attack_row
    rtl
