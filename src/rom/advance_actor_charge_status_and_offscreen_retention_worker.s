; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-charge-frame-workers.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_primary_status_palette = $ED08
advance_actor_secondary_status_palette = $EDD7
retain_or_remove_offscreen_actor_by_native_worker_gates = $FC2E
routine_01833a = $1833A
routine_02c221 = $2C221
routine_c0fbaf = $FBAF

.segment "CODE"
.org $FBB0
advance_actor_charge_status_and_offscreen_retention_worker:
    sep #$20
    lda a:$E000,X
    bmi routine_c0fbaf
    beq routine_c0fbaf
    bit $ED
    bpl advance_actor_charge_status_and_offscreen_retention_worker_c0fbef
    bit $5C
    bmi advance_actor_charge_status_and_offscreen_retention_worker_c0fbdd
    lda a:$E061,X
    beq advance_actor_charge_status_and_offscreen_retention_worker_c0fbca
    jsl f:routine_02c221
advance_actor_charge_status_and_offscreen_retention_worker_c0fbca:
    sep #$20
    lda a:$E1ED,X
    beq advance_actor_charge_status_and_offscreen_retention_worker_c0fbd5
    dec
    sta a:$E1ED,X
advance_actor_charge_status_and_offscreen_retention_worker_c0fbd5:
    lda a:$E100,X
    bpl advance_actor_charge_status_and_offscreen_retention_worker_c0fbdd
    jsr advance_actor_primary_status_palette
advance_actor_charge_status_and_offscreen_retention_worker_c0fbdd:
    lda a:$E104,X
    bpl advance_actor_charge_status_and_offscreen_retention_worker_c0fbe5
    jsr advance_actor_secondary_status_palette
advance_actor_charge_status_and_offscreen_retention_worker_c0fbe5:
    lda a:$E060,X
    beq advance_actor_charge_status_and_offscreen_retention_worker_c0fbef
    jsl f:routine_01833a
    rts
advance_actor_charge_status_and_offscreen_retention_worker_c0fbef:
    sep #$20
    bit $F1
    bvs advance_actor_charge_status_and_offscreen_retention_worker_c0fc1e
    bit $5C
    bmi advance_actor_charge_status_and_offscreen_retention_worker_c0fc1e
    jsr retain_or_remove_offscreen_actor_by_native_worker_gates
    sep #$20
    lda a:$E00A,X
    beq advance_actor_charge_status_and_offscreen_retention_worker_c0fc1f
    dec
    sta a:$E00A,X
    bne advance_actor_charge_status_and_offscreen_retention_worker_c0fc1e
    sta a:$E011,X
    sta a:$E042,X
    sta a:$E006,X
    sta a:$E007,X
    sta a:$E008,X
    sta a:$E064,X
    sta a:$E062,X
advance_actor_charge_status_and_offscreen_retention_worker_c0fc1e:
    rts
advance_actor_charge_status_and_offscreen_retention_worker_c0fc1f:
    lda a:$E064,X
    bmi advance_actor_charge_status_and_offscreen_retention_worker_c0fc2d
    lda a:$E062,X
    beq advance_actor_charge_status_and_offscreen_retention_worker_c0fc2d
    dec
    sta a:$E062,X
advance_actor_charge_status_and_offscreen_retention_worker_c0fc2d:
    rts
