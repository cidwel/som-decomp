; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

apply_actor_status_and_timers = $C8E301
rebuild_actor_stats_and_record_status_change_flags = $3E80
routine_c03b08 = $3B08

.segment "CODE"
.org $3A3A
initialize_actor_combat_controller_and_status:
    .a16
    lda #$0300
    tcd
    txa
    .a16
    and #$1FFF
    sta $85
    tax
    sep #$20
    xba
    lsr
    sta $81
    lda a:$00D9
    bne initialize_actor_combat_controller_and_status_c03a64
    lda a:$00DA
    bne initialize_actor_combat_controller_and_status_c03a64
    lda a:$00DB
    bne initialize_actor_combat_controller_and_status_c03a64
    .a8
    lda #$81
    sta a:$00D9
    .a8
    lda #$01
    sta a:$E02C
initialize_actor_combat_controller_and_status_c03a64:
    jsl f:apply_actor_status_and_timers
    jsr rebuild_actor_stats_and_record_status_change_flags
    lda a:$E1FA,X
    beq initialize_actor_combat_controller_and_status_c03a76
    stz a:$E1FA,X
    tax
    .a8
    lda #$04
initialize_actor_combat_controller_and_status_c03a76:
    jmp routine_c03b08
