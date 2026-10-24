.setcpu "65816"
.segment "CODE"
.org $901D
map_control_0c901d:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E1 ; previous-row copy count
