.setcpu "65816"
.segment "CODE"
.org $2BF6
map_control_0e2bf6:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E6 ; previous-row copy count
