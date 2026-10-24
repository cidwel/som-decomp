.setcpu "65816"
.segment "CODE"
.org $0E3A
map_control_0c0e3a:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $CD ; row-distance/count
