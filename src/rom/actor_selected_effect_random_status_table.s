; Three scaled RNG choices, ORed into the target status word.
.setcpu "65816"
.segment "CODE"
.org $E296
actor_selected_effect_random_status_table:
    .word $0200, $1000, $0010
