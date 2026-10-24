.setcpu "65816"
.segment "CODE"
.org $2997
map_control_0f2997:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
