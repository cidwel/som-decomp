.setcpu "65816"
.segment "CODE"
.org $A1D7
map_control_0ea1d7:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $4E ; distance low bit/count
