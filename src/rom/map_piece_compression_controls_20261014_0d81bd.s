.setcpu "65816"
.segment "CODE"
.org $81BD
map_control_0d81bd:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
