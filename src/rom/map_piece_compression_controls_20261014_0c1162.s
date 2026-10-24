.setcpu "65816"
.segment "CODE"
.org $1162
map_control_0c1162:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
