.setcpu "65816"
.segment "CODE"
.org $E089
map_control_0fe089:
    .byte $E9 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
