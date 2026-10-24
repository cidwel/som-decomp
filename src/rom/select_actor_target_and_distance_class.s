; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-action-target-selection.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $E4CC
select_actor_target_and_distance_class:
    bcc select_actor_target_and_distance_class_c1e51b
    lda a:$E1AC,X
    rep #$20
    xba
    .a16
    and #$0F00
    asl
    tay
    .i16
    cpx #$0600
    bcs select_actor_target_and_distance_class_c1e4f7
    .i16
    cpx #$0000
    bne select_actor_target_and_distance_class_c1e4e8
    lda a:$E050,Y
    bra select_actor_target_and_distance_class_c1e50e
select_actor_target_and_distance_class_c1e4e8:
    .i16
    cpx #$0200
    bne select_actor_target_and_distance_class_c1e4f2
    lda a:$E053,Y
    bra select_actor_target_and_distance_class_c1e50e
select_actor_target_and_distance_class_c1e4f2:
    lda a:$E056,Y
    bra select_actor_target_and_distance_class_c1e50e
select_actor_target_and_distance_class_c1e4f7:
    .i16
    cpy #$0000
    bne select_actor_target_and_distance_class_c1e501
    lda a:$E050,X
    bra select_actor_target_and_distance_class_c1e50e
select_actor_target_and_distance_class_c1e501:
    .i16
    cpy #$0200
    bne select_actor_target_and_distance_class_c1e50b
    lda a:$E053,X
    bra select_actor_target_and_distance_class_c1e50e
select_actor_target_and_distance_class_c1e50b:
    lda a:$E056,X
select_actor_target_and_distance_class_c1e50e:
    sep #$20
    sta $00
    xba
    cmp $00
    bcs select_actor_target_and_distance_class_c1e518
    xba
select_actor_target_and_distance_class_c1e518:
    brl select_actor_target_and_distance_class_c1e612
select_actor_target_and_distance_class_c1e51b:
    .i16
    cpx #$0600
    bcc select_actor_target_and_distance_class_c1e523
    brl select_actor_target_and_distance_class_c1e5a5
select_actor_target_and_distance_class_c1e523:
    .i16
    ldy #$0050
    .i16
    cpx #$0000
    beq select_actor_target_and_distance_class_c1e536
    .i16
    ldy #$0053
    .i16
    cpx #$0200
    beq select_actor_target_and_distance_class_c1e536
    .i16
    ldy #$0056
select_actor_target_and_distance_class_c1e536:
    .a8
    lda #$FD
    sta $00
    lda a:$E600
    beq select_actor_target_and_distance_class_c1e54e
    bmi select_actor_target_and_distance_class_c1e54e
    lda a:$E600,Y
    cmp a:$E601,Y
    bcs select_actor_target_and_distance_class_c1e54c
    lda a:$E601,Y
select_actor_target_and_distance_class_c1e54c:
    sta $00
select_actor_target_and_distance_class_c1e54e:
    .a8
    lda #$FE
    sta $01
    bit $5C
    bmi select_actor_target_and_distance_class_c1e56a
    lda a:$E800
    beq select_actor_target_and_distance_class_c1e56a
    bmi select_actor_target_and_distance_class_c1e56a
    lda a:$E800,Y
    cmp a:$E801,Y
    bcs select_actor_target_and_distance_class_c1e568
    lda a:$E801,Y
select_actor_target_and_distance_class_c1e568:
    sta $01
select_actor_target_and_distance_class_c1e56a:
    .a8
    lda #$FF
    sta $02
    bit $5C
    bmi select_actor_target_and_distance_class_c1e586
    lda a:$EA00
    beq select_actor_target_and_distance_class_c1e586
    bmi select_actor_target_and_distance_class_c1e586
    lda a:$EA00,Y
    cmp a:$EA01,Y
    bcs select_actor_target_and_distance_class_c1e584
    lda a:$EA01,Y
select_actor_target_and_distance_class_c1e584:
    sta $02
select_actor_target_and_distance_class_c1e586:
    lda $00
    cmp $01
    bcc select_actor_target_and_distance_class_c1e597
    lda $01
    cmp $02
    bcs select_actor_target_and_distance_class_c1e59b
    .i16
    ldy #$0800
    bra select_actor_target_and_distance_class_c1e612
select_actor_target_and_distance_class_c1e597:
    cmp $02
    bcc select_actor_target_and_distance_class_c1e5a0
select_actor_target_and_distance_class_c1e59b:
    .i16
    ldy #$0A00
    bra select_actor_target_and_distance_class_c1e612
select_actor_target_and_distance_class_c1e5a0:
    .i16
    ldy #$0600
    bra select_actor_target_and_distance_class_c1e612
select_actor_target_and_distance_class_c1e5a5:
    .a8
    lda #$FD
    sta $00
    lda a:$E000
    beq select_actor_target_and_distance_class_c1e5bd
    bmi select_actor_target_and_distance_class_c1e5bd
    lda a:$E050,X
    cmp a:$E051,X
    bcs select_actor_target_and_distance_class_c1e5bb
    lda a:$E051,X
select_actor_target_and_distance_class_c1e5bb:
    sta $00
select_actor_target_and_distance_class_c1e5bd:
    .a8
    lda #$FE
    sta $01
    bit $5C
    bmi select_actor_target_and_distance_class_c1e5d9
    lda a:$E200
    beq select_actor_target_and_distance_class_c1e5d9
    bmi select_actor_target_and_distance_class_c1e5d9
    lda a:$E253,X
    cmp a:$E254,X
    bcs select_actor_target_and_distance_class_c1e5d7
    lda a:$E254,X
select_actor_target_and_distance_class_c1e5d7:
    sta $01
select_actor_target_and_distance_class_c1e5d9:
    .a8
    lda #$FF
    sta $02
    bit $5C
    bmi select_actor_target_and_distance_class_c1e5f5
    lda a:$E400
    beq select_actor_target_and_distance_class_c1e5f5
    bmi select_actor_target_and_distance_class_c1e5f5
    lda a:$E456,X
    cmp a:$E457,X
    bcs select_actor_target_and_distance_class_c1e5f3
    lda a:$E457,X
select_actor_target_and_distance_class_c1e5f3:
    sta $02
select_actor_target_and_distance_class_c1e5f5:
    lda $00
    cmp $01
    bcc select_actor_target_and_distance_class_c1e606
    lda $01
    cmp $02
    bcs select_actor_target_and_distance_class_c1e60a
    .i16
    ldy #$0200
    bra select_actor_target_and_distance_class_c1e612
select_actor_target_and_distance_class_c1e606:
    cmp $02
    bcc select_actor_target_and_distance_class_c1e60f
select_actor_target_and_distance_class_c1e60a:
    .i16
    ldy #$0400
    bra select_actor_target_and_distance_class_c1e612
select_actor_target_and_distance_class_c1e60f:
    .i16
    ldy #$0000
select_actor_target_and_distance_class_c1e612:
    lsr
    lsr
    lsr
    lsr
    .a8
    cmp #$04
    bcc select_actor_target_and_distance_class_c1e61c
    .a8
    lda #$03
select_actor_target_and_distance_class_c1e61c:
    rts
