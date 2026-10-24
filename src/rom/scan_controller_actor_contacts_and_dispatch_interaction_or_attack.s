; Recovered Secret of Mana USA routine; behaviour documented in docs/hero-controller-schedule.md.
.setcpu "65816"
.smart
.a8
.i16

refresh_party_status_cancelled_weapon_graphics_with_saved_bank = $B31F
routine_01e76d = $1E76D
select_controller_actor_and_begin_attack_variant = $B29F

.segment "CODE"
.org $B851
scan_controller_actor_contacts_and_dispatch_interaction_or_attack:
    rep #$10
    sta $12
    .i16
    ldx #$0000
    lsr
    bcs scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b864
    .i16
    ldx #$0200
    lsr
    bcs scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b864
    .i16
    ldx #$0400
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b864:
    phx
    jsr refresh_party_status_cancelled_weapon_graphics_with_saved_bank
    sep #$20
    plx
    stx $10
    .i16
    ldy #$1600
    bit $ED
    bpl scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b87e
    .i16
    ldy #$0A00
    bit $5C
    bpl scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b87e
    .i16
    ldy #$0800
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b87e:
    phb
    .a8
    lda #$7E
    pha
    plb
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b883:
    sep #$20
    lda a:$E000,Y
    bne scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b88d
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b88a:
    brl scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b959
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b88d:
    bmi scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b88a
    lda a:$E01C,Y
    ora a:$E060,Y
    bne scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b88a
    lda a:$E03D,Y
    bpl scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b88a
    lda a:$E03F,Y
    sta $01
    .a8
    and #$70
    .a8
    cmp #$40
    bne scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b8ab
    .a8
    lda #$08
    bra scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b8b5
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b8ab:
    .a8
    cmp #$50
    beq scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b8b3
    .a8
    cmp #$60
    bne scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b88a
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b8b3:
    .a8
    lda #$1C
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b8b5:
    sta $02
    sta $03
    lda a:$E010,X
    .a8
    cmp #$02
    bcs scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b8c6
    .a8
    lda #$01
    sta $02
    bra scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b8ca
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b8c6:
    .a8
    lda #$03
    sta $03
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b8ca:
    .i16
    cpx #$0000
    beq scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b8ec
    .i16
    cpx #$0200
    beq scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b8e0
    lda a:$E058,Y
    sta $00
    rep #$20
    lda a:$E056,Y
    bra scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b8f6
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b8e0:
    lda a:$E055,Y
    sta $00
    rep #$20
    lda a:$E053,Y
    bra scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b8f6
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b8ec:
    lda a:$E052,Y
    sta $00
    rep #$20
    lda a:$E050,Y
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b8f6:
    sep #$20
    cmp $02
    bcs scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b959
    xba
    cmp $03
    bcs scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b959
    lda a:$E00B,X
    eor a:$E00B,Y
    bmi scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b959
    .a8
    and #$03
    .a8
    cmp #$03
    beq scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b959
    lda a:$E045,X
    clc
    adc a:$E045,Y
    .a8
    cmp #$04
    bcs scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b959
    lda $01
    .a8
    and #$70
    .a8
    cmp #$60
    bcc scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b936
    lda a:$E010,X
    .a8
    cmp #$02
    bcc scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b92d
    .a8
    eor #$80
    bra scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b92f
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b92d:
    .a8
    eor #$01
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b92f:
    cmp a:$E010,Y
    bne scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b959
    bra scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b995
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b936:
    lda a:$E010,X
    beq scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b94f
    .a8
    cmp #$01
    beq scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b955
    .a8
    cmp #$02
    beq scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b949
    bit $00
    bvs scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b959
    bvc scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b976
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b949:
    bit $00
    bvc scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b959
    bvs scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b976
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b94f:
    bit $00
    bmi scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b959
    bpl scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b976
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b955:
    bit $00
    bmi scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b976
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b959:
    rep #$20
    tya
    sec
    .a16
    sbc #$0200
    tay
    .a16
    cmp #$0600
    bcc scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b969
    brl scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b883
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b969:
    plb
    sep #$20
    bit $ED
    bmi scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b971
    rts
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b971:
    lda $12
    brl select_controller_actor_and_begin_attack_variant
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b976:
    lda $D0
    bne scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b969
    .a8
    lda #$00
    sta a:$E00A,Y
    sta a:$E01C,Y
    sta a:$E011,Y
    lda a:$E010,X
    .a8
    cmp #$02
    bcc scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b990
    .a8
    eor #$80
    bra scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b992
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b990:
    .a8
    eor #$01
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b992:
    sta a:$E010,Y
scan_controller_actor_contacts_and_dispatch_interaction_or_attack_c0b995:
    rep #$20
    sty $3A
    stx $D4
    .a16
    lda #$0000
    sta a:$E006,X
    sta a:$E008,X
    sta a:$E006,Y
    sta a:$E008,Y
    lda a:$E03E,Y
    .a16
    and #$0FFF
    jsl f:routine_01e76d
    plb
    rts
