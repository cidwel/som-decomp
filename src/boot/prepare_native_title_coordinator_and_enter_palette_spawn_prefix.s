; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-coordinator-live-aux-exit-parallel-coordinator-prefix.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eab88 = $AB88

.segment "CODE"
.org $D473
prepare_native_title_coordinator_and_enter_palette_spawn_prefix:
    phd
    php
    rep #$30
    phx
    tsc
    tcd
    sep #$20
    .a8
    lda #$7E
    .i16
    ldx #$649C
    jsr routine_7eab88
