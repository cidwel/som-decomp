; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-queued-effect-requests.md.
.setcpu "65816"
.smart
.a8
.i16

clear_actor_movement_charge_and_palette_effects = $CA6C
load_object_weapon_palette_from_field_04f = $85D8
prepare_queued_native_motion_presentation = $DC48
routine_01c599 = $1C599
routine_01e76d = $1E76D

.segment "CODE"
.org $DBC6
consume_queued_motion_or_map_scroll_request:
    lda a:$19F1
    .a8
    cmp #$07
    bne consume_queued_motion_or_map_scroll_request_c1dc31
    lda a:$19F2
    .a8
    and #$03
    asl
    xba
    .a8
    lda #$00
    tax
    stx $14
    jsr clear_actor_movement_charge_and_palette_effects
    .a8
    lda #$7F
    sta a:$E04F,X
    stz a:$E104,X
    .a8
    lda #$05
    sta a:$E02F,X
    stz a:$E00C,X
    stz a:$E084,X
    stz a:$E006
    stz a:$E007
    stz a:$E206
    stz a:$E207
    stz a:$E406
    stz a:$E407
    lda $F4
    .a8
    and #$1F
    .a8
    ora #$20
    sta $F4
    jsr load_object_weapon_palette_from_field_04f
    rep #$30
    .a16
    lda #$0040
    sta $08
    .a16
    lda #$0000
    sta $00
    .i16
    ldy #$2850
    .a16
    lda #$00D4
    jsl f:routine_01c599
    rep #$20
    lda $DC
    .a16
    and #$00FF
    .a16
    ora #$0C00
    jsl f:routine_01e76d
    rts
consume_queued_motion_or_map_scroll_request_c1dc31:
    phx
    jsr prepare_queued_native_motion_presentation
    plx
    rts
