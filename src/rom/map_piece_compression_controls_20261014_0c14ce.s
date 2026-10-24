.setcpu "65816"
.segment "CODE"
.org $14CE
map_control_0c14ce:
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
