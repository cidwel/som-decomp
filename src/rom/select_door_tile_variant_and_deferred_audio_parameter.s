; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-map-door-controller.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $BAD5
select_door_tile_variant_and_deferred_audio_parameter:
    .a8
    cmp #$05
    beq select_door_tile_variant_and_deferred_audio_parameter_c0bb0c
    .a8
    cmp #$06
    beq select_door_tile_variant_and_deferred_audio_parameter_c0bb05
    .a8
    cmp #$07
    beq select_door_tile_variant_and_deferred_audio_parameter_c0bafe
    .a8
    cmp #$08
    beq select_door_tile_variant_and_deferred_audio_parameter_c0baf7
    .a8
    cmp #$09
    beq select_door_tile_variant_and_deferred_audio_parameter_c0baf0
    .a8
    lda #$01
    xba
    .a8
    lda #$EC
    bra select_door_tile_variant_and_deferred_audio_parameter_c0bb11
select_door_tile_variant_and_deferred_audio_parameter_c0baf0:
    .a8
    lda #$00
    xba
    .a8
    lda #$EB
    bra select_door_tile_variant_and_deferred_audio_parameter_c0bb11
select_door_tile_variant_and_deferred_audio_parameter_c0baf7:
    .a8
    lda #$03
    xba
    .a8
    lda #$EB
    bra select_door_tile_variant_and_deferred_audio_parameter_c0bb11
select_door_tile_variant_and_deferred_audio_parameter_c0bafe:
    .a8
    lda #$02
    xba
    .a8
    lda #$EA
    bra select_door_tile_variant_and_deferred_audio_parameter_c0bb11
select_door_tile_variant_and_deferred_audio_parameter_c0bb05:
    .a8
    lda #$01
    xba
    .a8
    lda #$E9
    bra select_door_tile_variant_and_deferred_audio_parameter_c0bb11
select_door_tile_variant_and_deferred_audio_parameter_c0bb0c:
    .a8
    lda #$00
    xba
    .a8
    lda #$E8
select_door_tile_variant_and_deferred_audio_parameter_c0bb11:
    sta $95
    lda f:$7EE020,X
    .a8
    and #$F0
    sta a:$0118
    lsr
    lsr
    lsr
    lsr
    ora a:$0118
    sta a:$0119
    rts
