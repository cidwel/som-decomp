.setcpu "65816"
.segment "CODE"
.org $426F
map_control_0e426f:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
