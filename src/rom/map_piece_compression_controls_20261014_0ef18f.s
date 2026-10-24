.setcpu "65816"
.segment "CODE"
.org $F18F
map_control_0ef18f:
    .byte $E8 ; backreference distance high bits
    .byte $2A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7C ; row-distance/count
