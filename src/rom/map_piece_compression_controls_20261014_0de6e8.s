.setcpu "65816"
.segment "CODE"
.org $E6E8
map_control_0de6e8:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E2 ; previous-row copy count
