.setcpu "65816"
.segment "CODE"
.org $2B9C
map_control_0e2b9c:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E7 ; previous-row copy count
