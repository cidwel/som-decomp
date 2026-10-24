; Nine Lunar Magic effect pointers; only indices0..7 are selected by rnd(8).
.setcpu "65816"

lunar_heal_all_living_actors = $EF2B
lunar_buff_target = $EF48
lunar_debuff_target = $EF5E
lunar_silence_all_actors = $EF74
lunar_set_status_1000_all_actors = $EF8A
lunar_set_status_0200_heroes = $EFA0
lunar_set_status_0800_monsters = $EFB6
lunar_sleep_all_actors = $EFD0
lunar_halve_caster_maximum_mp = $EFE6

.segment "CODE"
.org $EF19
lunar_effect_table:
    .word lunar_heal_all_living_actors
    .word lunar_buff_target
    .word lunar_debuff_target
    .word lunar_silence_all_actors
    .word lunar_set_status_1000_all_actors
    .word lunar_set_status_0200_heroes
    .word lunar_set_status_0800_monsters
    .word lunar_sleep_all_actors
    .word lunar_halve_caster_maximum_mp
