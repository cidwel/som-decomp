.setcpu "65816"
.segment "CODE"
.org $70E6
map_control_0e70e6:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
