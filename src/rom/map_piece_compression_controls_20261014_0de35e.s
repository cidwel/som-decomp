.setcpu "65816"
.segment "CODE"
.org $E35E
map_control_0de35e:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
