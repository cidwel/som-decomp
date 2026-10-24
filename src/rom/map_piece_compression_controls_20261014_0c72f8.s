.setcpu "65816"
.segment "CODE"
.org $72F8
map_control_0c72f8:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E7 ; previous-row copy count
