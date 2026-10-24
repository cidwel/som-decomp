.setcpu "65816"
.segment "CODE"
.org $878F
map_control_0d878f:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
