; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-action-target-selection.md.
.setcpu "65816"
.smart
.a8
.i16

select_actor_target_and_distance_class = $E4CC

.segment "CODE"
.org $E40E
select_actor_target_and_attack_animation:
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    jsr select_actor_target_and_distance_class
    sta f:$004202
    .a8
    lda #$90
    sta f:$004203
    lda a:$E19B,X
    asl
    asl
    asl
    asl
    sta $00
    stz $01
    lda a:$E000,Y
    beq select_actor_target_and_attack_animation_c1e45c
    bmi select_actor_target_and_attack_animation_c1e45c
    lda a:$E190,Y
    .a8
    bit #$01
    beq select_actor_target_and_attack_animation_c1e43f
    .a8
    lda #$01
    bra select_actor_target_and_attack_animation_c1e44d
select_actor_target_and_attack_animation_c1e43f:
    .a8
    bit #$02
    beq select_actor_target_and_attack_animation_c1e447
    .a8
    lda #$02
    bra select_actor_target_and_attack_animation_c1e44d
select_actor_target_and_attack_animation_c1e447:
    .a8
    bit #$10
    beq select_actor_target_and_attack_animation_c1e453
    .a8
    lda #$03
select_actor_target_and_attack_animation_c1e44d:
    asl
    asl
    ora $00
    sta $00
select_actor_target_and_attack_animation_c1e453:
    lda a:$E1B1,Y
    .a8
    and #$02
    ora $00
    sta $00
select_actor_target_and_attack_animation_c1e45c:
    lda $F4
    .a8
    and #$01
    ora $00
    sta $00
    rep #$20
    tya
    sta a:$E05E,X
    lda f:$004216
    clc
    adc $00
    txy
    tax
    sep #$20
    .i16
    cpy #$0600
    bcc select_actor_target_and_attack_animation_c1e4a7
    lda a:$E180,Y
    sta f:$004202
    .a8
    lda #$20
    sta f:$004203
    lda a:$E1E4,Y
    asl
    lda f:$D10240,X
    rep #$20
    .a16
    and #$00FF
    bcc select_actor_target_and_attack_animation_c1e49a
    clc
    .a16
    adc #$0010
select_actor_target_and_attack_animation_c1e49a:
    adc f:$004216
    tax
    sep #$20
    lda f:$D105C0,X
    bra select_actor_target_and_attack_animation_c1e4c9
select_actor_target_and_attack_animation_c1e4a7:
    lda a:$E068,Y
    sta f:$004202
    .a8
    lda #$28
    sta f:$004203
    lda f:$D10000,X
    rep #$20
    .a16
    and #$00FF
    clc
    adc f:$004216
    tax
    sep #$20
    lda f:$D10480,X
select_actor_target_and_attack_animation_c1e4c9:
    tyx
    plb
    rtl
