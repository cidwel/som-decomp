; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-child-resources.md.
.setcpu "65816"
.smart
.a8
.i16

construct_first_warm_child_graphics_and_nine_sprites = $B97A

.segment "CODE"
.org $B959
call_first_warm_child_resource_constructor:
    jsr construct_first_warm_child_graphics_and_nine_sprites
