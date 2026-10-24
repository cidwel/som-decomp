.setcpu "65816"
.segment "CODE"
.org $18F7
map_control_0d18f7:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
