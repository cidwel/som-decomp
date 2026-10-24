; Five frame phases for ordinary bosses, guarded bosses and normal monsters.
.setcpu "65816"
.segment "CODE"
.org $9548
select_first_boss_auxiliary_tiles = $9566
select_second_boss_auxiliary_tiles = $956D
select_third_boss_auxiliary_tiles = $9574
upload_three_hero_normal_tile_tables = $95BC
upload_second_hero_auxiliary_tiles = $99CB
upload_first_boss_normal_tiles = $9D7F
upload_second_boss_normal_tiles = $A185
upload_third_boss_normal_tiles = $A58B
upload_low_monster_normal_tile_tables = $A991
upload_middle_monster_normal_tile_tables = $ABC7
upload_high_monster_normal_tile_tables = $ADFD
ordinary_boss_tile_phases:
    .word upload_first_boss_normal_tiles, upload_second_boss_normal_tiles, upload_third_boss_normal_tiles, upload_three_hero_normal_tile_tables, upload_second_hero_auxiliary_tiles
guarded_boss_tile_phases:
    .word select_first_boss_auxiliary_tiles, select_second_boss_auxiliary_tiles, select_third_boss_auxiliary_tiles, upload_three_hero_normal_tile_tables, upload_second_hero_auxiliary_tiles
monster_tile_phases:
    .word upload_low_monster_normal_tile_tables, upload_middle_monster_normal_tile_tables, upload_high_monster_normal_tile_tables, upload_three_hero_normal_tile_tables, upload_second_hero_auxiliary_tiles
