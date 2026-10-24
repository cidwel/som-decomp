; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-vblank.md.
.setcpu "65816"
.smart
.a8
.i16

routine_008000 = $8000

.segment "CODE"
.org $6961
poll_native_menu_controller_and_publish_input_word:
    rep #$30
    jsl f:routine_008000
    lda a:$1836
    .a16
    and #$00FF
    asl
    tax
    lda f:$000042,X
    sta a:$1800
    rts
