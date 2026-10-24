; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-title-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c01baf = $1BAF

.segment "CODE"
.org $306A
cancel_native_load_selection_and_request_title_page:
    .a8
    lda #$00
    sta a:$A210
    jsr routine_c01baf
    .a8
    lda #$01
    tsb a:$A20A
    rts
