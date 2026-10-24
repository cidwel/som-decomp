.setcpu "65816"
.segment "CODE"
.org $7C07
map_control_0e7c07:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
