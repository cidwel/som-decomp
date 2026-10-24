.setcpu "65816"
.segment "CODE"
.org $7FC7
map_control_0d7fc7:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7A ; distance low bit/count
