.setcpu "65816"
.segment "CODE"
.org $14B0
map_control_0e14b0:
    .byte $E9 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
