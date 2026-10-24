.setcpu "65816"
.segment "CODE"
.org $9C7A
map_control_0e9c7a:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
