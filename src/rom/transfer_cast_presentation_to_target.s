; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-coordinator.md.
.setcpu "65816"
.smart
.a8
.i16

copy_object_weapon_palette = $859B
load_actor_cast_graphics_by_spell_and_level = $8654
routine_c186da = $86DA

.segment "CODE"
.org $87C2
transfer_cast_presentation_to_target:
    sep #$20
    .a8
    lda #$00
    sta a:$E121,Y
    sta a:$E108,Y
    lda $F1
    bmi transfer_cast_presentation_to_target_c187e3
    lda $D0
    beq transfer_cast_presentation_to_target_c187e4
    .i16
    cpy #$0600
    bcc transfer_cast_presentation_to_target_c187df
    cpy $3A
    bne transfer_cast_presentation_to_target_c187e4
    beq transfer_cast_presentation_to_target_c187e3
transfer_cast_presentation_to_target_c187df:
    cpy $D4
    bne transfer_cast_presentation_to_target_c187e4
transfer_cast_presentation_to_target_c187e3:
    rts
transfer_cast_presentation_to_target_c187e4:
    lda a:$E109,Y
    sta a:$E110,Y
    lda a:$E10B,Y
    xba
    lda a:$E10A,Y
    rep #$20
    pha
    tyx
    jsr load_actor_cast_graphics_by_spell_and_level
    txy
    rep #$20
    pla
    jsr routine_c186da
    tax
    sep #$20
    lda f:$D02AA0,X
    sta a:$E04F,Y
    .a8
    lda #$C0
    sta a:$E060,Y
    lda a:$E01C,Y
    sta a:$E128,Y
    lda a:$E05D,Y
    sta a:$E129,Y
    .a8
    lda #$40
    sta a:$E01C,Y
    .a8
    lda #$00
    sta a:$E114,Y
    sta a:$E05D,Y
    sta a:$E012,Y
    sta a:$E00C,Y
    sta a:$E025,Y
    sta a:$E084,Y
    rep #$20
    lda a:$E104,Y
    sta a:$E12E,Y
    lda a:$E106,Y
    sta a:$E124,Y
    lda a:$E05E,Y
    sta a:$E12A,Y
    lda a:$E006,Y
    sta a:$E134,Y
    lda a:$E008,Y
    sta a:$E122,Y
    lda f:$D02AA6,X
    sta a:$E0FC,Y
    lda f:$D02AA2,X
    sta a:$E06A,Y
    .a16
    lda #$0000
    sta a:$E104,Y
    sta a:$E006,Y
    sta a:$E008,Y
    sta a:$E118,Y
    sta a:$E11A,Y
    sta a:$E11C,Y
    sta a:$E11E,Y
    sep #$20
    lda a:$E110,Y
    .a8
    cmp #$07
    bne transfer_cast_presentation_to_target_c18891
    .a8
    lda #$00
    sta a:$E110,Y
    .a8
    lda #$C0
    sta a:$E11A,Y
    .a8
    lda #$FF
    sta a:$E11B,Y
transfer_cast_presentation_to_target_c18891:
    lda a:$E04F,Y
    tyx
    jmp copy_object_weapon_palette
