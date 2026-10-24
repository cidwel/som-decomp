.setcpu "65816"
.segment "CODE"
.org $3BCD
map_control_0f3bcd:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
