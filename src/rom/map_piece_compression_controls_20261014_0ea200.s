.setcpu "65816"
.segment "CODE"
.org $A200
map_control_0ea200:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
