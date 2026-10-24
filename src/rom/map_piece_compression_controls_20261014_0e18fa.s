.setcpu "65816"
.segment "CODE"
.org $18FA
map_control_0e18fa:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
