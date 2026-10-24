; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-shop-wait-copies.md.
.setcpu "65816"
.smart
.a8
.i16

routine_d0d5c1 = $D0D5C1

.segment "CODE"
.org $7EE6
wait_native_dialogue_completion_near_copy_one:
    jsl f:routine_d0d5c1
    rts
