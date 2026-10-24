.setcpu "65816"
.segment "CODE"
.org $8665
map_control_0c8665:
    .byte $E0 ; previous-row copy escape
    .byte $9B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
