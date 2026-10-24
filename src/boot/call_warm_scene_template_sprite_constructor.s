; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-cluster-setup.md.
.setcpu "65816"
.smart
.a8
.i16

construct_four_warm_scene_template_sprites = $9373

.segment "CODE"
.org $957E
call_warm_scene_template_sprite_constructor:
    jsr construct_four_warm_scene_template_sprites
