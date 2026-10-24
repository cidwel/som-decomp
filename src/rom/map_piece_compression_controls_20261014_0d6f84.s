.setcpu "65816"
.segment "CODE"
.org $6F84
map_control_0d6f84:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
