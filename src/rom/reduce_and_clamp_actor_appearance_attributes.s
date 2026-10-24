; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4BBE
reduce_and_clamp_actor_appearance_attributes:
    lda a:$E190,X
    .a8
    bit #$08
    beq reduce_and_clamp_actor_appearance_attributes_c04bd7
    lda a:$E189,X
    lsr
    lsr
    lsr
    lsr
    sta $A4
    lda a:$E189,X
    sec
    sbc $A4
    sta a:$E189,X
reduce_and_clamp_actor_appearance_attributes_c04bd7:
    .a8
    lda #$05
    sta $A4
reduce_and_clamp_actor_appearance_attributes_c04bdb:
    .a8
    lda #$63
    cmp a:$E188,X
    bcs reduce_and_clamp_actor_appearance_attributes_c04be5
    sta a:$E188,X
reduce_and_clamp_actor_appearance_attributes_c04be5:
    .a8
    lda #$01
    cmp a:$E188,X
    bcc reduce_and_clamp_actor_appearance_attributes_c04bef
    sta a:$E188,X
reduce_and_clamp_actor_appearance_attributes_c04bef:
    inx
    dec $A4
    bne reduce_and_clamp_actor_appearance_attributes_c04bdb
    ldx $BD
    rts
