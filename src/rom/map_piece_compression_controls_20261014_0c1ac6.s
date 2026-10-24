.setcpu "65816"
.segment "CODE"
.org $1AC6
map_control_0c1ac6:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
