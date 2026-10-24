.setcpu "65816"
.segment "CODE"
.org $15E2
map_control_0d15e2:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $9E ; row-distance/count
