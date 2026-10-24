.setcpu "65816"
.segment "CODE"
.org $A427
map_control_0ea427:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
