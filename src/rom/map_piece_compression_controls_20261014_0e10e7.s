.setcpu "65816"
.segment "CODE"
.org $10E7
map_control_0e10e7:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
