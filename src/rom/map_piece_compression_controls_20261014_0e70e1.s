.setcpu "65816"
.segment "CODE"
.org $70E1
map_control_0e70e1:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
