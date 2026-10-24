.setcpu "65816"
.segment "CODE"
.org $CF90
map_control_0fcf90:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
