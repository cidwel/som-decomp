; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-queued-effect-requests.md.
.setcpu "65816"
.smart
.a8
.i16

load_object_weapon_palette_from_field_04f = $85D8
load_queued_native_motion_presentation_graphics = $86C6
routine_02b49c = $2B49C

.segment "CODE"
.org $DC48
prepare_queued_native_motion_presentation:
    lda a:$19F3
    .a8
    and #$03
    asl
    xba
    .a8
    lda #$00
    tay
    sep #$20
    lda a:$E060,Y
    beq prepare_queued_native_motion_presentation_c1dc5a
    rts
prepare_queued_native_motion_presentation_c1dc5a:
    .a8
    lda #$00
    sta a:$E110,Y
    sta a:$E108,Y
    lda a:$19F1
    sta a:$E121,Y
    lda a:$19F2
    .a8
    and #$03
    asl
    xba
    .a8
    lda #$00
    rep #$20
    sta a:$E10C,Y
    lda a:$19F1
    .a16
    and #$00FF
    asl
    asl
    asl
    asl
    tax
    phx
    phy
    jsr load_queued_native_motion_presentation_graphics
    ply
    plx
    jsl f:routine_02b49c
    jmp load_object_weapon_palette_from_field_04f
