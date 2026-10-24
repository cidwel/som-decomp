.setcpu "65816"
.segment "CODE"
.org $9CD3
map_control_0e9cd3:
    .byte $EF ; backreference distance high bits
    .byte $1B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
