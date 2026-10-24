.setcpu "65816"
.segment "CODE"
.org $0E72
map_control_0f0e72:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
    .byte $E1 ; previous-row copy count
