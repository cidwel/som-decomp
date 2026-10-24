.setcpu "65816"
.segment "CODE"
.org $BF2F
map_control_0dbf2f:
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $21 ; distance low bit/count
