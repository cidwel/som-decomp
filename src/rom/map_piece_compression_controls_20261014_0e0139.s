.setcpu "65816"
.segment "CODE"
.org $0139
map_control_0e0139:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E2 ; previous-row copy count
