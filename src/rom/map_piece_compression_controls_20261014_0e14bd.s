.setcpu "65816"
.segment "CODE"
.org $14BD
map_control_0e14bd:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
