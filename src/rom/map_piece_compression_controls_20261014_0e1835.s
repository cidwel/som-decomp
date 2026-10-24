.setcpu "65816"
.segment "CODE"
.org $1835
map_control_0e1835:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
