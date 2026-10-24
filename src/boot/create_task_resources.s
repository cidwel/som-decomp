; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_bytes = $B0A1
allocate_task_id_and_stack_page = $AA77
allocate_timer_registration = $CB86
copy_far_stack_arguments = $C44E

.segment "CODE"
.org $AAFF
create_task_resources:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$000B
    tcd
    tcs
    lda $0C,S
    sep #$20
    .i16
    ldy #$000A
    phy
    pha
    phx
    .a8
    lda #$00
    pha
    rep #$20
    tdc
    clc
    .a16
    adc #$0004
    pha
    jsr copy_far_stack_arguments
    tsc
    clc
    .a16
    adc #$0008
    tcs
    ldx a:$00A6
    beq create_task_resources_ab7f
    stx $02
    ldy a:$0000,X
    sty a:$00A6
    stz a:$0000,X
    sep #$20
    .a8
    lda #$01
    ldx a:$009E
    beq create_task_resources_ab45
    lda a:$0004,X
create_task_resources_ab45:
    ldx $02
    sta a:$0005,X
    rep #$20
    tdc
    clc
    .a16
    adc #$0004
    tay
    sep #$20
    lda a:$0005,X
    jsr allocate_task_id_and_stack_page
    lda $07
    sta a:$0003,X
    .a8
    lda #$08
    sta a:$0002,X
    lda a:$0004,X
    rep #$20
    jsr allocate_timer_registration
    txa
    ldx $02
    sta a:$000C,X
    ldx $0C
    beq create_task_resources_ab79
    jsr allocate_and_fill_bytes
create_task_resources_ab79:
    txa
    ldx $02
    sta a:$0008,X
create_task_resources_ab7f:
    tsc
    clc
    .a16
    adc #$000D
    tcs
    plp
    pld
    rts
