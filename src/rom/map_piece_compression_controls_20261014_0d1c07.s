.setcpu "65816"
.segment "CODE"
.org $1C07
map_control_0d1c07:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
