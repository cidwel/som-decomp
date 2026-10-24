; Spell handler addresses from the audited numeric table in data/spells.json.
.setcpu "65816"

queue_cure_water_healing = $EBB3
resolve_standard_damage_spell = $EA8B
resolve_speed_down_spell = $EA97
stone_saber_entry = $EAA3
ice_saber_entry = $EAA8
flame_saber_entry = $EAAD
thunder_saber_entry = $EAB2
light_saber_entry = $EAB7
moon_saber_entry = $EABC
apply_speed_up_spell = $EB04
apply_defender_spell = $EB20
resolve_acid_storm_spell = $EB39
queue_energy_absorb_spell = $EB54
resolve_remedy_spell = $EB9F
resolve_fire_bouquet_spell = $EBCA
resolve_blaze_wall_spell = $EBE5
resolve_status_only_spell = $EBF4
resolve_analyzer_spell = $EC00
queue_magic_absorb_spell = $EC3B
apply_lunar_boost_spell = $ECB5
apply_moon_energy_spell = $ECD1
apply_weapon_magic_first_timer = $ECEA
resolve_revivifier_spell = $ED04
apply_wall_spell = $ED53
apply_weapon_magic_second_timer = $ED68
queue_evil_gate_spell = $ED82
resolve_dispel_magic_spell = $EDCB
apply_lucid_barrier_spell = $EEB7
dispatch_lunar_magic_effect = $EEF5

.segment "CODE"
.org $E801
spell_handler_table:
    .word resolve_standard_damage_spell             ; spell00
    .word resolve_standard_damage_spell             ; spell01
    .word resolve_speed_down_spell             ; spell02
    .word stone_saber_entry             ; spell03
    .word apply_speed_up_spell             ; spell04
    .word apply_defender_spell             ; spell05
    .word resolve_standard_damage_spell             ; spell06
    .word resolve_acid_storm_spell             ; spell07
    .word queue_energy_absorb_spell             ; spell08
    .word ice_saber_entry             ; spell09
    .word resolve_remedy_spell             ; spell0A
    .word queue_cure_water_healing             ; spell0B
    .word resolve_standard_damage_spell             ; spell0C
    .word resolve_standard_damage_spell             ; spell0D
    .word resolve_standard_damage_spell             ; spell0E
    .word flame_saber_entry             ; spell0F
    .word resolve_fire_bouquet_spell             ; spell10
    .word resolve_blaze_wall_spell             ; spell11
    .word resolve_standard_damage_spell             ; spell12
    .word resolve_standard_damage_spell             ; spell13
    .word resolve_status_only_spell             ; spell14
    .word thunder_saber_entry             ; spell15
    .word resolve_status_only_spell             ; spell16
    .word resolve_analyzer_spell             ; spell17
    .word resolve_status_only_spell             ; spell18
    .word queue_magic_absorb_spell             ; spell19
    .word dispatch_lunar_magic_effect             ; spell1A
    .word moon_saber_entry             ; spell1B
    .word apply_lunar_boost_spell             ; spell1C
    .word apply_moon_energy_spell             ; spell1D
    .word resolve_status_only_spell             ; spell1E
    .word resolve_standard_damage_spell             ; spell1F
    .word apply_weapon_magic_first_timer             ; spell20
    .word resolve_revivifier_spell             ; spell21
    .word apply_wall_spell             ; spell22
    .word apply_weapon_magic_second_timer             ; spell23
    .word queue_evil_gate_spell             ; spell24
    .word resolve_standard_damage_spell             ; spell25
    .word resolve_dispel_magic_spell             ; spell26
    .word light_saber_entry             ; spell27
    .word resolve_standard_damage_spell             ; spell28
    .word apply_lucid_barrier_spell             ; spell29
