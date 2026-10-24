; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-shop-wait-copies.md.
.setcpu "65816"
.smart
.a8
.i16

routine_d0d5c1 = $D0D5C1

.segment "CODE"
.org $7EF0
wait_native_dialogue_completion_near_copy_two:
    jsl f:routine_d0d5c1
    rts
