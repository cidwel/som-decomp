.setcpu "65816"
.segment "CODE"
.org $1136
map_control_0d1136:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
