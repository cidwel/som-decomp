.setcpu "65816"
.segment "CODE"
.org $AAE2
map_control_0daae2:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
