.setcpu "65816"
.segment "CODE"
.org $1A6D
map_control_0c1a6d:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
