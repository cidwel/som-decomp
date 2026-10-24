; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-animation-operands.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D52A
read_actor_animation_packed_motion_or_effect:
    pha
    rep #$20
    .i16
    ldy #$0001
    lda [$00],Y
    sta $0C
    lda $00
    inc
    inc
    inc
    sta $00
    sep #$20
    pla
    .a8
    cmp #$F0
    bne read_actor_animation_packed_motion_or_effect_c1d588
    lda $0D
    .a8
    and #$0F
    .a8
    cmp #$08
    bcc read_actor_animation_packed_motion_or_effect_c1d54d
    .a8
    eor #$F7
    inc
read_actor_animation_packed_motion_or_effect_c1d54d:
    sta a:$E008,X
    lda a:$E010,X
    .a8
    and #$80
    sta $0F
    lda $0C
    .a8
    and #$0F
    .a8
    cmp #$08
    bcc read_actor_animation_packed_motion_or_effect_c1d564
    .a8
    eor #$87
    inc
    .a8
    and #$87
read_actor_animation_packed_motion_or_effect_c1d564:
    eor $0F
    .a8
    cmp #$80
    bne read_actor_animation_packed_motion_or_effect_c1d56c
    .a8
    lda #$00
read_actor_animation_packed_motion_or_effect_c1d56c:
    sta a:$E006,X
    lda $0C
    lsr
    lsr
    lsr
    lsr
    .a8
    cmp #$08
    bcc read_actor_animation_packed_motion_or_effect_c1d57e
    .a8
    eor #$87
    inc
    .a8
    and #$87
read_actor_animation_packed_motion_or_effect_c1d57e:
    .a8
    cmp #$80
    bne read_actor_animation_packed_motion_or_effect_c1d584
    .a8
    lda #$00
read_actor_animation_packed_motion_or_effect_c1d584:
    sta a:$E007,X
    rtl
read_actor_animation_packed_motion_or_effect_c1d588:
    .a8
    cmp #$F1
    bne read_actor_animation_packed_motion_or_effect_c1d59b
    inc a:$E05D,X
    rep #$20
    lda $00
    sta a:$E05E,X
    lda $0C
    sta $00
    rtl
read_actor_animation_packed_motion_or_effect_c1d59b:
    lda $22
    .a8
    and #$F8
    sta f:$00212D
    lda $0D
    .a8
    and #$80
    .a8
    ora #$23
    sta f:$002131
    lda $0C
    sta f:$002132
    lda $0D
    .a8
    and #$7F
    inc
    sta a:$105A
    .a8
    lda #$10
    tsb $E2
    rtl
