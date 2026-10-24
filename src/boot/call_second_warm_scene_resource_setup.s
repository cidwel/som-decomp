; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-secondary-resources.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_second_warm_scene_resources_and_colour_registers = $CAF8

.segment "CODE"
.org $CA4C
call_second_warm_scene_resource_setup:
    jsr initialize_second_warm_scene_resources_and_colour_registers
