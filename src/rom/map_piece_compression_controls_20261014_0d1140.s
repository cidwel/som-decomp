.setcpu "65816"
.segment "CODE"
.org $1140
map_control_0d1140:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
