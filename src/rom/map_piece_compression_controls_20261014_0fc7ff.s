.setcpu "65816"
.segment "CODE"
.org $C7FF
map_control_0fc7ff:
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
