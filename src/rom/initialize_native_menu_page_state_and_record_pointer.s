; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-controller.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $28A6
initialize_native_menu_page_state_and_record_pointer:
    .a8
    lda #$01
    sta f:$004200
    .a8
    lda #$80
    sta f:$002100
    stz a:$A200
    .a8
    lda #$FF
    sta a:$A210
    .a8
    lda #$80
    sta a:$A20A
    rep #$20
    lda a:$A202
    .a16
    and #$00FF
    asl
    sta a:$A173
    asl
    clc
    adc a:$A173
    .a16
    adc #$780A
    sta a:$A20D
    sep #$20
    rts
