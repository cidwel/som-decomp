; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4860
prepare_actor_appearance_table_pointers:
    .a8
    lda #$D0
    sta $CB
    sta $C8
    sta $C5
    sta $C2
    .a8
    lda #$0A
    sta f:$004202
    lda a:$E1E0,X
    sta f:$004203
    rep #$20
    nop
    nop
    nop
    lda f:$004216
    sta $C9
    sep #$20
    lda a:$E1E1,X
    sta f:$004203
    rep #$20
    nop
    nop
    nop
    lda f:$004216
    sta $C6
    sep #$20
    lda a:$E1E2,X
    sta f:$004203
    rep #$20
    nop
    nop
    nop
    lda f:$004216
    sta $C3
    sep #$20
    lda a:$E1FB,X
    .a8
    bit #$40
    beq prepare_actor_appearance_table_pointers_c048b4
    rts
prepare_actor_appearance_table_pointers_c048b4:
    ldy $BD
    lda a:$E1E4,X
    bpl prepare_actor_appearance_table_pointers_c048bc
    iny
prepare_actor_appearance_table_pointers_c048bc:
    lda a:$E1E8,Y
    sta f:$004202
    .a8
    lda #$0C
    sta f:$004203
    rep #$20
    nop
    nop
    nop
    lda f:$004216
    sta $C0
    sep #$20
    lda a:$E1FB,X
    bpl prepare_actor_appearance_table_pointers_c048e5
    phy
    .i16
    ldy #$1000
    lda [$C0],Y
    ply
    sta a:$E1E4,X
prepare_actor_appearance_table_pointers_c048e5:
    rts
