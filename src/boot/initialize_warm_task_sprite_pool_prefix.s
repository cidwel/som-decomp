; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-sprite-pool.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eb42b = $B42B

.segment "CODE"
.org $9558
initialize_warm_task_sprite_pool_prefix:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$000C
    tcd
    tcs
    .a16
    lda #$0B01
    jsr routine_7eb42b
