.setcpu "65816"
.segment "CODE"
.org $1606
map_control_0c1606:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $71 ; row-distance/count
