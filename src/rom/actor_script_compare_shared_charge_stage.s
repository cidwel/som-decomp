; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

jump_actor_script_after_2_bytes = $028D
skip_actor_script_after_2_bytes = $021B

.segment "CODE"
.org $2226
actor_script_compare_shared_charge_stage:
    rep #$20
    tya
    .a16
    and #$0600
    lsr
    xba
    tax
    sep #$20
    lda a:$CC7D,X
    xba
    ldx a:$0144,Y
    lda f:$D04F16,X
    beq actor_script_compare_shared_charge_stage_c1224b
    xba
    cmp a:$019B,Y
    beq actor_script_compare_shared_charge_stage_c12253
    bcc actor_script_compare_shared_charge_stage_c12253
actor_script_compare_shared_charge_stage_c12246:
    jsr skip_actor_script_after_2_bytes
    bra actor_script_compare_shared_charge_stage_c12256
actor_script_compare_shared_charge_stage_c1224b:
    xba
    cmp a:$019B,Y
    beq actor_script_compare_shared_charge_stage_c12246
    bcc actor_script_compare_shared_charge_stage_c12246
actor_script_compare_shared_charge_stage_c12253:
    jsr jump_actor_script_after_2_bytes
actor_script_compare_shared_charge_stage_c12256:
    rts
