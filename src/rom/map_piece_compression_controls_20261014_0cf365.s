.setcpu "65816"
.segment "CODE"
.org $F365
map_control_0cf365:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
