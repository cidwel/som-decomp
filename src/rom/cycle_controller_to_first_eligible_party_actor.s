; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-controller-cycle.md.
.setcpu "65816"
.smart
.a8
.i16

transfer_controller_to_eligible_party_actor = $BD3D

.segment "CODE"
.org $BCF3
cycle_controller_to_first_eligible_party_actor:
    sep #$20
    rep #$10
    stz $00
    stz $02
    stz $04
    phb
    .a8
    lda #$7E
    pha
    plb
    lda a:$00D9,Y
    lsr
    bcs cycle_controller_to_first_eligible_party_actor_c0bd23
    lsr
    bcs cycle_controller_to_first_eligible_party_actor_c0bd17
    .a8
    lda #$00
    sta $01
    .a8
    lda #$02
    sta $03
    .a8
    lda #$04
    bra cycle_controller_to_first_eligible_party_actor_c0bd2d
cycle_controller_to_first_eligible_party_actor_c0bd17:
    .a8
    lda #$04
    sta $01
    .a8
    lda #$00
    sta $03
    .a8
    lda #$02
    bra cycle_controller_to_first_eligible_party_actor_c0bd2d
cycle_controller_to_first_eligible_party_actor_c0bd23:
    .a8
    lda #$02
    sta $01
    .a8
    lda #$04
    sta $03
    .a8
    lda #$00
cycle_controller_to_first_eligible_party_actor_c0bd2d:
    sta $05
    ldx $00
    jsr transfer_controller_to_eligible_party_actor
    bcs cycle_controller_to_first_eligible_party_actor_c0bd3b
    ldx $02
    jsr transfer_controller_to_eligible_party_actor
cycle_controller_to_first_eligible_party_actor_c0bd3b:
    plb
    rts
