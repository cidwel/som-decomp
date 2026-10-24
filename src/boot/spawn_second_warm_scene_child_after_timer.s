; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-initializer-completion.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eab88 = $AB88

.segment "CODE"
.org $9590
spawn_second_warm_scene_child_after_timer:
    .a16
    lda #$007E
    .i16
    ldx #$60BE
    jsr routine_7eab88
