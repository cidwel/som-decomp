.setcpu "65816"
.segment "CODE"
.org $DF2D
map_control_0edf2d:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
