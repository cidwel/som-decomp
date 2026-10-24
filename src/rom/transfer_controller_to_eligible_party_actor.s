; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-controller-cycle.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c0bdb0 = $BDB0
wait_for_nmi_and_update_controller_hud = $BF38

.segment "CODE"
.org $BD3D
transfer_controller_to_eligible_party_actor:
    lda a:$E000,X
    beq transfer_controller_to_eligible_party_actor_c0bd8f
    bmi transfer_controller_to_eligible_party_actor_c0bd8f
    rep #$20
    lda a:$E190,X
    .a16
    and #$C160
    sep #$20
    bne transfer_controller_to_eligible_party_actor_c0bd8f
    lda a:$E02C,X
    ora a:$E08C,X
    bne transfer_controller_to_eligible_party_actor_c0bd8f
    stx $00
    lda $01
    bne transfer_controller_to_eligible_party_actor_c0bd5f
    inc
transfer_controller_to_eligible_party_actor_c0bd5f:
    sta a:$00D9,Y
    tya
    inc
    .a8
    cmp #$03
    bne transfer_controller_to_eligible_party_actor_c0bd6a
    .a8
    lda #$04
transfer_controller_to_eligible_party_actor_c0bd6a:
    sta a:$E02C,X
    .a8
    lda #$00
    sta a:$E013,X
    ldx $04
    stz a:$E02C,X
    lda a:$E08C,X
    stz a:$E08C,X
    bne transfer_controller_to_eligible_party_actor_c0bd84
    jsr routine_c0bdb0
    sep #$20
transfer_controller_to_eligible_party_actor_c0bd84:
    phb
    .a8
    lda #$00
    pha
    plb
    jsr wait_for_nmi_and_update_controller_hud
    plb
    sec
    rts
transfer_controller_to_eligible_party_actor_c0bd8f:
    clc
    rts
