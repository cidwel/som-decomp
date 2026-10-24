.setcpu "65816"
.segment "CODE"
.org $18B1
map_control_0e18b1:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $61 ; row-distance/count
