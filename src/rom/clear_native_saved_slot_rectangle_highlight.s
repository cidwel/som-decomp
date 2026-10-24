; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-graphics.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c757e1 = $57E1

.segment "CODE"
.org $57D5
clear_native_saved_slot_rectangle_highlight:
    .a8
    lda #$00
    sta a:$A1CB
    bra routine_c757e1
