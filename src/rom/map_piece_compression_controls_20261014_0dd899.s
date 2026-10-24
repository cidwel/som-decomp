.setcpu "65816"
.segment "CODE"
.org $D899
map_control_0dd899:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $6E ; distance low bit/count
