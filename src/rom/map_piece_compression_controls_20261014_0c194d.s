.setcpu "65816"
.segment "CODE"
.org $194D
map_control_0c194d:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E2 ; previous-row copy count
