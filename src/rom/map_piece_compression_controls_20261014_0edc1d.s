.setcpu "65816"
.segment "CODE"
.org $DC1D
map_control_0edc1d:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $41 ; row-distance/count
