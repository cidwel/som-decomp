.setcpu "65816"
.segment "CODE"
.org $603F
map_control_0d603f:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
