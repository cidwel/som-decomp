.setcpu "65816"
.segment "CODE"
.org $7D57
map_control_0c7d57:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
