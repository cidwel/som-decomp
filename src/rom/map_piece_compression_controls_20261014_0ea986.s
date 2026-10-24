.setcpu "65816"
.segment "CODE"
.org $A986
map_control_0ea986:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
