.setcpu "65816"
.segment "CODE"
.org $3FD0
map_control_0f3fd0:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
