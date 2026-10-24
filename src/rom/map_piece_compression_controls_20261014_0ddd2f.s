.setcpu "65816"
.segment "CODE"
.org $DD2F
map_control_0ddd2f:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
