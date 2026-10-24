; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $47DD
classify_actor_appearance_from_sprite:
    lda a:$E180,X
    rep #$20
    .a16
    and #$00FF
    asl
    asl
    asl
    asl
    tax
    sep #$20
    lda f:$D0000F,X
    ldx $BD
    sta a:$E1AF,X
    lda a:$E1FB,X
    .a8
    and #$0E
    sta a:$E1FB,X
    lda a:$E1E7,X
    bmi classify_actor_appearance_from_sprite_c04841
    .a8
    cmp #$2E
    beq classify_actor_appearance_from_sprite_c04810
    .a8
    cmp #$3F
    beq classify_actor_appearance_from_sprite_c04810
    .a8
    cmp #$20
    beq classify_actor_appearance_from_sprite_c04810
    bra classify_actor_appearance_from_sprite_c04819
classify_actor_appearance_from_sprite_c04810:
    lda a:$E1FB,X
    .a8
    ora #$01
    sta a:$E1FB,X
    rts
classify_actor_appearance_from_sprite_c04819:
    lda a:$CFFB
    sta a:$E1E6,X
    lda a:$E1E7,X
    .a8
    cmp #$57
    bcc classify_actor_appearance_from_sprite_c0482f
    lda a:$E1FB,X
    .a8
    ora #$40
    sta a:$E1FB,X
classify_actor_appearance_from_sprite_c0482e:
    rts
classify_actor_appearance_from_sprite_c0482f:
    .a8
    cmp #$55
    bcc classify_actor_appearance_from_sprite_c0482e
    lda a:$E1FB,X
    .a8
    ora #$10
    sta a:$E1FB,X
    .a8
    lda #$20
    sta a:$E190,X
    rts
classify_actor_appearance_from_sprite_c04841:
    lda a:$E1E7,X
    .a8
    cmp #$83
    bcs classify_actor_appearance_from_sprite_c04857
    lda a:$E1FB,X
    .a8
    ora #$80
    sta a:$E1FB,X
    lda a:$CFFC
    sta a:$E1E6,X
    rts
classify_actor_appearance_from_sprite_c04857:
    lda a:$E1FB,X
    .a8
    ora #$20
    sta a:$E1FB,X
    rts
