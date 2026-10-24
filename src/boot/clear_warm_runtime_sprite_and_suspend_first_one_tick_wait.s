; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-secondary-resources.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eabe7 = $ABE7

.segment "CODE"
.org $95F4
clear_warm_runtime_sprite_and_suspend_first_one_tick_wait:
    stz $01
    stz $02
    .i16
    ldx #$0001
    jsr routine_7eabe7
