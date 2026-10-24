.setcpu "65816"
.segment "CODE"
.org $670F
map_control_0d670f:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
