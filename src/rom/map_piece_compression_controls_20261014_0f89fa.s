.setcpu "65816"
.segment "CODE"
.org $89FA
map_control_0f89fa:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
