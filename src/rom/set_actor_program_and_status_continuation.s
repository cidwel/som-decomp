; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

rebuild_hero_for_actor_program = $2599
routine_c12698 = $2698

actor_program_pc_offset = $0144
actor_program_wait_offset = $0146
actor_program_counter_offset = $014C
actor_program_flag_offset = $014E
actor_program_depth_offset = $014F
actor_command_state_offset = $01AC
actor_status_offset = $0190

.segment "CODE"
.org $25B6
set_actor_program_and_status_continuation:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0002
    tcd
    tcs
    lda $03,S
    sep #$20
    phb
    pha
    .a8
    lda #$7E
    pha
    plb
    pla
    rep #$20
    sta $01
    txa
    .a16
    and #$1FFF
    .a16
    ora #$E000
    sta $03
    tay
    .a16
    lda #$FFFF
    sta a:actor_command_state_offset,Y
    lda $01
    sep #$20
    xba
    .a8
    lda #$10
    rep #$20
    sta f:$004202
    pha
    pla
    lda f:$004216
    tax
    lda f:$D00009,X
    sta a:actor_program_pc_offset,Y
    .a16
    lda #$0000
    sta a:actor_program_wait_offset,Y
    sta a:actor_program_counter_offset,Y
    sep #$20
    sta a:actor_program_flag_offset,Y
    sta a:actor_program_depth_offset,Y
    rep #$20
    lda $01
    sec
    .a16
    sbc #$0080
    .a16
    cmp #$0003
    bcs set_actor_program_and_status_continuation_c12629
    lda a:actor_status_offset,Y
    .a16
    and #$5760
    beq set_actor_program_and_status_continuation_c12629
    tyx
    .a16
    lda #$0001
    jsr routine_c12698
set_actor_program_and_status_continuation_c12629:
    lda $01
    ldy $03
    jsr rebuild_hero_for_actor_program
    plb
    sep #$20
    sta $04,S
    pla
    pla
    pla
    pla
    plp
    pld
    rts
