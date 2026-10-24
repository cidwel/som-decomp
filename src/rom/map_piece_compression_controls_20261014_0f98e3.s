.setcpu "65816"
.segment "CODE"
.org $98E3
map_control_0f98e3:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
