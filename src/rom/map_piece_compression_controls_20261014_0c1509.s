.setcpu "65816"
.segment "CODE"
.org $1509
map_control_0c1509:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
