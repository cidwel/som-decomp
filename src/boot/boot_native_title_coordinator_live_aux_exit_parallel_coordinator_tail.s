; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-coordinator-live-aux-exit-parallel-coordinator-tail.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eacac = $ACAC
routine_7ed3aa = $D3AA

.segment "CODE"
.org $D519
finish_produced_title_peer_stop_requests_and_return_coordinator:
    lda a:$0311
    beq finish_produced_title_peer_stop_requests_and_return_coordinator_d527
    jsr routine_7eacac
    lda a:$0312
    jsr routine_7eacac
finish_produced_title_peer_stop_requests_and_return_coordinator_d527:
    jsr routine_7ed3aa
    pla
    pla
    plp
    pld
    rts
