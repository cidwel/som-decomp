; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

create_and_enqueue_task = $AB88
release_controller_routes = $A3A5

.segment "CODE"
.org $D14C
ensure_parent_control_task:
    phd
    php
    rep #$30
    sep #$20
    lda a:$0314
    bne ensure_parent_control_task_d17c
    lda a:$0316
    beq ensure_parent_control_task_d16c
    .a8
    lda #$80
    sta f:$001E00
    .a8
    lda #$20
    sta f:$001E01
    jsl f:$C30004
ensure_parent_control_task_d16c:
    .a8
    lda #$7E
    .i16
    ldx #$6492
    jsr create_and_enqueue_task
    sta a:$0314
    .a8
    lda #$05
    jsr release_controller_routes
ensure_parent_control_task_d17c:
    plp
    pld
    rts
