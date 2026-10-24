.setcpu "65816"
.segment "CODE"
.org $0263
map_control_0e0263:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
