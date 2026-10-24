.setcpu "65816"
.segment "CODE"
.org $8DA4
map_control_0d8da4:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
