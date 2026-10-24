.setcpu "65816"
.segment "CODE"
.org $1AC1
map_control_0c1ac1:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
