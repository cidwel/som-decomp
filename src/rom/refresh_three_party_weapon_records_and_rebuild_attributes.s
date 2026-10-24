; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-party-weapon-refresh.md.
.setcpu "65816"
.smart
.a8
.i16

rebuild_actor_attributes_native = $C04530

.segment "CODE"
.org $4CB8
refresh_three_party_weapon_records_and_rebuild_attributes:
    phd
    phb
    php
    rep #$30
    .a16
    lda #$0300
    tcd
    sep #$20
    .a8
    lda #$7E
    pha
    plb
    .i16
    ldy #$0000
    sty $CC
    stz $D1
    .a8
    lda #$03
    sta $B0
refresh_three_party_weapon_records_and_rebuild_attributes_c04cd2:
    .a8
    lda #$07
    sta $D0
    lda a:$E1E4,Y
    sta $AC
refresh_three_party_weapon_records_and_rebuild_attributes_c04cdb:
    ldx $D0
    lda a:$CC54,X
    .a8
    cmp #$FF
    beq refresh_three_party_weapon_records_and_rebuild_attributes_c04d21
    .a8
    and #$3F
    beq refresh_three_party_weapon_records_and_rebuild_attributes_c04d21
    sta $A4
    lda $D0
    sta f:$004202
    .a8
    lda #$09
    sta f:$004203
    nop
    nop
    nop
    nop
    lda f:$004216
    clc
    adc $A4
    sta $A8
    sta f:$004202
    .a8
    lda #$0C
    sta f:$004203
    nop
    nop
    nop
    rep #$20
    lda f:$004216
    tax
    sep #$20
    lda f:$D01000,X
    cmp $AC
    beq refresh_three_party_weapon_records_and_rebuild_attributes_c04d27
refresh_three_party_weapon_records_and_rebuild_attributes_c04d21:
    dec $D0
    bpl refresh_three_party_weapon_records_and_rebuild_attributes_c04cdb
    bra refresh_three_party_weapon_records_and_rebuild_attributes_c04d4c
refresh_three_party_weapon_records_and_rebuild_attributes_c04d27:
    ldx $D0
    lda $A8
    sta a:$E1E8,Y
    sta $A6
    lda a:$E1FA,Y
    .a8
    ora #$04
    sta a:$E1FA,Y
    rep #$20
    lda a:$E190,Y
    .a16
    bit #$C760
    sep #$20
    bne refresh_three_party_weapon_records_and_rebuild_attributes_c04d4c
    lda $A6
    sta a:$E1E3,Y
    sta a:$E1E8,Y
refresh_three_party_weapon_records_and_rebuild_attributes_c04d4c:
    inc $CD
    inc $CD
    ldy $CC
    dec $B0
    beq refresh_three_party_weapon_records_and_rebuild_attributes_c04d59
    jmp refresh_three_party_weapon_records_and_rebuild_attributes_c04cd2
refresh_three_party_weapon_records_and_rebuild_attributes_c04d59:
    .i16
    ldx #$0000
    jsl f:rebuild_actor_attributes_native
    .i16
    ldx #$0200
    jsl f:rebuild_actor_attributes_native
    .i16
    ldx #$0400
    jsl f:rebuild_actor_attributes_native
    plp
    plb
    pld
    rtl
