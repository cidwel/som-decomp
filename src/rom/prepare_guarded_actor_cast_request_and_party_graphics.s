; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-request-setup.md.
.setcpu "65816"
.smart
.a8
.i16

load_actor_cast_secondary_graphics = $8634
load_object_weapon_palette_from_field_04f = $85D8
prepare_actor_cast_directional_offset = $8898

.segment "CODE"
.org $88C7
prepare_guarded_actor_cast_request_and_party_graphics:
    sep #$20
    stx $14
    bit $F1
    bmi prepare_guarded_actor_cast_request_and_party_graphics_c188e3
    lda $D0
    beq prepare_guarded_actor_cast_request_and_party_graphics_c188d7
    cpx $D4
    beq prepare_guarded_actor_cast_request_and_party_graphics_c188e3
prepare_guarded_actor_cast_request_and_party_graphics_c188d7:
    lda a:$E000,X
    beq prepare_guarded_actor_cast_request_and_party_graphics_c188e3
    bmi prepare_guarded_actor_cast_request_and_party_graphics_c188e3
    lda a:$E060,X
    beq prepare_guarded_actor_cast_request_and_party_graphics_c188e4
prepare_guarded_actor_cast_request_and_party_graphics_c188e3:
    rts
prepare_guarded_actor_cast_request_and_party_graphics_c188e4:
    stz a:$E111,X
    lda a:$E179,X
    ora a:$E17A,X
    .a8
    and #$07
    beq prepare_guarded_actor_cast_request_and_party_graphics_c188f6
    .a8
    lda #$80
    sta a:$E111,X
prepare_guarded_actor_cast_request_and_party_graphics_c188f6:
    lda a:$E171,X
    .a8
    and #$0F
    ora a:$E111,X
    sta a:$E111,X
    stz a:$E108,X
    .i16
    cpx #$0600
    bcc prepare_guarded_actor_cast_request_and_party_graphics_c18918
    jsr prepare_actor_cast_directional_offset
    sep #$20
    .a8
    lda #$20
    sta a:$E060,X
    rep #$10
    ldx $14
    rts
prepare_guarded_actor_cast_request_and_party_graphics_c18918:
    sep #$20
    .a8
    lda #$CE
    .i16
    cpx #$0400
    bcc prepare_guarded_actor_cast_request_and_party_graphics_c18922
    inc
prepare_guarded_actor_cast_request_and_party_graphics_c18922:
    sta a:$E04F,X
    .a8
    lda #$40
    sta a:$E01C,X
    .a8
    lda #$FF
    sta a:$E030,X
    .a8
    lda #$94
    sta a:$E011,X
    stz a:$E006,X
    stz a:$E007,X
    stz a:$E008,X
    .a8
    lda #$20
    sta a:$E060,X
    jsr load_actor_cast_secondary_graphics
    jsr load_object_weapon_palette_from_field_04f
    rep #$10
    ldx $14
    rts
