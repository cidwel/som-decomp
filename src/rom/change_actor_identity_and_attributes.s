; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

clear_actor_identity_attribute_record = $4E31
rebuild_actor_attributes_native = $C04530
refresh_actor_appearance_native = $C0457C

.segment "CODE"
.org $55EC
change_actor_identity_and_attributes:
    phd
    phb
    php
    sep #$20
    pha
    rep #$20
    .a16
    lda #$0300
    tcd
    txa
    .a16
    and #$1FFF
    tay
    sty $83
    sep #$20
    .a8
    lda #$7E
    pha
    plb
    ldx $83
    pla
    sta $B2
    bpl change_actor_identity_and_attributes_c0560f
    jmp change_actor_identity_and_attributes_c05719
change_actor_identity_and_attributes_c0560f:
    sta f:$004202
    .a8
    lda #$1D
    sta f:$004203
    jsr clear_actor_identity_attribute_record
    rep #$20
    ldy $83
    lda f:$004216
    tax
    lda f:$D01C01,X
    sta a:$E182,Y
    sta a:$E184,Y
    lda f:$D01C0E,X
    sta a:$E192,Y
    lda f:$D01C09,X
    sta a:$E1A5,Y
    lda f:$D01C0C,X
    sta a:$E1A8,Y
    lda f:$D01C14,X
    sta a:$E1AA,Y
    lda f:$D01C17,X
    sta a:$E1E8,Y
    lda f:$D01C04,X
    sta a:$E188,Y
    lda f:$D01C06,X
    sta a:$E18B,Y
    lda f:$D01C10,X
    sta a:$E18D,Y
    lda f:$D01C1B,X
    sta a:$E1C8,Y
    sep #$20
    lda $B2
    sta a:$E180,Y
    sta a:$E1E7,Y
    lda f:$D01C00,X
    sta a:$E181,Y
    lda f:$D01C03,X
    sta a:$E186,Y
    sta a:$E187,Y
    lda f:$D01C08,X
    sta a:$E1A4,Y
    lda f:$D01C0B,X
    sta a:$E1A7,Y
    lda f:$D01C19,X
    sta a:$E1CA,Y
    sta $A4
    .a8
    and #$01
    sta a:$E1B1,Y
    lda $A4
    .a8
    and #$80
    lsr
    lsr
    lsr
    lsr
    lsr
    lsr
    ora a:$E1B1,Y
    sta a:$E1B1,Y
    lda $A4
    .a8
    and #$40
    lsr
    lsr
    lsr
    lsr
    ora a:$E1B1,Y
    sta a:$E1B1,Y
    lda f:$D01C1A,X
    .a8
    and #$0F
    sta a:$E1C4,Y
    lda f:$D01C1A,X
    lsr
    lsr
    lsr
    lsr
    sta a:$E1C0,Y
    lda a:$E1E8,Y
    sta a:$E1E3,Y
    ldx $83
    jsl f:refresh_actor_appearance_native
    lda a:$E1E7,X
    sta f:$004202
    .a8
    lda #$05
    sta f:$004203
    nop
    nop
    nop
    rep #$20
    lda f:$004216
    tax
    sep #$20
    ldy $83
    lda f:$D03A50,X
    sta a:$E1CE,Y
    ldx $83
    lda a:$E1FB,X
    .a8
    bit #$01
    bne change_actor_identity_and_attributes_c05712
change_actor_identity_and_attributes_c0570e:
    plp
    plb
    pld
    rtl
change_actor_identity_and_attributes_c05712:
    .a8
    lda #$D2
    sta a:$E033,X
    bra change_actor_identity_and_attributes_c0570e
change_actor_identity_and_attributes_c05719:
    sta a:$E180,Y
    sta a:$E1E7,Y
    rep #$20
    stz a:$E190,X
    stz a:$E1EE,X
    stz a:$E19E,X
    sep #$20
    stz a:$E1E3,X
    stz a:$E1E9,X
    stz a:$E1E8,X
    stz a:$E1FB,X
    .a8
    lda #$07
    sta a:$E1FA,X
    jsl f:rebuild_actor_attributes_native
    plp
    plb
    pld
    rtl
