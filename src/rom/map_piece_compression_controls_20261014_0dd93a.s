.setcpu "65816"
.segment "CODE"
.org $D93A
map_control_0dd93a:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $6E ; row-distance/count
