; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-particle.md.
.setcpu "65816"
.smart
.a8
.i16

routine_0095f8 = $95F8
routine_7eab88 = $AB88

.segment "CODE"
.org $963C
spawn_warm_particle_task_and_repeat_runtime_wait:
    .a8
    lda #$7E
    .i16
    ldx #$6014
    jsr routine_7eab88
    bra routine_0095f8
