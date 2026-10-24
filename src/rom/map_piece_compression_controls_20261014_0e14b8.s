.setcpu "65816"
.segment "CODE"
.org $14B8
map_control_0e14b8:
    .byte $E9 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
