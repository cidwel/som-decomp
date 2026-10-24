; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-sprite-setup.md.
.setcpu "65816"
.smart
.a8
.i16

construct_sixteen_warm_scene_sprites = $945D

.segment "CODE"
.org $957B
call_warm_scene_sprite_constructor:
    jsr construct_sixteen_warm_scene_sprites
