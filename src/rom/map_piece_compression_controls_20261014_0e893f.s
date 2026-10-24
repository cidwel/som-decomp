.setcpu "65816"
.segment "CODE"
.org $893F
map_control_0e893f:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
