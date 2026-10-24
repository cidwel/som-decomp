.setcpu "65816"
.segment "CODE"
.org $7CF8
map_control_0c7cf8:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
