.setcpu "65816"
.segment "CODE"
.org $E81A
map_control_0fe81a:
    .byte $E8 ; backreference distance high bits
    .byte $2C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
