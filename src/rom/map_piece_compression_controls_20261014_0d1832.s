.setcpu "65816"
.segment "CODE"
.org $1832
map_control_0d1832:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
