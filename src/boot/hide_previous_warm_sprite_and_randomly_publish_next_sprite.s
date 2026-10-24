; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-secondary-resources.md.
.setcpu "65816"
.smart
.a8
.i16

draw_warm_runtime_eight_way_task_spawn_gate = $9633
routine_0095f8 = $95F8
routine_7eb7b9 = $B7B9
routine_7ec288 = $C288

.segment "CODE"
.org $95FE
hide_previous_warm_sprite_and_randomly_publish_next_sprite:
    ldx $01
    beq hide_previous_warm_sprite_and_randomly_publish_next_sprite_960c
    stz a:$0003,X
    jsr routine_7eb7b9
    stz $01
    stz $02
hide_previous_warm_sprite_and_randomly_publish_next_sprite_960c:
    .a8
    lda #$00
    jsr routine_7ec288
    .a8
    cmp #$10
    beq draw_warm_runtime_eight_way_task_spawn_gate
    bcs routine_0095f8
    asl
    rep #$20
    .a16
    and #$00FF
    clc
    adc a:$007C
    tay
    sep #$20
    ldx a:$0000,Y
    stx $01
    .a8
    lda #$01
    sta a:$0003,X
    jsr routine_7eb7b9
    bra routine_0095f8
