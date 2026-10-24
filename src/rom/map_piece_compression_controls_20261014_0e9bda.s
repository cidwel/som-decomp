.setcpu "65816"
.segment "CODE"
.org $9BDA
map_control_0e9bda:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
