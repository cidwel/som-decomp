.setcpu "65816"
.segment "CODE"
.org $4B55
map_control_0e4b55:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
