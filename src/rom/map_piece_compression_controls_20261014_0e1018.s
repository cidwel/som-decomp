.setcpu "65816"
.segment "CODE"
.org $1018
map_control_0e1018:
    .byte $ED ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
