; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-child-launch.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eab88 = $AB88

.segment "CODE"
.org $9581
spawn_first_warm_scene_child:
    .a16
    lda #$007E
    .i16
    ldx #$601E
    jsr routine_7eab88
