.setcpu "65816"
.segment "CODE"
.org $1916
map_control_0e1916:
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $A3 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $6B ; row-distance/count
