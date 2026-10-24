.setcpu "65816"
.segment "CODE"
.org $55A7
map_control_0f55a7:
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
    .byte $E2 ; previous-row copy count
