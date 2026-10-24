; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

release_first_party_controller = $BD91
release_second_party_controller = $BD98
release_third_party_controller = $BD9F
routine_02b59d = $2B59D
routine_02b5c9 = $2B5C9
routine_c0bdc9 = $BDC9

.segment "CODE"
.org $BDD0
select_or_release_controller_actor:
    beq select_or_release_controller_actor_c0bdf0
    stx $00
    dec
    .a8
    cmp #$03
    bne select_or_release_controller_actor_c0bddb
    .a8
    lda #$04
select_or_release_controller_actor_c0bddb:
    asl
    xba
    .a8
    lda #$00
    rep #$10
    tax
    lda f:$7EE01C,X
    ora f:$7EE060,X
    sep #$10
    bne routine_c0bdc9
    ldx $00
select_or_release_controller_actor_c0bdf0:
    ldy $D9,X
    beq select_or_release_controller_actor_c0be2c
    .i8
    cpx #$00
    beq select_or_release_controller_actor_c0be10
    .i8
    cpx #$01
    beq select_or_release_controller_actor_c0be06
    lda $D9
    bne select_or_release_controller_actor_c0be18
    lda $DA
    bne select_or_release_controller_actor_c0be18
    beq routine_c0bdc9
select_or_release_controller_actor_c0be06:
    lda $D9
    bne select_or_release_controller_actor_c0be18
    lda $DB
    bne select_or_release_controller_actor_c0be18
    beq routine_c0bdc9
select_or_release_controller_actor_c0be10:
    lda $DA
    bne select_or_release_controller_actor_c0be18
    lda $DB
    beq routine_c0bdc9
select_or_release_controller_actor_c0be18:
    stz $D9,X
    tya
    .i8
    ldy #$00
    lsr
    bcs select_or_release_controller_actor_c0be29
    lsr
    bcs select_or_release_controller_actor_c0be26
    brl release_third_party_controller
select_or_release_controller_actor_c0be26:
    brl release_second_party_controller
select_or_release_controller_actor_c0be29:
    brl release_first_party_controller
select_or_release_controller_actor_c0be2c:
    txa
    inc
    .a8
    cmp #$03
    bne select_or_release_controller_actor_c0be34
    .a8
    lda #$04
select_or_release_controller_actor_c0be34:
    sta $00
    phb
    .a8
    lda #$7E
    pha
    plb
    .a8
    lda #$00
    jsl f:routine_02b59d
    bcc select_or_release_controller_actor_c0be75
    .a8
    lda #$02
    jsl f:routine_02b59d
    bcc select_or_release_controller_actor_c0be71
    .a8
    lda #$04
    jsl f:routine_02b59d
    bcc select_or_release_controller_actor_c0be6d
    .a8
    lda #$00
    jsl f:routine_02b5c9
    bcc select_or_release_controller_actor_c0be75
    .a8
    lda #$02
    jsl f:routine_02b5c9
    bcc select_or_release_controller_actor_c0be71
    .a8
    lda #$04
    jsl f:routine_02b5c9
    bcc select_or_release_controller_actor_c0be6d
    plb
    rts
select_or_release_controller_actor_c0be6d:
    .a8
    lda #$04
    bra select_or_release_controller_actor_c0be77
select_or_release_controller_actor_c0be71:
    .a8
    lda #$02
    bra select_or_release_controller_actor_c0be77
select_or_release_controller_actor_c0be75:
    .a8
    lda #$01
select_or_release_controller_actor_c0be77:
    sta $D9,X
    .a8
    cmp #$01
    bne select_or_release_controller_actor_c0be7f
    .a8
    lda #$00
select_or_release_controller_actor_c0be7f:
    stz $CC,X
    xba
    phx
    .a8
    lda #$00
    rep #$10
    tax
    lda a:$E191,X
    .a8
    and #$41
    bne select_or_release_controller_actor_c0bea0
    lda a:$E190,X
    .a8
    and #$60
    bne select_or_release_controller_actor_c0bea0
    lda $00
    sta a:$E02C,X
    stz a:$E013,X
    bra select_or_release_controller_actor_c0bea5
select_or_release_controller_actor_c0bea0:
    lda $00
    sta a:$E08C,X
select_or_release_controller_actor_c0bea5:
    sep #$10
    plx
    plb
    rts
