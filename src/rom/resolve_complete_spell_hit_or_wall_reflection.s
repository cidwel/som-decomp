; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-spell-reflection.md.
.setcpu "65816"
.smart
.a8
.i16

enqueue_unique_spell_reflection_notice = $C0595F
prepare_and_resolve_complete_spell_hit = $C8E6D4
prepare_cast_actor_context_long = $C0395E
random_byte_long_wrapper = $C0389C

.segment "CODE"
.org $4C82
resolve_complete_spell_hit_or_wall_reflection:
    phd
    phb
    php
    jsl f:prepare_cast_actor_context_long
    lda a:$E1FB,X
    bpl resolve_complete_spell_hit_or_wall_reflection_d04c9b
    lda a:$E191,X
    bpl resolve_complete_spell_hit_or_wall_reflection_d04c9b
    lda a:$E1B1,X
    .a8
    ora #$08
    sta a:$E1B1,X
resolve_complete_spell_hit_or_wall_reflection_d04c9b:
    lda a:$E1B1,X
    .a8
    bit #$40
    bne resolve_complete_spell_hit_or_wall_reflection_d04cb3
resolve_complete_spell_hit_or_wall_reflection_d04ca2:
    ldy $85
    ldx $83
    jsl f:prepare_and_resolve_complete_spell_hit
    .a8
    lda #$00
    .i16
    ldx #$0000
resolve_complete_spell_hit_or_wall_reflection_d04caf:
    plp
    plb
    pld
    rtl
resolve_complete_spell_hit_or_wall_reflection_d04cb3:
    lda a:$E170,Y
    .a8
    cmp #$20
    beq resolve_complete_spell_hit_or_wall_reflection_d04ca2
    .a8
    cmp #$23
    beq resolve_complete_spell_hit_or_wall_reflection_d04ca2
    .a8
    cmp #$26
    beq resolve_complete_spell_hit_or_wall_reflection_d04ca2
    .i16
    ldx #$0003
    lda $81
    inc
resolve_complete_spell_hit_or_wall_reflection_d04cc8:
    cmp a:$E178,Y
    beq resolve_complete_spell_hit_or_wall_reflection_d04cd3
    iny
    dex
    bne resolve_complete_spell_hit_or_wall_reflection_d04cc8
    bra resolve_complete_spell_hit_or_wall_reflection_d04ca2
resolve_complete_spell_hit_or_wall_reflection_d04cd3:
    ldy $85
    ldx $83
    lda a:$E1B8,Y
    dec
    sta a:$E1B8,Y
    bne resolve_complete_spell_hit_or_wall_reflection_d04ce8
    lda a:$E1B1,Y
    .a8
    and #$BF
    sta a:$E1B1,Y
resolve_complete_spell_hit_or_wall_reflection_d04ce8:
    lda a:$E1FB,Y
    bmi resolve_complete_spell_hit_or_wall_reflection_d04cf2
    .i16
    ldx #$0000
    bra resolve_complete_spell_hit_or_wall_reflection_d04cf5
resolve_complete_spell_hit_or_wall_reflection_d04cf2:
    .i16
    ldx #$0600
resolve_complete_spell_hit_or_wall_reflection_d04cf5:
    .a8
    lda #$03
    sta $B2
    jsl f:random_byte_long_wrapper
    rep #$20
    stx $D0
    .a16
    and #$0003
    asl
    asl
    asl
    sta $D4
    lda a:$E002,Y
    sta $AC
    lda a:$E004,Y
    sta $AE
    sep #$20
resolve_complete_spell_hit_or_wall_reflection_d04d15:
    rep #$20
    lda $D4
    tax
    lda f:$D04D7E,X
    clc
    adc $D0
    tax
    sep #$20
    lda a:$E000,X
    .a8
    cmp #$01
    bne resolve_complete_spell_hit_or_wall_reflection_d04d6f
    lda a:$E191,X
    bmi resolve_complete_spell_hit_or_wall_reflection_d04d6f
    lda a:$E1FB,X
    .a8
    bit #$30
    bne resolve_complete_spell_hit_or_wall_reflection_d04d6f
    lda a:$00ED
    bpl resolve_complete_spell_hit_or_wall_reflection_d04d6f
    rep #$20
    lda a:$E002,X
    sec
    sbc $AC
    bpl resolve_complete_spell_hit_or_wall_reflection_d04d4a
    .a16
    eor #$FFFF
    inc
resolve_complete_spell_hit_or_wall_reflection_d04d4a:
    sta $A8
    lda a:$E004,X
    sec
    sbc $AE
    bpl resolve_complete_spell_hit_or_wall_reflection_d04d58
    .a16
    eor #$FFFF
    inc
resolve_complete_spell_hit_or_wall_reflection_d04d58:
    sta $AA
    clc
    adc $A8
    .a16
    cmp #$00F0
    sep #$20
    bcs resolve_complete_spell_hit_or_wall_reflection_d04d6f
    phx
    jsl f:enqueue_unique_spell_reflection_notice
    plx
    .a8
    lda #$FF
    jmp resolve_complete_spell_hit_or_wall_reflection_d04caf
resolve_complete_spell_hit_or_wall_reflection_d04d6f:
    inc $CD
    inc $CD
    inc $D4
    inc $D4
    dec $B2
    bne resolve_complete_spell_hit_or_wall_reflection_d04d15
    jmp resolve_complete_spell_hit_or_wall_reflection_d04ca2
