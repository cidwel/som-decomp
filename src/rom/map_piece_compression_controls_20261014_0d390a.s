.setcpu "65816"
.segment "CODE"
.org $390A
map_control_0d390a:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
