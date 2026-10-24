.setcpu "65816"
.segment "CODE"
.org $D536
map_control_0dd536:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
