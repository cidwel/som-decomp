; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

claim_controller_routes = $A351
release_eight_byte_record = $B1DD
set_controller_pressed_masks = $A3FC

.segment "CODE"
.org $D0AE
handle_input_task_completion:
    phd
    php
    rep #$30
    sep #$20
    jsr release_eight_byte_record
    .a8
    lda #$05
    jsr claim_controller_routes
    .a8
    lda #$05
    .i16
    ldx #$F0F0
    jsr set_controller_pressed_masks
    .a8
    lda #$01
    sta a:$0316
    plp
    pld
    rts
