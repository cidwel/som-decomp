.setcpu "65816"
.segment "CODE"
.org $1044
map_control_0e1044:
    .byte $F1 ; progressive-copy count
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $0A ; distance low bit/count
