.setcpu "65816"
.segment "CODE"
.org $C40F
map_control_0ec40f:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E2 ; previous-row copy count
