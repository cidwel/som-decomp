.setcpu "65816"
.segment "CODE"
.org $2FD2
map_control_0e2fd2:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
