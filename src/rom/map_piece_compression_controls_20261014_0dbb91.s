.setcpu "65816"
.segment "CODE"
.org $BB91
map_control_0dbb91:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
