.setcpu "65816"
.segment "CODE"
.org $082F
map_control_0d082f:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
