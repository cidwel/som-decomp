.setcpu "65816"
.segment "CODE"
.org $8360
map_control_0d8360:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $25 ; distance low bit/count
