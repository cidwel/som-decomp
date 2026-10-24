.setcpu "65816"
.segment "CODE"
.org $E08E
map_control_0fe08e:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
