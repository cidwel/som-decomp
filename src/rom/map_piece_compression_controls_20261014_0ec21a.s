.setcpu "65816"
.segment "CODE"
.org $C21A
map_control_0ec21a:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
