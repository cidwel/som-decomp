.setcpu "65816"
.segment "CODE"
.org $7625
map_control_0d7625:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
