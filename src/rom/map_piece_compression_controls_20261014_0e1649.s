.setcpu "65816"
.segment "CODE"
.org $1649
map_control_0e1649:
    .byte $EF ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E1 ; previous-row copy count
