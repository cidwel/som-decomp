; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-scheduler-cycle.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00af0b = $AF0B
routine_7eae28 = $AE28

.segment "CODE"
.org $AF36
return_warm_scheduler_through_reserved_api_and_restart_cold_boot:
    jsr routine_7eae28
    jmp routine_00af0b
