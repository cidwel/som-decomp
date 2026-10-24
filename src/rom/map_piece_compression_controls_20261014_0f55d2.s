.setcpu "65816"
.segment "CODE"
.org $55D2
map_control_0f55d2:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
    .byte $E2 ; previous-row copy count
