.setcpu "65816"
.segment "CODE"
.org $9C5D
map_control_0e9c5d:
    .byte $EC ; backreference distance high bits
    .byte $91 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
