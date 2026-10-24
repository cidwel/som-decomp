.setcpu "65816"
.segment "CODE"
.org $15F5
map_control_0d15f5:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
