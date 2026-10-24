.setcpu "65816"
.segment "CODE"
.org $4265
map_control_0e4265:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
