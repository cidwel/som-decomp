; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-sprite-pool.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_warm_task_sprite_pool_prefix = $9558

.segment "CODE"
.org $934F
enter_warm_task_resource_initializer:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    jsr initialize_warm_task_sprite_pool_prefix
