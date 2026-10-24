.setcpu "65816"
.segment "CODE"
.org $1AAF
map_control_0d1aaf:
    .byte $E8 ; backreference distance high bits
    .byte $9B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
