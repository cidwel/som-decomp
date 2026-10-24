; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-graphics-prefix.md.
.setcpu "65816"
.smart
.a8
.i16

enter_warm_graphics_resource_constructor = $93F4

.segment "CODE"
.org $9578
call_warm_graphics_resource_constructor:
    jsr enter_warm_graphics_resource_constructor
