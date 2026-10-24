; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-charge-worker-offscreen.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FC2E
retain_or_remove_offscreen_actor_by_native_worker_gates:
    sep #$20
    lda a:$E044,X
    .a8
    and #$40
    bne retain_or_remove_offscreen_actor_by_native_worker_gates_c0fc4e
    lda $D0
    bne retain_or_remove_offscreen_actor_by_native_worker_gates_c0fc4e
    cpx $3A
    beq retain_or_remove_offscreen_actor_by_native_worker_gates_c0fc4e
    lda $BC
    bit $ED
    bpl retain_or_remove_offscreen_actor_by_native_worker_gates_c0fc4a
    .a8
    cmp #$04
    bcs retain_or_remove_offscreen_actor_by_native_worker_gates_c0fc4f
    rts
retain_or_remove_offscreen_actor_by_native_worker_gates_c0fc4a:
    .a8
    cmp #$0A
    bcs retain_or_remove_offscreen_actor_by_native_worker_gates_c0fc4f
retain_or_remove_offscreen_actor_by_native_worker_gates_c0fc4e:
    rts
retain_or_remove_offscreen_actor_by_native_worker_gates_c0fc4f:
    stz a:$E043,X
    rep #$20
    lda a:$E020,X
    bmi retain_or_remove_offscreen_actor_by_native_worker_gates_c0fc61
    .a16
    cmp #$0140
    bcc retain_or_remove_offscreen_actor_by_native_worker_gates_c0fc66
retain_or_remove_offscreen_actor_by_native_worker_gates_c0fc5e:
    brl retain_or_remove_offscreen_actor_by_native_worker_gates_c0fc78
retain_or_remove_offscreen_actor_by_native_worker_gates_c0fc61:
    .a16
    cmp #$FFC0
    bcc retain_or_remove_offscreen_actor_by_native_worker_gates_c0fc5e
retain_or_remove_offscreen_actor_by_native_worker_gates_c0fc66:
    lda a:$E022,X
    bmi retain_or_remove_offscreen_actor_by_native_worker_gates_c0fc72
    .a16
    cmp #$0120
    bcc retain_or_remove_offscreen_actor_by_native_worker_gates_c0fc77
    bcs retain_or_remove_offscreen_actor_by_native_worker_gates_c0fc5e
retain_or_remove_offscreen_actor_by_native_worker_gates_c0fc72:
    .a16
    cmp #$FFC0
    bcc retain_or_remove_offscreen_actor_by_native_worker_gates_c0fc5e
retain_or_remove_offscreen_actor_by_native_worker_gates_c0fc77:
    rts
retain_or_remove_offscreen_actor_by_native_worker_gates_c0fc78:
    sep #$20
    lda a:$E032,X
    beq retain_or_remove_offscreen_actor_by_native_worker_gates_c0fc86
    stz a:$E000,X
    stz a:$E032,X
    rts
retain_or_remove_offscreen_actor_by_native_worker_gates_c0fc86:
    .a8
    lda #$01
    sta a:$E043,X
    rts
