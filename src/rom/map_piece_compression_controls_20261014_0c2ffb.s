.setcpu "65816"
.segment "CODE"
.org $2FFB
map_control_0c2ffb:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
