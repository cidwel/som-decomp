; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-charge-frame-workers.md.
.setcpu "65816"
.smart
.a8
.i16

advance_actor_primary_status_palette = $ED08
advance_actor_secondary_status_palette = $EDD7
present_actor_charge_gauge_and_deferred_flash = $EBB6
routine_01833a = $1833A
routine_02c221 = $2C221
routine_c0eb35 = $EB35

.segment "CODE"
.org $EB36
advance_hero_charge_gauge_status_and_visual_effect_worker:
    sep #$20
    lda a:$E00F,X
    bne routine_c0eb35
    lda a:$E000,X
    beq routine_c0eb35
    bmi routine_c0eb35
    lda a:$E061,X
    beq advance_hero_charge_gauge_status_and_visual_effect_worker_c0eb4d
    jsl f:routine_02c221
advance_hero_charge_gauge_status_and_visual_effect_worker_c0eb4d:
    sep #$20
    lda a:$E1ED,X
    beq advance_hero_charge_gauge_status_and_visual_effect_worker_c0eb68
    sta $00
    lda a:$E01C,X
    .a8
    bit #$A0
    bne advance_hero_charge_gauge_status_and_visual_effect_worker_c0eb68
    lda $00
    dec
    sta a:$E1ED,X
    jsr present_actor_charge_gauge_and_deferred_flash
    sep #$20
advance_hero_charge_gauge_status_and_visual_effect_worker_c0eb68:
    lda a:$E100,X
    bpl advance_hero_charge_gauge_status_and_visual_effect_worker_c0eb70
    jsr advance_actor_primary_status_palette
advance_hero_charge_gauge_status_and_visual_effect_worker_c0eb70:
    lda a:$E104,X
    bpl advance_hero_charge_gauge_status_and_visual_effect_worker_c0eb78
    jsr advance_actor_secondary_status_palette
advance_hero_charge_gauge_status_and_visual_effect_worker_c0eb78:
    lda a:$E060,X
    beq advance_hero_charge_gauge_status_and_visual_effect_worker_c0eb82
    jsl f:routine_01833a
    rts
advance_hero_charge_gauge_status_and_visual_effect_worker_c0eb82:
    bit $F1
    bvs advance_hero_charge_gauge_status_and_visual_effect_worker_c0eba6
    lda a:$E00A,X
    beq advance_hero_charge_gauge_status_and_visual_effect_worker_c0eba7
    dec
    sta a:$E00A,X
    bne advance_hero_charge_gauge_status_and_visual_effect_worker_c0eba6
    sta a:$E011,X
    sta a:$E042,X
    sta a:$E006,X
    sta a:$E007,X
    sta a:$E008,X
    sta a:$E064,X
    sta a:$E062,X
advance_hero_charge_gauge_status_and_visual_effect_worker_c0eba6:
    rts
advance_hero_charge_gauge_status_and_visual_effect_worker_c0eba7:
    lda a:$E064,X
    bmi advance_hero_charge_gauge_status_and_visual_effect_worker_c0ebb5
    lda a:$E062,X
    beq advance_hero_charge_gauge_status_and_visual_effect_worker_c0ebb5
    dec
    sta a:$E062,X
advance_hero_charge_gauge_status_and_visual_effect_worker_c0ebb5:
    rts
