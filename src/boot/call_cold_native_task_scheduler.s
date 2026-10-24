; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-scheduler-cycle.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7ea88f = $A88F

.segment "CODE"
.org $AF16
call_cold_native_task_scheduler:
    jsr routine_7ea88f
