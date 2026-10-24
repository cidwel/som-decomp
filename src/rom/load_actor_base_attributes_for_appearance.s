; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $474F
load_actor_base_attributes_for_appearance:
    lda a:$E1B1,X
    .a8
    and #$FD
    sta a:$E1B1,X
    lda a:$E191,X
    .a8
    bit #$08
    beq load_actor_base_attributes_for_appearance_c04765
    lda a:$E180,X
    bmi load_actor_base_attributes_for_appearance_c04765
    bra load_actor_base_attributes_for_appearance_c04768
load_actor_base_attributes_for_appearance_c04765:
    lda a:$E1E7,X
load_actor_base_attributes_for_appearance_c04768:
    sta f:$004202
    .a8
    lda #$1D
    sta f:$004203
    nop
    nop
    nop
    rep #$20
    lda f:$004216
    tax
    ldy $BD
    lda f:$D01C04,X
    sta a:$E188,Y
    lda f:$D01C06,X
    sta a:$E18B,Y
    lda f:$D01C08,X
    sta a:$E1A4,Y
    lda f:$D01C0A,X
    sta a:$E1A6,Y
    lda f:$D01C0C,X
    sta a:$E1A8,Y
    lda f:$D01C0E,X
    sta a:$E192,Y
    lda f:$D01C09,X
    sta a:$E1A5,Y
    lda f:$D01C0C,X
    sta a:$E1A8,Y
    lda f:$D01C12,X
    sta a:$E1FD,Y
    lda f:$D01C14,X
    sta a:$E1AA,Y
    lda f:$D01C19,X
    .a16
    and #$0001
    asl
    ora a:$E1B1,Y
    sta a:$E1B1,Y
    lda f:$D01C17,X
    sta a:$E1E8,Y
    tyx
    sep #$20
    rts
