.setcpu "65816"
.segment "CODE"
.org $9F39
map_control_0e9f39:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
