; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-name-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3244
set_native_name_idle_timer:
    .a8
    lda #$03
    sta a:$A201
    rts
