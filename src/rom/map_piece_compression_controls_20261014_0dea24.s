.setcpu "65816"
.segment "CODE"
.org $EA24
map_control_0dea24:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
