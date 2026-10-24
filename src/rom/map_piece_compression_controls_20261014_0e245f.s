.setcpu "65816"
.segment "CODE"
.org $245F
map_control_0e245f:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
