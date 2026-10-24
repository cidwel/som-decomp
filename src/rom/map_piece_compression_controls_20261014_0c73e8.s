.setcpu "65816"
.segment "CODE"
.org $73E8
map_control_0c73e8:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E2 ; previous-row copy count
