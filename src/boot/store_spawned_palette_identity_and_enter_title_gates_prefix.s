; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-coordinator-live-aux-exit-parallel-coordinator-accept-prefix.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7ed23e = $D23E
routine_7ed445 = $D445

.segment "CODE"
.org $D484
store_spawned_palette_identity_and_enter_title_gates_prefix:
    sta a:$0315
    stz a:$0316
    jsr routine_7ed445
    jsr routine_7ed23e
